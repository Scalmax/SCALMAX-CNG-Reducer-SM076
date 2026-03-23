/**

 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * exchange.c
  
 * OPIS:
 * plik exchange (modul komunikacji) zawierajacy funkcje z danymi diagnostycznymi
 * zawarymi w strukturze
 * dodatkowo w pliku zawarto stale odpowiadajace za ustawienia modulu UART 
License: MIT | SPDX-License-Identifier: MIT
 */

#include <string.h>
#include "exchange.h"


volatile exchange_eeprom_t exchange_eeprom;
volatile exchange_dynamic_t exchange_dynamic;
volatile exchange_dynamic_decimal_t exchange_dynamic_decimal;
volatile ValueReadADC_t ValueReadADC;
volatile AnalogData_t AnalogData;
volatile PWMData_t PWMData;
volatile F1TimerRT_t F1TimerRT;
volatile CoeffPolynominal_t CoeffPolynominal;
volatile zmienneUART_t zmienneUART;
volatile tekst_t tekst;
volatile ErVar_t ErVar;
volatile Podlicznik_Bit_t Podlicznik_Bit;
volatile Podlicznik_Flag_t Podlicznik_Flag;
volatile TWizD_Flag_Bit_t WizD_Flag_Bit;
volatile TWizD_Error_Bit_t WizD_Error_Bit;



// Dane do UART
const int32_t Baud_Rate = 38400; // szybkosc transmisji
const int8_t Data_Bits = (8 + 1); // bity danych
const int8_t Stop_Bits = 1; // bity stopu
const int8_t Checked_Bits = 1; // ile bitow do sprawdzenia w RX
const int8_t Software_Receive_Buffer_Size = 8; // rozmiar bufora odbioru 
const int8_t Software_Transmit_Buffer_Size = 8; // rozmiar bufora transmisji 
const int8_t parity = 1; // parzystosc - EVEN
const int8_t flow_control = 0; // NO


