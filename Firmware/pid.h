/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * pid.h
  
 * OPIS:
 * plik naglowkowy pid zawierajacy deklaracje funkcji sterujacej systemem 
 * regulacji temperatury, na procesor DSPIC33EV128GM106
 License: MIT | SPDX-License-Identifier: MIT
 */


#ifndef PID_H // if ! define

#define	PID_H


#include <stdint.h>
#include "exchange.h"

/* deklaracja funkcji sterujacej systemem regulacji temperatury PID */
void pid(const volatile exchange_eeprom_t *exchange_eeprom, volatile exchange_dynamic_t *exchange_dynamic);

#endif	/* PID_H */