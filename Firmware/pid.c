/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * PID.c
 
 * OPIS:
 * plik pid sterujacy systemem regulacji temperatury za pomoca dwoch rownoleglych,
 * niezaleznych regulatorowa PID (dyskretnych) na procesor DSPIC33EV128GM106
 * 
 * zastosowano ograniczenie amplitudy sygnalu sterujacego
 
 * Dodatkowo w pliku zastosowano mozliwosc wyboru rodzaju regulatorow (PI lub PID)
License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdlib.h>
#include <stdint.h>
#include "pid.h"
#include "definicje.h"

/* Funkcja zawierajaca rownania regulatora dyskretnego typu PID */
void pid(const volatile exchange_eeprom_t *_eeprom, volatile exchange_dynamic_t *_dynamic) {

/* zmienna stalej czasowej */
const fixed16_t time_const = (FIXED16_T_FROM_FLOAT(FLOAT_TIME_CONST))/2;
/* Odwrotnosc stalej czasowej regulatora PID w fixed16_t */
const fixed16_t reverse_time_const = FIXED16_T_FROM_FLOAT((1. / FLOAT_TIME_CONST));
    
    ////////////////////////////////////////// Rownania PID /////////////////////////////////////////

    //  e(t) = yzad(t) - y(t); 
    _dynamic->ErTemp1 = _eeprom->target_temp - _dynamic->CurrTemp1; // uchyb czujnika 1'ego
    _dynamic->ErTemp2 = _eeprom->target_temp - _dynamic->CurrTemp2; // uchyb czujnika 2'ego

    //  regP = Kp * e(t);
    _dynamic->PropReg1 = fixed16_t_mul(KP, _dynamic->ErTemp1); // rownanie czlonu P czujnika 1'ego
    _dynamic->PropReg2 = fixed16_t_mul(KP, _dynamic->ErTemp2); // rownanie czlonu P czujnika 2'ego

    //  errorsum = errorsum + ( e(t) + e(t - 1) ) * (T/2);
    _dynamic->ErSumTemp1 = _dynamic->ErSumTemp1 + fixed16_t_mul((_dynamic->ErTemp1 - _dynamic->ErLastTemp1), time_const); // suma uchybow czujnika 1'ego
    _dynamic->ErSumTemp2 = _dynamic->ErSumTemp2 + fixed16_t_mul((_dynamic->ErTemp2 - _dynamic->ErLastTemp2), time_const); // suma uchybow czujnika 2'ego

    //  regI = Ki * errorsum;
    _dynamic->IntReg1 = fixed16_t_mul(KI, _dynamic->ErSumTemp1); // rownanie czlonu I czujnika 1'ego
    _dynamic->IntReg2 = fixed16_t_mul(KI, _dynamic->ErSumTemp2); // rownanie czlonu I czujnika 2'ego

    switch (REGULATOR) {
        case 0: // 0 - regulator PID

            // errordiff = ( e(t) - e(t - 1) ) / T;
            _dynamic->ErDiffTemp1 = fixed16_t_mul((_dynamic->ErTemp1 - _dynamic->ErLastTemp1), reverse_time_const); // uchyb rozniczki czujnika 1'ego
            _dynamic->ErDiffTemp2 = fixed16_t_mul((_dynamic->ErTemp2 - _dynamic->ErLastTemp2), reverse_time_const); // uchyb rozniczki czujnika 1'ego

            //  regD = Kd * errordiff;
            _dynamic->DiffReg1 = fixed16_t_mul(KD, _dynamic->ErDiffTemp1); // rownanie czlonu D czujnika 1'ego
            _dynamic->DiffReg2 = fixed16_t_mul(KD, _dynamic->ErDiffTemp2); // rownanie czlonu D czujnika 2'ego

            //  PID = P + I + D;
            _dynamic->SumReg1 = _dynamic->PropReg1 + _dynamic->IntReg1 + _dynamic->DiffReg1; // rownanie regulatora PID dla czujnika 1'ego
            _dynamic->SumReg2 = _dynamic->PropReg2 + _dynamic->IntReg2 + _dynamic->DiffReg2; // rownanie regulatora PID dla czujnika 2'ego

            break;

        case 1: // 1 - regulator PI

            //  PI = P + I;
            _dynamic->SumReg1 = _dynamic->PropReg1 + _dynamic->IntReg1; // rownanie regulatora PI dla czujnika 1'ego
            _dynamic->SumReg2 = _dynamic->PropReg2 + _dynamic->IntReg2; // rownanie regulatora PI dla czujnika 2'ego

            break;
            
        default:
            break; 
    }

    //  e(t - 1) = e(t);
    _dynamic->ErLastTemp1 = _dynamic->ErTemp1; // uchyb poprzedni czujnika 1'ego
    _dynamic->ErLastTemp2 = _dynamic->ErTemp2; // uchyb poprzedni czujnika 2'ego
    
 /*
  |                                     |       
  |                                     |
  | NIE WYKORZYSTYWANE W TYM PRZYPADKU  |
  |                                     |
  |                                     |
  */

    /* Ograniczenie amplitudy sygnalu sterujacego ( MIN_VAL - MAX_VAL ) */

    // Jezeli sygnal sterowania PID dla czujnika 1 jest mniejszy od wartosci minimalnej
    if (_dynamic->SumReg1 < MIN_VAL) {
        _dynamic->LimitSumReg1 = MIN_VAL; // wartosc ograniczonego sygnalu sterowania rowna sie wartosci minimalnej zadanej przez uzytkownika
        
    }
        // Jezeli sygnal sterowania PID dla czujnika 1 jest wiekszy od wartosci minimalnej
    else if (_dynamic->SumReg1 > MAX_VAL) // jezeli wartosc sygnalu sterujacego jest wieksza od wartosci minimalnej okreslonej przez uzytkownika to: 
    {
        _dynamic->LimitSumReg1 = MAX_VAL; // wartosc ograniczonego sygnalu sterowania rowna sie wartosci maksymalnej zadanej przez uzytkownika
    }
        // jezeli powyzsze warunki nie sa spelnione, to: 
    else {
        _dynamic->LimitSumReg1 = _dynamic->SumReg1; // wartosc ograniczonego sygnalu sterowania rowna sie pierwotnej wartosci sygnalu sterowania
    }

    // Jezeli sygnal sterowania PID dla czujnika 2 jest mniejszy od wartosci minimalnej
    if (_dynamic->SumReg2 < MIN_VAL) {
        _dynamic->LimitSumReg2 = MIN_VAL; // wartosc ograniczonego sygnalu sterowania rowna sie wartosci minimalnej zadanej przez uzytkownika
    }
        // Jezeli sygnal sterowania PID dla czujnika 2 jest wiekszy od wartosci minimalnej
    else if (_dynamic->SumReg2 > MAX_VAL) // jezeli wartosc sygnalu sterujacego jest wieksza od wartosci minimalnej okreslonej przez uzytkownika to: 
    {
        _dynamic->LimitSumReg2 = MAX_VAL; // wartosc ograniczonego sygnalu sterowania rowna sie wartosci maksymalnej zadanej przez uzytkownika
    }
        // jezeli powyzsze warunki nie sa spelnione, to:
    else {
        _dynamic->LimitSumReg2 = _dynamic->SumReg2; // wartosc ograniczonego sygnalu sterowania rowna sie pierwotnej wartosci sygnalu sterowania
    }
}








