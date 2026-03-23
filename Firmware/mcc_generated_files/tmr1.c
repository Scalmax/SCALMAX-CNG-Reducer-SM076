
/**
  TMR1 Generated Driver API Source File 

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated source file for the TMR1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for driver for TMR1. 
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
#include "tmr1.h"
#include "../exchange.h"
#include "../adc_temp.h"
#include "../pid.h"
#include "../obs_timerow.h"
#include "../TimeTick.h"
#include "../definicje.h"

/**
 Section: File specific functions
*/
void (*TMR1_InterruptHandler)(void) = NULL;
void TMR1_CallBack(void);

/**
  Section: Data Type Definitions
*/

/** TMR Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

  Remarks:
    None.
*/

typedef struct _TMR_OBJ_STRUCT
{
    /* Timer Elapsed */
    volatile bool           timerElapsed;
    /*Software Counter value*/
    volatile uint8_t        count;

} TMR_OBJ;

static TMR_OBJ tmr1_obj;

/**
  Section: Driver Interface
*/

void TMR1_Initialize (void)
{
    //TMR1 0; 
    TMR1 = 0x00;
    //Period = 0.001 s; Frequency = 40000000 Hz; PR1 39999; 
    PR1 = 0x9C3F;
    //TCKPS 1:1; TON enabled; TSIDL disabled; TCS FOSC/2; TSYNC disabled; TGATE disabled; 
    T1CON = 0x8000;

    if(TMR1_InterruptHandler == NULL)
    {
        TMR1_SetInterruptHandler(&TMR1_CallBack);
    }

    IFS0bits.T1IF = false;
    IEC0bits.T1IE = true;
	
    tmr1_obj.timerElapsed = false;

}


void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  )
{
    /* Check if the Timer Interrupt/Status is set */

    //***User Area Begin

    // ticker function call;
    // ticker is 1 -> Callback function gets called everytime this ISR executes
    if(TMR1_InterruptHandler != NULL) 
    { 
           TMR1_InterruptHandler(); 
    }

    //***User Area End

    tmr1_obj.count++;
    tmr1_obj.timerElapsed = true;
    IFS0bits.T1IF = false;
}

void TMR1_Period16BitSet( uint16_t value )
{
    /* Update the counter values */
    PR1 = value;
    /* Reset the status information */
    tmr1_obj.timerElapsed = false;
}

uint16_t TMR1_Period16BitGet( void )
{
    return( PR1 );
}

void TMR1_Counter16BitSet ( uint16_t value )
{
    /* Update the counter values */
    TMR1 = value;
    /* Reset the status information */
    tmr1_obj.timerElapsed = false;
}

uint16_t TMR1_Counter16BitGet( void )
{
    return( TMR1 );
}


void __attribute__ ((weak)) TMR1_CallBack(void)
{
    // obsluga funkcji TimeTick_1ms
    if (Podlicznik_Flag.podlicznik_1ms == true) { // jezeli podlicznik rowna sie 1 ms(0.001s)
        Disable_Interrupt(); // Disable Timer1 interrupt 
        F1TimerRT.TimerFlag_1ms = true; // ustawienie flagi timera_1ms na 1
        Enable_Interrupt(); // Enable Timer1 interrupt
    }

    // obsluga funkcji TimeTick_10ms
    if (Podlicznik_Flag.podlicznik_10ms == true) { // jezeli podlicznik rowna sie 10 ms(0.01s)

        TimeTick_Interrupt_10ms();
    }

    // obsluga funkcji TimeTick_100ms
    if (Podlicznik_Flag.podlicznik_100ms == true) { // jezeli podlicznik rowna sie 100 ms (0.1s)

        TimeTick_Interrupt_100ms();
    }

    // obsluga funkcji TimeTick_1s
    if (Podlicznik_Flag.podlicznik_1s == true) { // jezeli podlicznik rowna sie 1000 ms (1s)

        TimeTick_Interrupt_1s();
    }

    // obsluga funkcji TimeTick_60s
    if (Podlicznik_Flag.podlicznik_60s == true) { // jezeli podlicznik rowna sie 60000 ms (1min)

        TimeTick_Interrupt_60s();
    }

    // obsluga funkcji TimeTick_1h
    if (Podlicznik_Flag.podlicznik_1h == true) { // jezeli podlicznik rowna sie 3600000ms (1h)

        TimeTick_Interrupt_1h();
    }
}

void  TMR1_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC0bits.T1IE = false;
    TMR1_InterruptHandler = InterruptHandler; 
    IEC0bits.T1IE = true;
}

void TMR1_Start( void )
{
    /* Reset the status information */
    tmr1_obj.timerElapsed = false;

    /*Enable the interrupt*/
    IEC0bits.T1IE = true;

    /* Start the Timer */
    T1CONbits.TON = 1;
}

void TMR1_Stop( void )
{
    /* Stop the Timer */
    T1CONbits.TON = false;

    /*Disable the interrupt*/
    IEC0bits.T1IE = false;
}

bool TMR1_GetElapsedThenClear(void)
{
    bool status;
    
    status = tmr1_obj.timerElapsed;

    if(status == true)
    {
        tmr1_obj.timerElapsed = false;
    }
    return status;
}

int TMR1_SoftwareCounterGet(void)
{
    return tmr1_obj.count;
}

void TMR1_SoftwareCounterClear(void)
{
    tmr1_obj.count = 0; 
}

/**
 End of File
*/


void Enable_Interrupt(void) {
    IEC0bits.T1IE = true; // Enable Timer1 interrupt
}

void Disable_Interrupt(void) {
    IEC0bits.T1IE = false; // Enable Timer1 interrupt
}

void TimeTick_Interrupt_10ms(void) {

    if (++Podlicznik_Bit.Counter_10ms >= Podlicznik_Bit.podlicznik_10ms) { // jezeli counter wiekszy od podlicznika, to

        Disable_Interrupt(); // Disable Timer1 interrupt 
        F1TimerRT.TimerFlag_10ms = true; // ustawienie flagi timera_10ms na 1
        Enable_Interrupt(); // Enable Timer1 interrupt

        Podlicznik_Bit.Counter_10ms = 0; // ustawienie flagi timera_10ms na 0
    }
}

void TimeTick_Interrupt_100ms(void) {

    if (++Podlicznik_Bit.Counter_100ms >= Podlicznik_Bit.podlicznik_100ms) { // jezeli counter wiekszy od podlicznika, to

        Disable_Interrupt(); // Disable Timer1 interrupt
        F1TimerRT.TimerFlag_100ms = true; // ustawienie flagi timera_100ms na 1
        Enable_Interrupt(); // Enable Timer1 interrupt   

        Podlicznik_Bit.Counter_100ms = 0; // ustawienie flagi timera_100ms na 0
    }
}

void TimeTick_Interrupt_1s(void) {

    if (++Podlicznik_Bit.Counter_1s >= Podlicznik_Bit.podlicznik_1s) { // jezeli counter wiekszy od podlicznika, to

        Disable_Interrupt(); // Disable Timer1 interrupt
        F1TimerRT.TimerFlag_1s = true; // ustawienie flagi timera_1s na 1
        Enable_Interrupt(); // Enable Timer1 interrupt

        Podlicznik_Bit.Counter_1s = 0; // ustawienie flagi timera_1s na 0
    }
}

void TimeTick_Interrupt_60s(void) {

    if (++Podlicznik_Bit.Counter_60s >= Podlicznik_Bit.podlicznik_60s) { // jezeli counter wiekszy od podlicznika, to

        Disable_Interrupt(); // Disable Timer1 interrupt
        F1TimerRT.TimerFlag_60s = true; // ustawienie flagi timera_60s na 1
        Enable_Interrupt(); // Enable Timer1 interrupt

        Podlicznik_Bit.Counter_60s = 0; // ustawienie flagi timera_60s na 0
    }
}

void TimeTick_Interrupt_1h(void) {

    if (++Podlicznik_Bit.Counter_1h >= Podlicznik_Bit.podlicznik_1h) { // jezeli counter wiekszy od podlicznika, to

        Disable_Interrupt(); // Disable Timer1 interrupt
        F1TimerRT.TimerFlag_1h = true; // ustawienie flagi timera_1h na 1
        Enable_Interrupt(); // Enable Timer1 interrupt

        Podlicznik_Bit.Counter_1h = 0; // ustawienie flagi timera_1h na 0
    }
}