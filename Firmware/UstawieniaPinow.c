/**
  
 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * UstawieniaPinow.c
  
 * OPIS:
 * Plik UstawieniaPinow zawieracy funkcje z ustawieniami pinow mikrokontrolera 
 * DSPIC33EV128GM106
License: MIT | SPDX-License-Identifier: MIT
 */

#include <xc.h>
#include "mcc_generated_files/pin_manager.h"
#include "definicje.h"
#include <adc.h>

/* Funkcja zawierajaca ustawienia uzywanych pinow */
void Ustawienia_Pinow(void) {

    // nieuzywane piny jako wyjscia

    NOT_USED_IN_01_PIN = OUTPUT; // RG8 jako wyjscie
    NOT_USED_IN_02_PIN = OUTPUT; // RA0 jako wyjscie 
    NOT_USED_IN_03_PIN = OUTPUT; // RA1 jako wyjscie
    NOT_USED_IN_04_PIN = OUTPUT; // RB0 jako wyjscie
    NOT_USED_IN_05_PIN = OUTPUT; // RB1 jako wyjscie
    NOT_USED_IN_06_PIN = OUTPUT; // RC0 jako wyjscie
    NOT_USED_IN_07_PIN = OUTPUT; // RC1 jako wyjscie
    NOT_USED_IN_08_PIN = OUTPUT; // RE12 jako wyjscie
    NOT_USED_IN_09_PIN = OUTPUT; // RE13 jako wyjscie
    NOT_USED_IN_10_PIN = OUTPUT; // RE15 jako wyjscie
    NOT_USED_IN_11_PIN = OUTPUT; // RA8 jako wyjscie
    NOT_USED_IN_12_PIN = OUTPUT; // RA10 jako wyjscie
    NOT_USED_IN_13_PIN = OUTPUT; // RB11 jako wyjscie
    NOT_USED_IN_14_PIN = OUTPUT; // RC9 jako wyjscie
    NOT_USED_IN_15_PIN = OUTPUT; // RD5 jako wyjscie
    NOT_USED_IN_16_PIN = OUTPUT; // RB8 jako wyjscie                  
    NOT_USED_IN_17_PIN = OUTPUT; // RB6 jako wyjscie 
    NOT_USED_IN_18_PIN = OUTPUT; // RB5 jako wyjscie
    NOT_USED_IN_19_PIN = OUTPUT; // RD8 jako wyjscie   
    NOT_USED_IN_20_PIN = OUTPUT; // RC5 jako wyjscie
    NOT_USED_IN_21_PIN = OUTPUT; // RC4 jako wyjscie
    NOT_USED_IN_22_PIN = OUTPUT; // RC3 jako wyjscie  

    // stan niski na nieuzywanych pinach
    NOT_USED_IN_01 = OFF; // stan niski na RG8
    NOT_USED_IN_02 = OFF; // stan niski na RA0
    NOT_USED_IN_03 = OFF; // stan niski na RA1
    NOT_USED_IN_04 = OFF; // stan niski na RB0
    NOT_USED_IN_05 = OFF; // stan niski na RB1
    NOT_USED_IN_06 = OFF; // stan niski na RC0
    NOT_USED_IN_07 = OFF; // stan niski na RC1
    NOT_USED_IN_08 = OFF; // stan niski na RE12
    NOT_USED_IN_09 = OFF; // stan niski na RE13
    NOT_USED_IN_10 = OFF; // stan niski na RE15
    NOT_USED_IN_11 = OFF; // stan niski na RA8
    NOT_USED_IN_12 = OFF; // stan niski na RA10
    NOT_USED_IN_13 = OFF; // stan niski na RB11
    NOT_USED_IN_14 = OFF; // stan niski na RC9
    NOT_USED_IN_15 = OFF; // stan niski na RD5
    NOT_USED_IN_16 = OFF; // stan niski na RB8
    NOT_USED_IN_17 = OFF; // stan niski na RB6
    NOT_USED_IN_18 = OFF; // stan niski na RB5
    NOT_USED_IN_19 = OFF; // stan niski na RD8
    NOT_USED_IN_20 = OFF; // stan niski na RC5
    NOT_USED_IN_21 = OFF; // stan niski na RC4
    NOT_USED_IN_22 = OFF; // stan niski na RC3

    // pozostale piny
    POWER_OUT_5V_PIN = OUTPUT; // RA4 jako wyjscie (zasilanie analogow)
    STAC_IN_PIN = INPUT; // RC13 jako wejscie (stacyjka)
    LED_G_PIN = OUTPUT; // RB15 jako wyjscie (dioda zielona)
    LED_R_PIN = OUTPUT; // RG7 jako wyjscie (dioda czerowna)   
    PIC_FR_PIN = OUTPUT; // RD6 jako wyjscie (FR_Standby)
    PIC_POWER_PIN = OUTPUT; // RB10 jako wyjscie (picPower)
    PIC_BEEP_OUT_PIN = OUTPUT; // RB4 jako wyjscie (picBeep) - Buzzer
    HEATER_1_PIN = OUTPUT; // RC7 jako wyjscie (picOut3) - grzalka 1 
    HEATER_1_PIN = OUTPUT; // RC8 jako wyjscie (picOut4) - grzalka 2
    GIN_HEATER_1 = INPUT; // RB13 jako wejscie (GIN3)
    GIN_HEATER_1 = INPUT; // RB12 jako wejscie (GIN4)
}