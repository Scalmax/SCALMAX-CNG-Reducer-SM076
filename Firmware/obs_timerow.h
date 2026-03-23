/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * obs_timerow.h
 
 * OPIS:
 * plik naglowkowy obs_timerow zawiera deklaracje funkcji wykorzystywanych do 
 * obslugi timerow czasu rzeczywistego
License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef OBS_TIMEROW_H

#define	OBS_TIMEROW_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Obsluga_Timerow(void); // Funkcja obslugi timerow
void ObslugaTimera_1ms(void); // Funkcja obslugi timera 1ms
void ObslugaTimera_10ms(void); // Funkcja obslugi timera 10ms
void ObslugaTimera_100ms(void); // Funkcja obslugi timera 100ms
void ObslugaTimera_1s(void); // Funkcja obslugi timera 1s
void ObslugaTimera_60s(void); // Funkcja obslugi timera 60s
void ObslugaTimera_1h(void); // Funkcja obslugi timera 1h

#endif	/* OBS_TIMEROW_H */

