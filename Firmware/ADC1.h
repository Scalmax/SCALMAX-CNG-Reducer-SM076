/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * ADC.c
  
 * OPIS:
 * Plik ADC zawierajacy deklaracje funkcji niezbednych do pomiaru napiec 
 * wejsciowych pochodzacych z czujnikow analogowych NTC 4k7
License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef ADC1_H
#define	ADC1_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "exchange.h"

/* Inicjalizacja ADC */
void ADC_Initialize(void);
/* Funkcja liczaca sume kumulacyjna ADC */
void ObliczenieSumyKumulacyjnej(void);
/* Deklaracja funkjci zalaczajacej modul ADC */
void ADC_Enable(void);
/* Deklaracja funkjci wylaczajacej modul ADC */
void ADC_Disable(void);

#endif	/* ADC1_H */

