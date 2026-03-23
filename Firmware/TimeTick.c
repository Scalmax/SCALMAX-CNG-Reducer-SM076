/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * TimeTick.c
 
 * OPIS:
 * plik TimeTick zawiera funkcje wykorzystywane do utworzenie systemu przerwan 
 * czasu rzeczywistego i obs?ugi tych przerwa?
License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdbool.h>
#include "TimeTick.h"
#include "exchange.h"


///////////////////////////////// Wedlug Jiry //////////////////////////////////


void TimeTick_1ms(void)
{
    Podlicznik_Bit.podlicznik_1ms = 1;
    Podlicznik_Flag.podlicznik_1ms = true;
}

// Fukcja timera dla 10 milisekund
void TimeTick_10ms(void) 
{
    Podlicznik_Bit.podlicznik_10ms = 10;
    Podlicznik_Flag.podlicznik_10ms = true;
}

// Fukcja timera dla 100 milisekund
void TimeTick_100ms(void) 
{
    Podlicznik_Bit.podlicznik_100ms = 100;
    Podlicznik_Flag.podlicznik_100ms = true;
}

// Fukcja timera dla 1 sekundy
void TimeTick_1s(void) 
{
    Podlicznik_Bit.podlicznik_1s = 1000;
    Podlicznik_Flag.podlicznik_1s = true;
}

// Fukcja timera dla 60 sekund
void TimeTick_60s(void) 
{
    Podlicznik_Bit.podlicznik_60s = 60000;
    Podlicznik_Flag.podlicznik_60s = true;
}

// Fukcja timera dla 1 godziny
void TimeTick_1h(void) 
{    
    Podlicznik_Bit.podlicznik_1h = 3600000;
    Podlicznik_Flag.podlicznik_1h = true;
}

/* Funkcja aktywuj?ca wszystkie podliczniki Real Time */
void RealTime_Interrupt_ON(void){
    
    /* Funkcja wyboru podlicznika dla 1 ms */
    TimeTick_1ms();
    /* Funkcja wyboru podlicznika dla 10 ms */
    TimeTick_10ms();
    /* Funkcja wyboru podlicznika dla 100 ms */
    TimeTick_100ms();
    /* Funkcja wyboru podlicznika dla 1s */
    TimeTick_1s();
    /* Funkcja wyboru podlicznika dla 60s */
    TimeTick_60s();
    /* Funkcja wyboru podlicznika dla 1sh */
    TimeTick_1h();
    
}






