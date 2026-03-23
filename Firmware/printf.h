/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * printf.h
 
 * OPIS:
 * plik naglowkowy printf zawiera deklaracje funkcji wykorzystanych do wyswietlania danych diagnostycznych
 * pochodzacych z czunikow temperatury NTC 4k7 oraz obliczonych wartosci 
 * pochodzacych z regulatorow PID 
License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef PRINTF_H
#define	PRINTF_H

#include <xc.h> // include processor files - each processor file is guarded.  

/* Funkcja odpowiadajaca za wyswietlenie danych diagnostycznych dla reg PID i 2 czujnikow */
void Print_Reg_PID_Sens_Together(void);
/* Funkcja odpowiadajaca za wyswietlenie danych diagnostycznych dla reg PI i 2 czujnikow */
void Print_Reg_PI_Sens_Together(void);
/* Funkcja odpowiadajaca za konwersje wartosci danych z fixed16_t do int */
void Konwersja_Danych_FixedToInt(void);



#endif	/* PRINTF_H */

