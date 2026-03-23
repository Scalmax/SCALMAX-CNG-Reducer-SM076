/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * fixed_t.c
 
 * OPIS:
 * plik fixed_t zawierajacy funkcje przypisania wartosci int/float do
 * fixed_t i fixed16_t (8bit i 16bit) systemu regulacji temperatury

 * License: MIT | SPDX-License-Identifier: MIT 
 */

#include "fixed_t.h"
#include <stdbool.h>
#include "definicje.h"

// funkcja przypisania do fixed_t z int

inline __attribute__((always_inline)) fixed_t fixed_t_from_int(int16_t val) {
    
    return FIXED_T_FROM_INT(val);
}

// funkcja przypisania do fixed_t z float 

inline __attribute__((always_inline)) fixed_t fixed_t_from_float(float val) {

    return FIXED_T_FROM_FLOAT(val); // dodawanie i odejmowanie jest standardowe
}

// funkcja odpowiadajaca za mno?enie dwoch wartosci fixed_t

inline __attribute__((always_inline)) fixed_t fixed_t_mul(fixed_t val1, fixed_t val2) {

    return ((int32_t) val1 * val2) / (0x100);
    //return ((int32_t) val1 * val2) >> FIXED_T_BITS;
}

//funkcja odpowiadajaca za dzielenie dwoch wartosci fixed_t

inline __attribute__((always_inline)) fixed_t fixed_t_div(fixed_t val1, fixed_t val2) {

    return (((int32_t) val1) * 256) / val2;
    //return (((int32_t) val1) << FIXED_T_BITS) / val2; // mno?enie i dzielenie odbywa sie standardowo, tzn int*int = int
}

// funkcja przypisania fixed_t do int

inline __attribute__((always_inline)) int8_t fixed_t_to_int(fixed_t val) {

    return FIXED_T_TO_INT(val);
}

// funkcja przypisania fixed_t do float

inline __attribute__((always_inline)) float fixed_t_to_float(fixed_t val) {

    return FIXED_T_TO_FLOAT(val);
}


/* DLA FIXED16_T 16 - bit */

// funkcja przypisania do fixed16_t z int

inline __attribute__((always_inline)) fixed16_t fixed16_t_from_int(int32_t val) {

    return FIXED16_T_FROM_INT(val);
}

// funkcja przypisania do fixed16_t z float

inline __attribute__((always_inline)) fixed16_t fixed16_t_from_float(float val) {

    return FIXED16_T_FROM_FLOAT(val); // dodawanie i odejmowanie jest standardowe
}

// funkcja odpowiadajaca za mnozenie dwoch wartosci fixed16_t

inline __attribute__((always_inline)) fixed16_t fixed16_t_mul(fixed16_t val1, fixed16_t val2) {

    bool minus = false;
    int32_t wartosc;

    int32_t value1 = val1;
    int32_t value2 = val2;

    if (value1 < 0) { // je?eli pierwsza wartosc jest mniejsza od zera to:

        value1 = -(value1); // zmiana znaku
        minus = !minus; // minus = true
    }

    if (val2 < 0) { // jezeli druga wartosc jest mniejsza od zera to

        value2 = -value2; // zmiana znaku
        minus = !minus; // minus = true
    }

    int32_t a1 = value1 / (0x10000),
            //a1 = value1 >> 16,
            a2 = (value1 & 0xFFFF),
            b1 = value2 / (0x10000),
            //b1 = value2 >> 16,
            b2 = (value2 & 0xFFFF);

    if (minus) {

        wartosc = -(((a1 * b1)*(0x10000)) + ((a1 * b2) + (b1 * a2))+((a2 * b2) / (0x10000)));
        //return -(((a1 * b1) << 16) + ((a1 * b2) + (b1 * a2))+((a2 * b2) >> 16));

    } 
    else {
        wartosc = ((a1 * b1)*(0x10000)) + ((a1 * b2) + (b1 * a2)) + ((a2 * b2) / (0x10000));
        //return ((a1 * b1) << 16) + ((a1 * b2) + (b1 * a2)) + ((a2 * b2) >> 16);
    }
    return wartosc;

}

// funkcja odpowiadajaca za dzielenie dwoch wartosci fixed16_t

inline __attribute__((always_inline)) fixed16_t fixed16_t_div(fixed16_t val1, fixed16_t val2) {

    return (((int32_t) val1) / (0x10000)) / val2;
    //return (((int32_t) val1) << FIXED16_T_BITS) / val2;
}

// funkcja przypisania fixed16_t do int

inline __attribute__((always_inline)) int16_t fixed16_t_to_int(fixed16_t val) {

    return FIXED16_T_TO_INT(val);
}

// funkcja przypisania fixed16_t do float

inline __attribute__((always_inline)) float fixed16_t_to_float(fixed16_t val) {

    return FIXED16_T_TO_FLOAT(val);
}


/* PRZEKIEROWANIE Z FIXED_T do FIXED16_T i na odwrot */

// funkcja przekierowania do fixed16_t z fixed_t

inline __attribute__((always_inline)) fixed_t fixed_t_from_fixed16_t(fixed16_t val) {

    return val / (0x100); // przesuniecie o 8 bit
}

// funkcja przekierowania do fixed_t z fixed16_t

inline __attribute__((always_inline)) fixed16_t fixed16_t_from_fixed_t(fixed_t val) {

    return ((int32_t) val) * (0x100); // przesuniecie o 8 bit
}
