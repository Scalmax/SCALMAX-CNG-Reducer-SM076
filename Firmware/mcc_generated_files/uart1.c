/**
  UART1 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    uart1.c

  @Summary
    This is the generated source file for the UART1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for driver for UART1. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  dsPIC33EV128GM106
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB             :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "xc.h"
#include "uart1.h"

/**
  Section: Data Type Definitions
*/

/** UART Driver Queue Status

  @Summary
    Defines the object required for the status of the queue.
*/

static uint8_t * volatile rxTail;
static uint8_t *rxHead;
static uint8_t *txTail;
static uint8_t * volatile txHead;
static bool volatile rxOverflowed;

/** UART Driver Queue Length

  @Summary
    Defines the length of the Transmit and Receive Buffers

*/

/* We add one extra byte than requested so that we don't have to have a separate
 * bit to determine the difference between buffer full and buffer empty, but
 * still be able to hold the amount of data requested by the user.  Empty is
 * when head == tail.  So full will result in head/tail being off by one due to
 * the extra byte.
 */
#define UART1_CONFIG_TX_BYTEQ_LENGTH (8+1)
#define UART1_CONFIG_RX_BYTEQ_LENGTH (8+1)

/** UART Driver Queue

  @Summary
    Defines the Transmit and Receive Buffers

*/

static uint8_t txQueue[UART1_CONFIG_TX_BYTEQ_LENGTH];
static uint8_t rxQueue[UART1_CONFIG_RX_BYTEQ_LENGTH];

void (*UART1_TxDefaultInterruptHandler)(void);
void (*UART1_RxDefaultInterruptHandler)(void);

/**
  Section: Driver Interface
*/

void UART1_Initialize(void)
{
    IEC0bits.U1TXIE = 0;
    IEC0bits.U1RXIE = 0;

    // STSEL 1; IREN disabled; PDSEL 8E; UARTEN enabled; RTSMD disabled; USIDL disabled; WAKE disabled; ABAUD disabled; LPBACK disabled; BRGH enabled; URXINV disabled; UEN TX_RX; 
    // Data Bits = 8; Parity = Even; Stop Bits = 1;
    U1MODE = (0x800A & ~(0x8000));  // disabling UART ON bit
    // UTXISEL0 TX_ONE_CHAR; UTXINV disabled; OERR NO_ERROR_cleared; URXISEL RX_ONE_CHAR; UTXBRK COMPLETED; UTXEN disabled; ADDEN disabled; 
    U1STA = 0x00;
    // BaudRate = 38400; Frequency = 40000000 Hz; BRG 259; 
    U1BRG = 0x103;
    
    txHead = txQueue;
    txTail = txQueue;
    rxHead = rxQueue;
    rxTail = rxQueue;
   
    rxOverflowed = false;

    UART1_SetTxInterruptHandler(&UART1_Transmit_CallBack);

    UART1_SetRxInterruptHandler(&UART1_Receive_CallBack);

    IEC0bits.U1RXIE = 1;
    
    //Make sure to set LAT bit corresponding to TxPin as high before UART initialization
    U1MODEbits.UARTEN = 1;   // enabling UART ON bit
    U1STAbits.UTXEN = 1;
}

/**
    Maintains the driver's transmitter state machine and implements its ISR
*/

void UART1_SetTxInterruptHandler(void (* interruptHandler)(void))
{
    if(interruptHandler == NULL)
    {
        UART1_TxDefaultInterruptHandler = &UART1_Transmit_CallBack;
    }
    else
    {
        UART1_TxDefaultInterruptHandler = interruptHandler;
    }
} 

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1TXInterrupt ( void )
{
    if(UART1_TxDefaultInterruptHandler != NULL)
    {
        UART1_TxDefaultInterruptHandler();
    }

    if(txHead == txTail)
    {
        IEC0bits.U1TXIE = 0;
    }
    else
    {
        IFS0bits.U1TXIF = 0;

        while(!(U1STAbits.UTXBF == 1))
        {
            U1TXREG = *txHead;
            txHead++;

            if(txHead == (txQueue + UART1_CONFIG_TX_BYTEQ_LENGTH))
            {
                txHead = txQueue;
            }

            // Are we empty?
            if(txHead == txTail)
            {
                break;
            }
        }
    }
}

void __attribute__ ((weak)) UART1_Transmit_CallBack ( void )
{ 

}

void UART1_SetRxInterruptHandler(void (* interruptHandler)(void))
{
    if(interruptHandler == NULL)
    {
        UART1_RxDefaultInterruptHandler = &UART1_Receive_CallBack;
    }
    else
    {
        UART1_RxDefaultInterruptHandler = interruptHandler;
    }
}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt( void )
{
    if(UART1_RxDefaultInterruptHandler != NULL)
    {
        UART1_RxDefaultInterruptHandler();
    }
    
    IFS0bits.U1RXIF = 0;
	
    while((U1STAbits.URXDA == 1))
    {
        *rxTail = U1RXREG;

        // Will the increment not result in a wrap and not result in a pure collision?
        // This is most often condition so check first
        if ( ( rxTail    != (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH-1)) && ((rxTail+1) != rxHead) )
        {
            rxTail++;
        } 
        else if ( (rxTail == (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH-1)) && (rxHead !=  rxQueue) )
        {
            // Pure wrap no collision
            rxTail = rxQueue;
        } 
        else // must be collision
        {
            rxOverflowed = true;
        }
    }
}

void __attribute__ ((weak)) UART1_Receive_CallBack(void)
{

}

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1ErrInterrupt( void )
{
    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }
    
    IFS4bits.U1EIF = 0;
}

/**
  Section: UART Driver Client Routines
*/

uint8_t UART1_Read( void)
{
    uint8_t data = 0;

    while (rxHead == rxTail )
    {
    }
    
    data = *rxHead;

    rxHead++;

    if (rxHead == (rxQueue + UART1_CONFIG_RX_BYTEQ_LENGTH))
    {
        rxHead = rxQueue;
    }
    return data;
}

void UART1_Write( uint8_t byte)
{
    while(UART1_IsTxReady() == 0)
    {
    }

    *txTail = byte;

    txTail++;
    
    if (txTail == (txQueue + UART1_CONFIG_TX_BYTEQ_LENGTH))
    {
        txTail = txQueue;
    }

    IEC0bits.U1TXIE = 1;
}

bool UART1_IsRxReady(void)
{    
    return !(rxHead == rxTail);
}

bool UART1_IsTxReady(void)
{
    uint16_t size;
    uint8_t *snapshot_txHead = (uint8_t*)txHead;
    
    if (txTail < snapshot_txHead)
    {
        size = (snapshot_txHead - txTail - 1);
    }
    else
    {
        size = ( UART1_CONFIG_TX_BYTEQ_LENGTH - (txTail - snapshot_txHead) - 1 );
    }
    
    return (size != NULL);
}

bool UART1_IsTxDone(void)
{
    bool result;
    if(txTail == txHead)
    {
        result = (bool)U1STAbits.TRMT;
    }
    
    return false;
}
