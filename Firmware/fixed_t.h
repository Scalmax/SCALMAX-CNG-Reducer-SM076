/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * fixed_t.h
 
 * OPIS:
 * plik nagowkowy fixed_t zawierajacy deklaracje funkcji przypisania wartosci int/float do
 * fixed_t i fixed16_t (8bit i 16bit) systemu regulacji temperatury na procesor
 * DSPIC33EV128GM106
 
 * przesuniecie bitowe
 
 */

#ifndef FIXED_T_H

#define	FIXED_T_H

#include <stdint.h>
#include "definicje.h"

typedef int16_t fixed_t;
typedef int32_t fixed16_t;

// DLA FIXED_T 8 - bit

// funkcja przypisania do fixed_t z int
inline __attribute__((always_inline)) fixed_t fixed_t_from_int(int16_t val);

// funkcja przypisania do fixed_t z float 
// dodawanie i odejmowanie jest standardowe
inline __attribute__((always_inline)) fixed_t fixed_t_from_float(float val);

// funkcja odpowiadajaca za mno?enie dwoch wartosci fixed_t
inline __attribute__((always_inline)) fixed_t fixed_t_mul(fixed_t val1, fixed_t val2);

// funkcja odpowiadajaca za dzielenie dwoch wartosci fixed_t
// mno?enie i dzielenie odbywa sie standardowo, tzn int*int = int
inline __attribute__((always_inline)) fixed_t fixed_t_div(fixed_t val1, fixed_t val2);

// funkcja przypisania fixed_t do int
inline __attribute__((always_inline)) int8_t fixed_t_to_int(fixed_t val);

// funkcja przypisania fixed_t do float
inline __attribute__((always_inline)) float fixed_t_to_float(fixed_t val);

// DLA FIXED16_T 16 - bit

// funkcja przypisania do fixed16_t z int
inline __attribute__((always_inline)) fixed16_t fixed16_t_from_int(int32_t val);

// funkcja przypisania do fixed16_t z float
inline __attribute__((always_inline)) fixed16_t fixed16_t_from_float(float val);

// funkcja odpowiadajaca za mno?enie dwoch wartosci fixed16_t
inline __attribute__((always_inline)) fixed16_t fixed16_t_mul(fixed16_t val1, fixed16_t val2);

// funkcja odpowiadajaca za dzielenie dwoch wartosci fixed16_t
inline __attribute__((always_inline)) fixed16_t fixed16_t_div(fixed16_t val1, fixed16_t val2);

// funkcja przypisania fixed16_t do int
inline __attribute__((always_inline)) int16_t fixed16_t_to_int(fixed16_t val);

// funkcja przypisania fixed16_t do float
inline __attribute__((always_inline)) float fixed16_t_to_float(fixed16_t val);

// funkcja przekierowania do fixed16_t z fixed_t
inline __attribute__((always_inline)) fixed_t fixed_t_from_fixed16_t(fixed16_t val);

// funkcja przekierowania do fixed_t z fixed16_t
inline __attribute__((always_inline)) fixed16_t fixed16_t_from_fixed_t(fixed_t val);

#endif	/* FIXED_T_H */

