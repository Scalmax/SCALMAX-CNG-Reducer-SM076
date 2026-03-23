/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * uart_demo_v2.h
 
 * OPIS:
 * plik naglowkowy uart_demo_v2 zawiera funkcje 
 * wykorzystywane do zapewnienia komunikacji w formie asynchronicznego przekazu 
 * i odbioru danych za posrednictwem portu szerewegowego 
License: MIT | SPDX-License-Identifier: MIT
 */


#ifndef UART_DEMO_V2_H
#define	UART_DEMO_V2_H

#include <string.h>

void UART_Read(void); // Funkcja odpowiadajaca za odczyt wprowadzonych danych
uint8_t char_to_int(char *txt); // Funkcja odpowiadajaca za konwersje danych typu char do int
void UART_Write(char *string); // Funkcja odpowiadajaca za transmisje
void UART_Printf(void); // Funkcja odpowiadajaca za mozliwosc wprowadzenia nastaw, odczytania i przypisania ich do zmiennych 
void UART_Receive_Data(void); // Funkcja odpowiadajaca za wyswietlenie danych diagnostycznych
void UART_WyborDzialania(void); // Funkcja wyboru czynnosci UART
void UART_OdczytBledow(void); // Funkcja odpowiadajaca za odczyt bledow z czujnikow
void UART_OdczytBledowWybor(void); // Funkcja odpowiadajaca za ponowyny odczyt bledow lub wyjscie

#endif	/* UART_DEMO_V2 */