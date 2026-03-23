/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * obs_timerow.c
 
 * OPIS:
 * plik obs_timerow zawiera funkcje wykorzystywane do obslugi timerow czasu 
 * rzeczywistego
License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdbool.h>
#include "xc.h"
#include "obs_timerow.h"
#include "TimeTick.h"
#include "uart_demo_v2.h"
#include "exchange.h"
#include "errors.h"
#include "pid.h"
#include "ADC1.h"
#include "Compare_PWM.h"

/* Funkcja obslugi timerow */
void Obsluga_Timerow(void) {
    // Zmienna licznika petli glownej
    F1TimerRT.CountMainLoop++;
    // Jezeli flaga timera 1 ms = true, to
    if (F1TimerRT.TimerFlag_1ms == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_1ms();
        /* Funkcja odpowiadajaca za wpisanie nastaw do regulatora PI/PID */
        UART_Printf();
        /* Funkcja odpowiadajaca za obliczenie sumy kumulacyjnej ADC */
        ObliczenieSumyKumulacyjnej();
        /* Zalaczenie funkcji sprawdzajacej czy nie ma bledow czujnikow */
        CheckSensorErrorsON();
        /* Funkcja odpowiedzialna za sprawdzenie bledow czujnikow */
        UART_OdczytBledow();
        // Wyzeruj flage timera 1ms
        F1TimerRT.TimerFlag_1ms = false;
    }

    // Jezeli flaga timera 10 ms = true, to
    if (F1TimerRT.TimerFlag_10ms == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_10ms();
        
        // Wyzeruj flage timera 10ms
        F1TimerRT.TimerFlag_10ms = false;
    }

    // Jezeli flaga timera 100 ms = true, to
    if (F1TimerRT.TimerFlag_100ms == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_100ms();
        // Funkcja odpowiedzialna za wyswietlenie danych diagnostycznych
        UART_Receive_Data();

        // Wyzeruj flage timera 100ms
        F1TimerRT.TimerFlag_100ms = false;
    }

    // Jezeli flaga timera 1s = true, to
    if (F1TimerRT.TimerFlag_1s == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_1s();
        /* Wywolanie funkcji PID */
        pid(&exchange_eeprom, &exchange_dynamic);
        // Wyzeruj flage timera 1s
        F1TimerRT.TimerFlag_1s = false;
    }

    // Jezeli flaga timera 60s = true, to
    if (F1TimerRT.TimerFlag_60s == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_60s();
        // Wyzeruj flage timera 60s
        F1TimerRT.TimerFlag_60s = false;
    }

    // Jezeli flaga timera 1h = true, to
    if (F1TimerRT.TimerFlag_1h == true) {
        // Funkcja obslugi timera 1ms
        ObslugaTimera_1h();
        // Wyzeruj flage timera 1h
        F1TimerRT.TimerFlag_1h = false;
    }
}

// Funkcja obslugi timera 1ms

void ObslugaTimera_1ms(void) {

    uint32_t Podlicznik_1s = 1000;
    // 1 sek = 1ms * 1000
    F1TimerRT.OpPer1s = (F1TimerRT.CountMainLoop * Podlicznik_1s);
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

// Funkcja obslugi timera 10ms

void ObslugaTimera_10ms(void) {

    uint32_t Podlicznik_100ms = 100;
    // 1 sek = 10 ms * 100
    F1TimerRT.OpPer1s = (F1TimerRT.CountMainLoop * Podlicznik_100ms);
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

// Funkcja obslugi timera 100ms

void ObslugaTimera_100ms(void) {

    uint32_t Podlicznik_10ms = 10;
    // 1 sek = 100 ms * 10
    F1TimerRT.OpPer1s = (F1TimerRT.CountMainLoop * Podlicznik_10ms);
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

// Funkcja obslugi timera 1s

void ObslugaTimera_1s(void) {

    // 1 sek = 1000 ms
    F1TimerRT.OpPer1s = F1TimerRT.CountMainLoop;
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

// Funkcja obslugi timera 60s

void ObslugaTimera_60s(void) {

    uint32_t Podlicznik_60s = 60;
    // 1 sek = 60000 ms / 60
    F1TimerRT.OpPer1s = (F1TimerRT.CountMainLoop / Podlicznik_60s);
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

// Funkcja obslugi timera 1h

void ObslugaTimera_1h(void) {

    uint32_t Podlicznik_1h = 3600;
    // 1 sek = 3600000 / 3600
    F1TimerRT.OpPer1s = (F1TimerRT.CountMainLoop / Podlicznik_1h);
    // Zerowanie flagi licznika
    F1TimerRT.CountMainLoop = 0;
}

