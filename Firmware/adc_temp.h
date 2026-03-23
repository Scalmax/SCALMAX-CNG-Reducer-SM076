/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * adc_temp.h
  
 * OPIS:
 * Plik naglowkowy adc_temp zawierajacy deklaracje funkcji odczytu temperatury 
 * z ADC
License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef ADC_TEMP_H

#define	ADC_TEMP_H

#include "fixed_t.h"

#include <stdint.h>

// deklaracja funkcji wyboru czujnika temperatury
void WyborCzujnikaTemperatury(uint8_t czujnik);
// deklaracja funkcji adc_temp
fixed16_t adc_temp(int32_t adc);

#endif	/* ADC_TEMP_H */
