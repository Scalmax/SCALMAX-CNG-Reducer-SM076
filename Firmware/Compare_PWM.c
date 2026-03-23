/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * Compare_PWM_v2.c
  
 * OPIS:
 * Plik Compare_PWM zawiera funkcje inicjalizacji modulow OC1 i OC2 oraz funkcje
 *  niezbedne do wygenerowania sygnalu PWM sterujacego praca grzalek  
 License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdbool.h>
#include <xc.h>
#include "exchange.h"
#include "fixed_t.h"
#include "Compare_PWM.h"
#include "definicje.h"
#include <outcompare.h>

static uint16_t OutputCompare1_ON; // zmienna wykorzystana do zalaczenia modulu OC1
static uint16_t OutputCompare2_ON; // zmienna wykorzystana do zalaczenia modulu OC2

/* Inicjalizacja modulu OutputCompare 1 */
void OutputCompare1_Initialize(void) {
    
    // ENFLT0 disabled; OCSIDL disabled; OCM Edge-Aligned PWM mode; OCFLT0 disabled; OCTSEL TMR2; TRIGMODE Hardware or Software; 
    OC1CON1 = 0x0E;
    // SYNCSEL Self; TRIGSTAT disabled; OCINV disabled; OCTRIG Sync; OC32 disabled; FLTOUT disabled; OCTRIS disabled; FLTMD Inactive; FLTTRIEN disabled; 
    OC1CON2 = 0x800C; // wypelnienie sie zmienia, a okres pozostaje bez zmian
    //OC1CON2 = 0x801F; // zmienne wypelnienie i okres    

    OC1R = 0x00; // OC1R = 0 - wypelnienie PWM
    OC1RS = 0x00; // OC1RS = 0; - okres PWM

    OutputCompare1_ON = OC1CON1bits.OCM; // flaga zalaczenia modulu OC1

    IFS0bits.OC1IF = false; // wyczyszczenie flagi przerwania modulu OC1
    IEC0bits.OC1IE = true; // zalaczenie przerwania modulu OC1
}

/* Inicjalizacja modulu OutputCompare 2 */
void OutputCompare2_Initialize(void) {
    
    // ENFLT0 disabled; OCSIDL disabled; OCM Edge-Aligned PWM mode; OCFLT0 disabled; OCTSEL TMR2; TRIGMODE Hardware or Software; 
    OC2CON1 = 0x0E;
    // SYNCSEL Self; TRIGSTAT disabled; OCINV disabled; OCTRIG Sync; OC32 disabled; FLTOUT disabled; OCTRIS disabled; FLTMD Inactive; FLTTRIEN disabled; 
    OC2CON2 = 0x800C; // wypelnienie sie zmienia, a okres pozostaje bez zmian
    //OC2CON2 = 0x801F; // zmienne wypelnienie i okres  

    OC2R = 0x00; // OC2R = 0; - wypelnienie PWM
    OC2RS = 0x00; // OC2RS = 0; - okres - PWM

    OutputCompare2_ON = OC2CON1bits.OCM; // flaga zalaczenia modulu OC2

    IFS0bits.OC2IF = false; // wyczyszczenie flagi przerwania modulu OC2
    IEC0bits.OC2IE = true; // zalaczenie przerwania modulu OC2
}

/* CallBack modulu OC1 */
void __attribute__((weak)) OutputCompare1_CallBack(void) {
    
    uint16_t MaksWypelnienie = 65535;
    uint32_t Dziel_8_Bajt = BITY_DZIELENIA_PRZEZ_8; 
    
    /* Wartosc maksymalna sygnalu sterowania w fixed_t - okres PWM */
    PWMData.OC1_Okres = (MAX_VAL * 2.559);
    /* zmienna wypelnienia PWM okreslona za pomoca sygnalu sterujacego PID */
    PWMData.OC1_Wypelnienie = (exchange_dynamic.SumReg1 * 2.559);
    
    if(PWMData.OC1_Wypelnienie >= PWMData.OC1_Okres){
        OutputCompare1_DutyCycle(MaksWypelnienie);
    }else{
    /* Przypisanie wartosci wypelnienia PWM do rejestru OC1R */
    OutputCompare1_DutyCycle(((uint16_t)(PWMData.OC1_Wypelnienie/Dziel_8_Bajt)));
    }
}

/* przerwanie modulu OC1 co 100 ms */
void __attribute__((interrupt, no_auto_psv)) _ISR _OC1Interrupt(void) {
    
    // jezeli flaga przerwania modulu OC1 = 1
    if (IFS0bits.OC1IF == 1) {
        // Wywolaj funkcje CallBack modulu OC1
        OutputCompare1_CallBack();
        // Wyzeruj flage przerwania modulu OC1
        IFS0bits.OC1IF = 0;
    }
}

/* CallBack modulu OC2 */
void __attribute__((weak)) OutputCompare2_CallBack(void) {

    uint16_t MaksWypelnienie = 65535;
    
    uint32_t Dziel_8_Bajt = BITY_DZIELENIA_PRZEZ_8;
    
    /* Wartosc maksymalna sygnalu sterowania w fixed_t - okres PWM */
    PWMData.OC2_Okres = (MAX_VAL * 2.559);
    /* zmienna wypelnienia PWM okreslona za pomoca sygnalu sterujacego PID */
    PWMData.OC2_Wypelnienie = (exchange_dynamic.SumReg1 * 2.559);
    
    if(PWMData.OC2_Wypelnienie >= PWMData.OC2_Okres){
        OutputCompare2_DutyCycle(MaksWypelnienie);
    }else{
    /* Przypisanie wartosci wypelnienia PWM do rejestru OC1R */
    OutputCompare2_DutyCycle(((uint16_t)(PWMData.OC2_Wypelnienie/Dziel_8_Bajt)));
    }
}

/* przerwanie modulu OC2 co 100ms */
void __attribute__((interrupt, no_auto_psv)) _ISR _OC2Interrupt(void) {

    // jezeli flaga modulu OC2 = 1
    if (IFS0bits.OC2IF == 1) {
        // Wywolaj funkcje CallBack modulu OC2
        OutputCompare2_CallBack();
        // Wyzeruj flage przerwania modulu OC2
        IFS0bits.OC2IF = 0;
    }
}

/* funkcja zalaczenia modulu OC1 */
void OutputCompare1_Enable(void) {

    OC1CON1bits.OCM = OutputCompare1_ON;

}

/* funkcja wylaczenia modulu OC1 */
void OutputCompare1_Disable(void) {
    OC1CON1bits.OCM = 0;
}

/* funkcja zalaczenia modulu OC2 */
void OutputCompare2_Enable(void) {
    OC2CON1bits.OCM = OutputCompare2_ON;
}

/* funkcja wylaczenia modulu OC2 */
void OutputCompare2_Disable(void) {
    OC2CON1bits.OCM = 0;
}

/* funkcja przypisania wartosci wypelnienia PWM do rejestru OC1R */
void OutputCompare1_DutyCycle(uint16_t DutyCycle) {
    OC1R = DutyCycle;
}

/* funkcja przypisania wartosci wypelnienia PWM do rejestru OC2R */
void OutputCompare2_DutyCycle(uint16_t DutyCycle) {
    OC2R = DutyCycle;
}