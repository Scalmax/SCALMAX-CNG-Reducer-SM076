/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * TypyZmiennych.h
 
 * OPIS:
 * plik TypyZmniennych zawiera definicje Typow zmiennych
License: MIT | SPDX-License-Identifier: MIT
 */  

#ifndef TYPYZMIENNYCH_H
#define	TYPYZMIENNYCH_H

#include <xc.h> // include processor files - each processor file is guarded.  

// definicje typow zmiennych
typedef unsigned short int uWord; // 16bit liczba calkowita     0...65535
typedef signed short int sWord; // 16bit liczba calkowita       -32768...32767
typedef unsigned char uByte; // 8bit liczba calkowita           0...255
typedef signed char sByte; // 8bit liczba calkowita             -128...127
typedef unsigned long int UdWord; // 32bit liczba calkowita     0...4 294 967 295
typedef signed long int SdWord; // 32bit liczba calkowita       -2 147 483 648...2 147 483 647
typedef unsigned long long UqWord; // 64bit liczba calkowita    0...(w *uj)
typedef signed long long SqWord; // 64bit liczba calkowita      w *uj na minusie ... w *uj na plusie 

#endif	/* TYPYZMIENNYCH_H */

