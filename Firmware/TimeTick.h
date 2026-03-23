/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * TimeTick.h
 
 * OPIS:
 * plik TimeTick zawiera deklaracje funkcji wykorzystywanych do utworzenia 
 * systemu przerwan czasu rzeczywistego i obs?ugi tych przerwa?
License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef TIMETICK_H

#define	TIMETICK_H

#include "xc.h"


void TimeTick_1ms(void); // deklaracja funkcji timera dla 1 milisekundy
void TimeTick_10ms(void); // deklaracja funkcji dla 10 milisekund
void TimeTick_100ms(void); // deklaracja funkcji dla 100 milisekund
void TimeTick_1s(void); // deklaracja funkcji dla 1 sekundy
void TimeTick_60s(void); // deklaracja funkcji dla 60 sekund
void TimeTick_1h(void); // deklaracja funkcji dla 1 godziny
void RealTime_Interrupt_ON(void); // deklaracja funkcji aktywuj?cej wszystkie podliczniki Real Time



#endif	/* TIMETICK_H */

