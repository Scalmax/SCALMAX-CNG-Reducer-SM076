/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * ADC.c
  
 * OPIS:
 * Plik ADC zawierajacy inicjalizacje modulu ADC niezbedna do pomiaru napiec 
 * wejsciowych pochodzacych z czujnikow analogowych NTC 4k7
License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdint.h>
#include <adc.h>
#include "xc.h"
#include "definicje.h"
#include "UstawieniaPinow.h"
#include "adc_temp.h"
#include "ADC1.h"

/* Inicjalizacja ADC */
void ADC_Initialize(void) {

    //wylaczenie wszystkich wejsc analogowych
    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    ANSELE = 0x0000;
    ANSELG = 0x0000;

    // wlaczenie odpowiednich wejsc analogowych
    ADC_k01 = 1; // wejscie napiecia (LevelInpic) - czujnik 2
    ADC_k02 = 1; // napieciowe wejscie uniwersalne - czujnik 1
    ADC_k03 = 1; // prad na wejsciu CurrVN3
    ADC_k04 = 1; // prad na wejsciu CurrVN4
    ADC_k05 = 1; // napiecie zasilania VDC


    // ustawienia AD1CON2
    AD1CON2 = ADC_VREF_AVDD_AVSS // A/D Voltage reference configuration Vref+ is AVdd and Vref- is AVss
            & ADC_SCAN_ON // A/D Scan Input Selections for CH0 during SAMPLE A 
            & ADC_SELECT_CHAN_01 // Converts CH0 
            & ADC_SETS_OF_SAMPLES_PER_INT_5 // DMA address increment after conversion of 2 samples 
            & ADC_ALT_BUF_OFF // Buffer configured as 1 16-word buffer 
            & ADC_ALT_INPUT_OFF; // use MUXA only 

    // ustawienia AD1CON3
    AD1CON3 = ADC_CONV_CLK_SYSTEM // A/D Conversion Clock Source Clock derived from system clock 
            & ADC_SAMPLE_TIME_31 // A/D Auto Sample Time 31 Tad 
            & ADC_CONV_CLK_32Tcy; // A/D conversion clock select bit ADCS<7:0> - 32TCY

    // ustawienia AD1CON4
    AD1CON4 = ADC_DMA_DIS; //brak DMA

    AD1CSSH = 0; // ADCx INPUT SCAN SELECT REGISTER HIGH
    AD1CSSL = 0; // ADCx INPUT SCAN SELECT REGISTER LOW

    // skanowanie wejsc
    AD1CSSHbits.CSS16 = 1; // skanowanie ADC wejscie LevelInpic (AN16 - RG9)
    AD1CSSLbits.CSS14 = 1; // skanowanie ADC wejscie UNI1 (AN14 - RE14)
    AD1CSSLbits.CSS11 = 1; // skanowanie ADC wejscie CurrVN4 (AN11 - RC11)
    AD1CSSLbits.CSS9 = 1; // skanowanie ADC wejscie CurrVN3 (AN9 - RA11)
    AD1CSSLbits.CSS8 = 1; // skanowanie ADC wejscie picAkuVdc (AN8 - RC2) 


    AD1CHS123 = 0; // ADCx INPUT CHANNELS 1, 2, 3 SELECT REGISTER - rejestr wylaczony
    AD1CHS0 = 0; // ADCx INPUT CHANNEL 0 SELECT REGISTER - rejestr wylacozny

    // ustawienia AD1CON1
    AD1CON1 = ADC_MODULE_ON // A/D Converter on 
            & ADC_IDLE_CONTINUE // A/D Operate in Idle mode 
            & ADC_AD12B_12BIT // 12 bit, 1-channel ADC operation 
            & ADC_FORMAT_INTG // A/D data format integer 
            & ADC_SSRC_TMR5 //ADC_SSRC_AUTO // SSRC = 111 & SSRCG = 0 Internal counter ends sampling and starts conversion (auto-convert) 
            & ADC_AUTO_SAMPLING_ON // Sampling begins immediately after last conversion 
            & ADC_MULTIPLE // Samples multiple channels individually in sequence 
            & ADC_ADDMABM_ORDER; // DMA buffers are written in the order of conversion 

    ConfigIntADC1(ADC_INT_ENABLE & ADC_INT_PRI_1);
}

void __attribute__((interrupt, no_auto_psv)) _AD1Interrupt(void) {

    uint8_t Filtr = FILTR_ILE_PROBEK;

    AnalogData.Current3 = ADC1BUF0;
    AnalogData.VDC = ADC1BUF1;
    AnalogData.Current4 = ADC1BUF2;
    AnalogData.TEMP_SENS_1 = ADC1BUF3; // przypisanie wartosci z ADC1BUF0 do zmiennej UNI 
    AnalogData.TEMP_SENS_2 = ADC1BUF4; // przypisanie wartosci z ADC1BUF1 do zmiennej LevelInpic

    //   

    if (IFS0bits.AD1IF == 1) {

        // Pomiar przekonwertowanej wartosci z modulu ADC - czujnik temperatury numer 1 
        ValueReadADC.pomiarADC1 = adc_temp(AnalogData.TEMP_SENS_1);
        // Przypisanie probek ADC do kolejnych kolumn w tablicy - czujnik 1 
        ValueReadADC.FiltrpomiarADC1[ValueReadADC.iADC1] = ValueReadADC.pomiarADC1;
        // Inkrementacja licznika iADC1
        ValueReadADC.iADC1++;

        // Pomiar przekonwertowanej wartosci z modulu ADC - czujnik temperatury numer 2 
        ValueReadADC.pomiarADC2 = adc_temp(AnalogData.TEMP_SENS_2);
        // Przypisanie probek ADC do kolejnych kolumn w tablicy - czujnik 2 
        ValueReadADC.FiltrpomiarADC2[ValueReadADC.iADC2] = ValueReadADC.pomiarADC2;
        // Inkrementacja licznika iADC2
        ValueReadADC.iADC2++;

        // Pomiar przekonwertowanej warosci z modulu ADC - pomiar pradu CurrVN3
        ValueReadADC.pomiarADC3 = AnalogData.Current3;
        // Przypisanie probek ADC do koljenych kolumn w tablicy - pomiar pradu CurrVN3
        ValueReadADC.FiltrpomiarADC3[ValueReadADC.iADC3] = ValueReadADC.pomiarADC3;
        // Inkrementacja licznika iADC3
        ValueReadADC.iADC3++;

        // Pomiar przekonwertowanej warosci z modulu ADC - pomiar pradu CurrVN4
        ValueReadADC.pomiarADC4 = AnalogData.Current4;
        // Przypisanie probek ADC do koljenych kolumn w tablicy - pomiar pradu CurrVN4 
        ValueReadADC.FiltrpomiarADC4[ValueReadADC.iADC4] = ValueReadADC.pomiarADC4;
        // Inkrementacja licznika iADC4
        ValueReadADC.iADC4++;

        // Pomiar przekonwertowanej warosci z modulu ADC - pomiar napiecia zasilajacego VDC
        ValueReadADC.pomiarADC5 = AnalogData.VDC;
        // Przypisanie probek ADC do koljenych kolumn w tablicy - pomiar napiecia zasilajacego VDC
        ValueReadADC.FiltrpomiarADC5[ValueReadADC.iADC5] = ValueReadADC.pomiarADC5;
        // Inkrementacja licznika iADC5
        ValueReadADC.iADC5++;

        // Jezeli licznik iADC1 wiekszy od FILTR_ILE_BAJTOW, to wyzeruj iADC1
        if (ValueReadADC.iADC1 >= Filtr) {

            ValueReadADC.iADC1 = 0;
        }

        // Jezeli licznik iADC2 wiekszy od FILTR_ILE_BAJTOW, to wyzeruj iADC2
        if (ValueReadADC.iADC2 >= Filtr) {

            ValueReadADC.iADC2 = 0;
        }

        // Jezeli licznik iADC23 wiekszy od FILTR_ILE_BAJTOW, to wyzeruj iADC3
        if (ValueReadADC.iADC3 >= Filtr) {

            ValueReadADC.iADC3 = 0;
        }

        // Jezeli licznik iADC4 wiekszy od FILTR_ILE_BAJTOW, to wyzeruj iADC4
        if (ValueReadADC.iADC4 >= Filtr) {

            ValueReadADC.iADC4 = 0;
        }

        // Jezeli licznik iADC5 wiekszy od FILTR_ILE_BAJTOW, to wyzeruj iADC5
        if (ValueReadADC.iADC5 >= Filtr) {

            ValueReadADC.iADC5 = 0;
        }

        // czysci flage przerwania modulu ADC
        IFS0bits.AD1IF = 0;
    }
}

/* Funkcja liczaca sume kumulacyjna ADC */
void ObliczenieSumyKumulacyjnej(void) {

    uint8_t Filtr = FILTR_ILE_PROBEK;

    for (ValueReadADC.jADC = 0; ValueReadADC.jADC < Filtr; ValueReadADC.jADC++) {
        /* Suma wszystkich probek ADC 1 (TEMP_SENS_1) */
        ValueReadADC.SumPomADC1 += ValueReadADC.FiltrpomiarADC1[ValueReadADC.jADC];
        /* Suma wszystkich probek ADC 2 (TEMP_SENS_2) */
        ValueReadADC.SumPomADC2 += ValueReadADC.FiltrpomiarADC2[ValueReadADC.jADC];
        /* Suma wszystkich probek ADC 3 (Current 3) */
        ValueReadADC.SumPomADC3 += ValueReadADC.FiltrpomiarADC3[ValueReadADC.jADC];
        /* Suma wszystkich probek ADC 4 (Current 4) */
        ValueReadADC.SumPomADC4 += ValueReadADC.FiltrpomiarADC4[ValueReadADC.jADC];
        /* Suma wszystkich probek ADC 5 (VDC) */
        ValueReadADC.SumPomADC5 += ValueReadADC.FiltrpomiarADC5[ValueReadADC.jADC];
    }

    /* Srednia uzyskana ze wszystkich probek z ADC1 */
    ValueReadADC.SumPomADC1 = (ValueReadADC.SumPomADC1 >> FILTR_ILE_BAJTOW);
    /* Srednia uzyskana ze wszystkich probek z ADC2 */
    ValueReadADC.SumPomADC2 = (ValueReadADC.SumPomADC2 >> FILTR_ILE_BAJTOW);
    /* Srednia uzyskana ze wszystkich probek z ADC3 */
    ValueReadADC.SumPomADC3 = (ValueReadADC.SumPomADC3 >> FILTR_ILE_BAJTOW);
    /* Srednia uzyskana ze wszystkich probek z ADC4 */
    ValueReadADC.SumPomADC4 = (ValueReadADC.SumPomADC4 >> FILTR_ILE_BAJTOW);
    /* Srednia uzyskana ze wszystkich probek z ADC5 */
    ValueReadADC.SumPomADC5 = (ValueReadADC.SumPomADC5 >> FILTR_ILE_BAJTOW);

    /* Przypisanie obliczonej wartosci sredniej ze wszystkich probek do zmiennej CurrTemp1 w fixed16_t */
    exchange_dynamic.CurrTemp1 = ValueReadADC.SumPomADC1;
    /* Przypisanie obliczonej wartosci sredniej ze wszystkich probek do zmiennej CurrTemp1 w fixed16_t */
    exchange_dynamic.CurrTemp2 = ValueReadADC.SumPomADC2;
    /* Przypisanie obliczonej wartosci sredniej ze wszystkich probek do zmiennej Current3 w fixed16_t */
    exchange_dynamic.Current3 = ValueReadADC.SumPomADC3;
    /* Przypisanie obliczonej wartosci sredniej ze wszystkich probek do zmiennej Current4 w fixed16_t */
    exchange_dynamic.Current4 = ValueReadADC.SumPomADC4;
    /* Przypisanie obliczonej wartosci sredniej ze wszystkich probek do zmiennej VDC w fixed16_t */
    exchange_dynamic.VDC = ValueReadADC.SumPomADC5;

}

/* Funkcja zalaczajaca modul ADC */
void ADC_Enable(void) {

    AD1CON1bits.ADON = 1;
}

/* Funkcja wylaczajaca modul ADC */
void ADC_Disable(void) {

    AD1CON1bits.ADON = 0;
}
