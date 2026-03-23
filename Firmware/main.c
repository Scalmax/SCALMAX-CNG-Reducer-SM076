/*
* @file    main.c
 * @author  [SCALMAX Pawel Poplawski / SCALMAX]
 * @date    2024-03-22
 * @version 1.0
 * * Target MCU: Microchip dsPIC33EV128GM106
 * * ---------------------------------------------------------------------------
 * OPIS PROJEKTU (PL)
 * ---------------------------------------------------------------------------
 * Oprogramowanie steruj?ce temperatur? pracy reduktora gazu CNG.
 * Program realizuje algorytm stabilizacji temperatury w celu zapobiegania 
 * zamarzaniu reduktora podczas rozpr??ania gazu. Wykorzystuje peryferia 
 * skonfigurowane w MPLAB® Code Configurator (MCC) dla dsPIC33EV.
 * * ? OSTRZE?ENIE DOTYCZ?CE BEZPIECZE?STWA:
 * Praca z instalacjami CNG (spr??ony gaz ziemny) stwarza ryzyko wybuchu, 
 * po?aru oraz uszkodzenia mienia lub cia?a. Autor NIE PONOSI ?ADNEJ 
 * ODPOWIEDZIALNO?CI za jakiekolwiek szkody, awarie, wypadki lub straty 
 * powsta?e w wyniku u?ycia, modyfikacji lub b??dnego dzia?ania tego kodu. 
 * Budujesz i u?ywasz tego urz?dzenia wy??cznie na w?asne ryzyko!
 * * ---------------------------------------------------------------------------
 * PROJECT DESCRIPTION (EN)
 * ---------------------------------------------------------------------------
 * Firmware for controlling the operating temperature of a CNG gas regulator.
 * The program implements a temperature stabilization algorithm to prevent 
 * regulator freezing during gas decompression. Developed using MCC for 
 * the dsPIC33EV128GM106 microcontroller.
 * * ? SAFETY WARNING:
 * Working with CNG (Compressed Natural Gas) systems poses a risk of explosion, 
 * fire, and property or personal damage. The Author SHALL NOT BE HELD LIABLE 
 * for any damages, failures, accidents, or losses resulting from the use, 
 * modification, or malfunction of this code. Build and use at your own risk!
 * * ---------------------------------------------------------------------------
 * LICENCJA / LICENSE (SPDX-License-Identifier: MIT)
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 [SCALMAX Pawel Poplawski / SCALMAX]
 * Ten kod autorski jest na licencji MIT. Pe?na tre?? w pliku LICENSE.
 * This custom code is licensed under the MIT License. Full text in LICENSE file.
 * ---------------------------------------------------------------------------
 */

/**
 * FIRMA:
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * main.c
 
 * OPIS:
 * plik main systemu regulatora temperatury na procesor DSPIC33EV128GM106
 * integracja regulatora PID z SM-076
  
 * OPIS UZYTYCH PINOW: 
 * 
 * PC7 - picOut3 (Pin ON/OFF grzalki numer 1) - modul OC1
 * PC8 - picOut4 (Pin ON/OFF grzalki numer 2) - modul OC2
 * RB15 - picLed1 (Pin ON/OFF Led_1)
 * RG7 - picLed2 (Pin ON/OFF Led_2)
 * 
 * RF0 - UART - U1RX - input
 * RF1 - UART - U1TX - output
 * 
 * PODLACZENIE DEBUGERA:
 * 
 * RB2 - PGEC1 (przewod zolty)
 * RB3 - PGED1 (przewod zielony)
 * Vpp - GND_D (przewod czerwony)
 * Vdd - 3,3 V (przewod czarny)
 * MCLR - (przewod bialy)
 
 * WYBOR TERMISTORA:
 * 
 * TEMP_SENS_2K - termistor NTC 2k
 * TEMP_SENS_2K2 - termistor NTC 2k2
 * TEMP_SENS_3K3 - termistor NTC 3k3
 * TEMP_SENS_4K7 - termistor NTC 4k7
 * TEMP_SENS_6K7 - termistor NTC 6k8
 * TEMP_SENS_10K - termistor NTC 10k 
  
 */

#include <adc.h>
#include "obs_timerow.h"
#include "TimeTick.h"
#include "mcc_generated_files/system.h"
#include "uart_demo_v2.h"
#include "mcc_generated_files/pin_manager.h"
#include "definicje.h"
#include "UstawieniaPinow.h"
#include "adc_temp.h"
#include "ADC1.h"
#include "Compare_PWM.h"
#include "errors.h"

int main(void) {

    /* Clear Watchdog */
    ClrWdt();
    
    /* Funkcja wyboru termistora */
    WyborCzujnikaTemperatury(TEMP_SENS_4K7);
    /* Inicjalizacja systemu */
    SYSTEM_Initialize();
    /* Inicjalizacja ADC */
    ADC_Initialize();
    /* Inicjalizacja modulu OutputCompare_1 */
    OutputCompare1_Initialize();
    /* Inicjalizacja modulu OutputCompare_2 */
    OutputCompare2_Initialize();
    /* Funkcja ustawiajaca nieuzywane piny jako wyjscia ze stanem LOW */
    Ustawienia_Pinow();
    /* Funkcja aktywuj?ca wszystkie podliczniki Real Time */
    RealTime_Interrupt_ON();
    /* Zalaczenie modulu OutputCompare_1 */
    OutputCompare1_Enable();
    /* Zalaczenie modulu OutputCompare_2 */
    OutputCompare2_Enable();
    /* Wylaczenie FR_STANDBY - do pomiaru pradu*/
    PIC_FR_OFF;
    
    while (1) {

        /* Clear Watchdog */
        ClrWdt();

        /* Jezeli stacyjka ON */
        if (STAC_IN == ON) {
            /* Zalaczenie diody zielonej - sygnalizacja zalaczenia stacyjki*/
            LED_ONLY_GREEN
            /* Zalaczenie zasilania rzeczy analogowych */
            POWER_OUT_5V = ON;
            /* Zalaczenie przekaznika (na wyjsciu >12V) */
            PIC_POWER_ON;
            /* Funkcja obslugi timerow */
            Obsluga_Timerow();
            /* Funkcja odpowiadajaca za zmiane danych w kazdym momencie dzialania UART */
            UART_WyborDzialania();
            /* Jezeli stacyjka OFF, to przejdz dalej */
            continue;
        }
        /* Wylaczenie zasilania rzeczy analogowych */
        POWER_OUT_5V = OFF;
        /* Wylaczenie przekaznika */
        PIC_POWER_OFF;
        /* Wylaczenie diod */
        LED_OFF
        /* Wylaczenie funkcji sprawdzajacej czy nie ma bledow czujnikow */
        CheckSensorErrorsOFF();     
    }
    return 0; // zwraca 0 jesli wszystko przebiegnie pomyslnie
}