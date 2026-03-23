/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * definicje.h
 
 * OPIS:
 * plik definicje zawiera definicje (makra) wykorzystanych zmiennych w programie
 * na procesor DSPIC33EV128GM106 niezbednych do integracji regulatora PID z SM-076
License: MIT | SPDX-License-Identifier: MIT
 */


#include <stdint.h>
#include "mcc_generated_files/pin_manager.h"
#include "fixed_t.h"
#include "exchange.h"
#include "UstawieniaPinow.h"

#define ON      1 // zalaczenie 
#define OFF     0 // wylaczenie
#define INPUT   1 // wejscie
#define OUTPUT  0 // wyjscie

// definicje wyjscia stacyjki
#define STAC_IN                 _RC13       // definicja pinu stacyjki
#define STAC_IN_PIN             _TRISC13

// definicje zasilania analogowych pierdol
#define POWER_OUT_5V            _RA4        //zasilanie wejsc analogowych
#define POWER_OUT_5V_PIN        _TRISA4   

// definicja pinow centralki LED
#define LED_G                   _LATB15     // definicja pinu diody zielonej
#define LED_G_PIN               _TRISB15
#define LED_R                   _LATG7      // definicja pinu diody czerwonej
#define LED_R_PIN               _TRISG7

//  tranzystory na wejsciach sterowania diodami, P kanal poniewaz jesli bedzie w HIGH Z to nie bedzie dioda swiecila na zielono
#define LED_ONLY_GREEN          LED_G = (!(1&STAC_IN)); LED_R = (!(1&STAC_IN)); // wlaczona tylko dioda zielona                  
#define LED_GREEN_AND_READ      LED_G = (!(1&STAC_IN)); LED_R = 1;              // wlaczone: dioda zielona i czerwona
#define LED_OFF                 LED_G = 1;              LED_R = (!(STAC_IN));   // diody wylaczone

// definicja pinu FR_STANDBY
#define PIC_FR                  _RD6
#define PIC_FR_PIN              _TRISD6

#define PIC_FR_ON               PIC_FR = 1;     // FR_STANDBY ON
#define PIC_FR_OFF              PIC_FR = 0;    // FR_STANDBY OFF

// definicje picPowerON
#define PIC_POWER               _RB10
#define PIC_POWER_PIN           _TRISB10

#define PIC_POWER_ON            PIC_POWER = 1;
#define PIC_POWER_OFF           PIC_POWER= 0;

// definicje picBeepOn
#define PIC_BEEP_OUT            _RB4
#define PIC_BEEP_OUT_PIN        _TRISB4

#define PIC_BEEP_ON             PIC_BEEP_OUT = 1;
#define PIC_BEEP_OFF            PIC_BEEP_OUT = 0;

// definicje grzalek
#define HEATER_1                _RC7
#define HEATER_1_PIN            _TRISC7
#define HEATER_2                _RC8
#define HEATER_2_PIN            _TRISC8

// definicje GIN grzalek
#define GIN_HEATER_1            _RB13
#define GIN_HEATER_1_PIN        _TRISB13
#define GIN_HEATER_2            _RB12
#define GIN_HEATER_2_PIN        _TRISB12

// nieuzywane piny
#define NOT_USED_IN_01          _RG8    // RG8
#define NOT_USED_IN_01_PIN      _TRISG8
#define NOT_USED_IN_02          _RA0    // RA0
#define NOT_USED_IN_02_PIN      _TRISA0
#define NOT_USED_IN_03          _RA1    // RA1
#define NOT_USED_IN_03_PIN      _TRISA1
#define NOT_USED_IN_04          _RB0    // RB0
#define NOT_USED_IN_04_PIN      _TRISB0
#define NOT_USED_IN_05          _RB1    // RB1
#define NOT_USED_IN_05_PIN      _TRISB1
#define NOT_USED_IN_06          _RC0    // RC0
#define NOT_USED_IN_06_PIN      _TRISC0
#define NOT_USED_IN_07          _RC1    // RC1
#define NOT_USED_IN_07_PIN      _TRISC1
#define NOT_USED_IN_08          _RE12   // RE12
#define NOT_USED_IN_08_PIN      _TRISE12
#define NOT_USED_IN_09          _RE13   // RE13
#define NOT_USED_IN_09_PIN      _TRISE13
#define NOT_USED_IN_10          _RE15   // RE15
#define NOT_USED_IN_10_PIN      _TRISE15
#define NOT_USED_IN_11          _RA8    // RA8
#define NOT_USED_IN_11_PIN      _TRISA8
#define NOT_USED_IN_12          _RA10   // RA10
#define NOT_USED_IN_12_PIN      _TRISA10
#define NOT_USED_IN_13          _RB11   // RB11
#define NOT_USED_IN_13_PIN      _TRISB11
#define NOT_USED_IN_14          _RC9    // RC9
#define NOT_USED_IN_14_PIN      _TRISC9
#define NOT_USED_IN_15          _RD5    // RD5
#define NOT_USED_IN_15_PIN      _TRISD5
#define NOT_USED_IN_16          _RB8    // RB8
#define NOT_USED_IN_16_PIN      _TRISB8
#define NOT_USED_IN_17          _RB6    // RB6
#define NOT_USED_IN_17_PIN      _TRISB6
#define NOT_USED_IN_18          _RB5    // RB5
#define NOT_USED_IN_18_PIN      _TRISB5
#define NOT_USED_IN_19          _RD8    // RD8
#define NOT_USED_IN_19_PIN      _TRISD8
#define NOT_USED_IN_20          _RC5    // RC5
#define NOT_USED_IN_20_PIN      _TRISC5
#define NOT_USED_IN_21          _RC4    // RC4
#define NOT_USED_IN_21_PIN      _TRISC4
#define NOT_USED_IN_22          _RC3    // RC3
#define NOT_USED_IN_22_PIN      _TRISC3

// definicje kontroli (control.c)
#define TARGET_TEMP             exchange_eeprom.target_temp_dec          // definicja temperatury zadanej przez uzytkownika w stopniach Celsjusza
#define CURRENT_TEMP1_DEGREES   exchange_dynamic_decimal.data.CurrTemp1_Dec   // definicja temperatury wyjsciowej, odczytana z czujnika 1 w stopniach Celsjusza
#define CURRENT_TEMP2_DEGREES   exchange_dynamic_decimal.data.CurrTemp2_Dec   // definicja temperatury wyjsciowej, odczytana z czujnika 2 w stopniach Celsjusza

// definicje fixed_t
#define FIXED_T_BITS 8 // definicja przesuniecia dla fixed_t
#define FIXED16_T_BITS 16 // definicja przesuniecia dla fixed16_t

#define FIXED_T_FROM_INT(val)       (val)*(0x100)                       // definicja konwersji z int do fixed_t
#define FIXED_T_FROM_FLOAT(val)     (((val)*(1.))*(0x100))                     // definicja konwersji z float do fixed_t
#define FIXED_T_TO_INT(val)         (val)/(0x100)                       // definicja konwersji z fixet_t do int
#define FIXED_T_TO_FLOAT(val)       (((val)*(1.))/(0x100))              // definicja konwersji z fixed_t do 

#define FIXED16_T_FROM_INT(val)     (val)*(0x10000)                     // definicja konwersji z int do fixed16_t
#define FIXED16_T_FROM_FLOAT(val)   (((val)*(1.))*(0x10000))                   // definicja konwersji z float do fixed16_t (literka L sprawia ze int jest 32 bit)
#define FIXED16_T_TO_INT(val)       (val)/(0x10000)                     // definicja konwersji z fixet16_t do int
#define FIXED16_T_TO_FLOAT(val)     ((val)*(1.))/(0x10000)              // definicja konwersji z fixed16_t do


//#define FIXED_T_FROM_INT(val)   (val) << FIXED_T_BITS                 // definicja konwersji z int do fixed_t
//#define FIXED_T_FROM_FLOAT(val) (val)*(1 << FIXED_T_BITS)             // definicja konwersji z float do fixed_t
//#define FIXED_T_TO_INT(val)     (val) >> FIXED_T_BITS                 // definicja konwersji z fixet_t do int
//#define FIXED_T_TO_FLOAT(val)   ((val)*(1.))/(1<<FIXED_T_BITS)        // definicja konwersji z fixed_t do 

//#define FIXED16_T_FROM_INT(val) (val)<<FIXED16_T_BITS                 // definicja konwersji z int do fixed16_t
//#define FIXED16_T_FROM_FLOAT(val) (val)*((1L)<<FIXED16_T_BITS)        // definicja konwersji z float do fixed16_t (literka L sprawia ze int jest 32 bit)
//#define FIXED16_T_TO_INT(val)   (val)>>FIXED16_T_BITS                 // definicja konwersji z fixet16_t do int
//#define FIXED16_T_TO_FLOAT(val) ((val)*(1.))/(1L<<FIXED16_T_BITS)     // definicja konwersji z fixed16_t do

// definicje nastaw PID
#define REGULATOR               exchange_eeprom.regulator                      // definicja wyboru regulatora
#define MIN_VAL                 FIXED16_T_FROM_INT(exchange_eeprom.Min_Val_a)  // definicja minimalnej wartosci sygnalu sterowania
#define MAX_VAL                 FIXED16_T_FROM_INT(exchange_eeprom.Max_Val_a)  // definicja maksymalnej wartosci sygnalu sterowania
#define KP                      FIXED16_T_FROM_INT(exchange_eeprom.Kp)         // definicja spolczynnika wzmocnienia czlonu regulatora typu P
#define KI                      FIXED16_T_FROM_INT(exchange_eeprom.Ki)         // definicja wspolczynnika wzmocnienia czlonu regulatora typu I
#define KD                      FIXED16_T_FROM_INT(exchange_eeprom.Kd)         // definicja wspolczynnika wzmocnienia czlonu regulatora typu D
#define FLOAT_TIME_CONST 0.1    // definicja stalej czasowej

// definicje UART
#define RECEIVE_TABLE_SIZE (8+1)    // definicja rozmiaru bufora odczytu
#define TRANSMIT_TABLE_SIZE 256     // definicja rozmiaru bufora zapisupolynomial
#define LICZBA_ZMIENNYCH 7          // definicja liczby zmiennych (nastaw)
#define LICZBA_CZUJNIKOW 8          // definicja liczby czujnikow 

#define TARGET_TEMP_MAX 120 // definicja maksymalnej wartosci temperatury zadanej
#define MIN_VAL_SET 0       // definicja minimalnej wartosci wzmocnien
#define MAX_VAL_SET 10       // definicja maksymalnej wartosci wzmocniej
#define MIN_VAL_UART 0      // definicja minimalnej wartosci sygnalu sterowania
#define MAX_VAL_UART 200    // definicja maksymalnej wartosci sygnalu sterowania

// definicja wyboru termistora (czujnika temperatury)
#define TEMP_SENS exchange_eeprom.temp_sens    // definicja przypisania czujnika temperatury do makra TEMP_SENS
#define TEMP_SENS_2K  1     // definicja wyboru czujnika NTC 2K
#define TEMP_SENS_2K2 2     // definicja wyboru czujnika NTC 2K2
#define TEMP_SENS_3K3 3     // definicja wyboru czujnika NTC 3K3
#define TEMP_SENS_4K7 4     // definicja wyboru czujnika NTC 4K7
#define TEMP_SENS_6K8 5     // definicja wyboru czujnika NTC 6K8
#define TEMP_SENS_10K 6     // definicja wyboru czujnika NTC 10K

// definicje wspolczynnikow adc_temp (NTC 2k)
#define A6_2K 70.879957     // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 2K
#define A5_2K -480.1654     // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 2K
#define A4_2K 1285.8203     // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 2K
#define A3_2K -1753.928     // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 2K
#define A2_2K 1306.8913     // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 2K
#define A1_2K -527.8831     // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 2K
#define A0_2K 167.93524     // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 2K

// definicje wspolczynnikow adc_temp (NTC 2k2)
#define A6_2K2 78.234509    // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 2K2
#define A5_2K2 -531.6377    // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 2K2
#define A4_2K2 1416.7246    // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 2K2
#define A3_2K2 -1898.299    // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 2K2
#define A2_2K2 1362.2082    // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 2K2
#define A1_2K2 -556.5532    // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 2K2
#define A0_2K2 153.64285    // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 2K2

// definicje wspolczynnikow adc_temp (NTC 3k3)
#define A6_3K3 70.038123    // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 3K3
#define A5_3K3 -474.4288    // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 3K3
#define A4_3K3 1271.7572    // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 3K3
#define A3_3K3 -1739.52     // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 3K3
#define A2_3K3 1302.9961    // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 3K3
#define A1_3K3 -576.3779    // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 3K3
#define A0_3K3 170.1131     // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 3K3

// definicje wspolczynnikow adc_temp (NTC 4k7) - 6st
#define A6_4K7 33.240828    // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 4K7
#define A5_4K7 -249.34814   // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 4K7
#define A4_4K7 729.14858    // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 4K7
#define A3_4K7 -1081.508    // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 4K7
#define A2_4K7 876.24853    // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 4K7
#define A1_4K7 -424.4753    // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 4K7
#define A0_4K7 141.51544    // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 4K7

// definicje wspolczynnikow adc_temp (NTC 6k8)
#define A6_6K8 77.82268     // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 6K8
#define A5_6K8 -528.8347    // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 6K8
#define A4_6K8 1409.559     // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 6K8
#define A3_6K8 -1889.871    // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 6K8
#define A2_6K8 1357.9       // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 6K8
#define A1_6K8 -556.1455    // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 6K8
#define A0_6K8 153.9289     // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 6K8

// definicje wspolczynnikow adc_temp (NTC 10k)
#define A6_10K 77.82268     // definicja wspolczynnika a6 wielomianu 6'ego stopnia dla NTC 10K
#define A5_10K -528.8347    // definicja wspolczynnika a5 wielomianu 6'ego stopnia dla NTC 10K
#define A4_10K 1409.559     // definicja wspolczynnika a4 wielomianu 6'ego stopnia dla NTC 10K
#define A3_10K -1889.871    // definicja wspolczynnika a3 wielomianu 6'ego stopnia dla NTC 10K
#define A2_10K 1357.9       // definicja wspolczynnika a2 wielomianu 6'ego stopnia dla NTC 10K
#define A1_10K -556.1455    // definicja wspolczynnika a1 wielomianu 6'ego stopnia dla NTC 10K
#define A0_10K 153.9289     // definicja wspolczynnika a0 wielomianu 6'ego stopnia dla NTC 10K

// definicje kanalow ADC
#define ADC_k01 ANSELGbits.ANSG9    // wejscie napieciowe czujnika 1
#define ADC_k02 ANSELEbits.ANSE14   // wejscie napieciowe czujnika 2
#define ADC_k03 ANSELCbits.ANSC2    // prad na wejsciu CurrVN3
#define ADC_k04 ANSELCbits.ANSC11   // prad na wejsciu CurrVN4
#define ADC_k05 ANSELAbits.ANSA11   // napiecie zasilania

// definicje filtrow
#define FILTR_ILE_BAJTOW            5    // (5 bajtow - 32 probki)
#define FILTR_ILE_PROBEK            32   // )

// definicje bledow czujnika
#define STALA_V                     0.00122     // stala napiecia do przeliczania wartosci dziesietnych na napiecie
#define STALA_V_TO_DEC              819.2       // stala napiecia do przeliczania napiecia na wartosci dziesietne

// definicje pradu na scalaku
#define RSENSE                      2000        // rezystor na scalaku
#define I_OUT_TO_I_SENSE            2190        // stosunek pradu wyjscia do pradu czujnika

#define BITY_DZIELENIA_PRZEZ_8      256
#define BITY_DZIELENIA_PRZEZ_16     65536



