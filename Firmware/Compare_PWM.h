/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * Compare_PWM_v2.h
  
 * OPIS:
 * Plik Compare_PWM zawiera deklaracje funkcji inicjalizacji modulow OC1 i OC2 
 * oraz deklaracje funkcji niezbednych do wygenerowania sygnalu PWM sterujacego 
 * praca grzalek  
 
 */

#ifndef COMPARE_PWM_H
#define	COMPARE_PWM_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdbool.h>

/* Inicjalizacja modulu OutputCompare 1 */
void OutputCompare1_Initialize(void);
/* Inicjalizacja modulu OutputCompare 2 */
void OutputCompare2_Initialize(void);
/* CallBack modulu OC1 */
void OutputCompare1_CallBack(void);
/* CallBack modulu OC2 */
void OutputCompare2_CallBack(void);
// funkcja zalaczenia modulu OC1
void OutputCompare1_Enable(void);
// funkcja zalaczenia modulu OC2
void OutputCompare2_Enable(void);
// funkcja wylaczenia modulu OC1
void OutputCompare1_Disable(void);
// funkcja wylaczenia modulu OC1
void OutputCompare2_Disable(void);
// funkcja przypisania wartosci wypelnienia PWM do rejestru OC1R
void OutputCompare1_DutyCycle(uint16_t DutyCycle);
// funkcja przypisania wartosci wypelnienia PWM do rejestru OC2R
void OutputCompare2_DutyCycle(uint16_t DutyCycle);

#endif	/* COMPARE_PWM_V2_H */