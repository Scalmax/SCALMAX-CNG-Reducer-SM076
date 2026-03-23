/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * printf.c
 
 * OPIS:
 * plik printf zawiera funkcje wykorzystane do wyswietlania danych diagnostycznych
 * pochodzacych z czunikow temperatury NTC 4k7 oraz obliczonych wartosci 
 * pochodzacych z regulatorow PID 
License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <string.h>
#include "exchange.h"
#include "fixed_t.h"

/* Funkcja odpowiadajaca za konwersje wartosci danych z fixed16_t do int */
void Konwersja_Danych_FixedToInt(void) {
    // uchyb czujnika 1'ego
    exchange_dynamic_decimal.ErTemp1_Dec = fixed16_t_to_int(exchange_dynamic.ErTemp1);
    // uchyb poprzedni czujnika 1'ego
    exchange_dynamic_decimal.ErLastTemp1_Dec = fixed16_t_to_int(exchange_dynamic.ErLastTemp1);
    // suma uchybow czujnika 1'ego
    exchange_dynamic_decimal.ErSumTemp1_Dec = fixed16_t_to_int(exchange_dynamic.ErSumTemp1);
    // uchyb rozniczki czujnika 1'ego
    exchange_dynamic_decimal.ErDiffTemp1_Dec = fixed16_t_to_int(exchange_dynamic.ErDiffTemp1);
    // wartosc czlonu P czujnika 1'ego
    exchange_dynamic_decimal.PropReg1_Dec = fixed16_t_to_int(exchange_dynamic.PropReg1);
    // wartosc czlonu I czujnika 1'ego
    exchange_dynamic_decimal.IntReg1_Dec = fixed16_t_to_int(exchange_dynamic.IntReg1);
    // wartosc czlonu D czujnika 1'ego
    exchange_dynamic_decimal.DiffReg1_Dec = fixed16_t_to_int(exchange_dynamic.DiffReg1);
    // wartosc sygnalu sterowania regulatora PID -> PID = P + I + D czujnika 1'ego
    exchange_dynamic_decimal.SumReg1_Dec = fixed16_t_to_int(exchange_dynamic.SumReg1);
    // wartosc ogranoczonego sygnalu sterowania regulatora PID czujnika 1'ego
    exchange_dynamic_decimal.LimitSumReg1_Dec = fixed16_t_to_int(exchange_dynamic.LimitSumReg1);
    // Konwersja temperatury w fixed16_t do temperatury w stopniach Celsjusza czujnika 1'ego
    exchange_dynamic_decimal.CurrTemp1_Dec = fixed16_t_to_int(exchange_dynamic.CurrTemp1);

    // uchyb czujnika 2
    exchange_dynamic_decimal.ErTemp2_Dec = fixed16_t_to_int(exchange_dynamic.ErTemp2);
    // uchyb poprzedni czujnika 2
    exchange_dynamic_decimal.ErLastTemp2_Dec = fixed16_t_to_int(exchange_dynamic.ErLastTemp2);
    // suma uchybow czujnika 2
    exchange_dynamic_decimal.ErSumTemp2_Dec = fixed16_t_to_int(exchange_dynamic.ErSumTemp2);
    // uchyb rozniczki czujnika 2
    exchange_dynamic_decimal.ErDiffTemp2_Dec = fixed16_t_to_int(exchange_dynamic.ErDiffTemp2);
    // wartosc czlonu P czujnika 2
    exchange_dynamic_decimal.PropReg2_Dec = fixed16_t_to_int(exchange_dynamic.PropReg2);
    // wartosc czlonu I czujnika 2
    exchange_dynamic_decimal.IntReg2_Dec = fixed16_t_to_int(exchange_dynamic.IntReg2);
    // wartosc czlonu D czujnika 2
    exchange_dynamic_decimal.DiffReg2_Dec = fixed16_t_to_int(exchange_dynamic.DiffReg2);
    // wartosc sygnalu sterowania regulatora PID -> PID = P + I + D czujnika 2
    exchange_dynamic_decimal.SumReg2_Dec = fixed16_t_to_int(exchange_dynamic.SumReg2);
    // wartosc ogranoczonego sygnalu sterowania regulatora PID czujnika 2
    exchange_dynamic_decimal.LimitSumReg2_Dec = fixed16_t_to_int(exchange_dynamic.LimitSumReg2);
    // Konwersja temperatury w fixed16_t do temperatury w stopniach Celsjusza  czujnika 2
    exchange_dynamic_decimal.CurrTemp2_Dec = fixed16_t_to_int(exchange_dynamic.CurrTemp2);

}


void Print_Reg_PID_Sens_Together(void){
    
    printf("\n%ld   %ld %ld   %ld %ld     %ld %ld",
            // temperatura zadana
            exchange_eeprom.target_temp_dec,
            // temperatura odczytana z czujnika 1
            exchange_dynamic_decimal.CurrTemp1_Dec,
            // uchyb czujnika 2
            exchange_dynamic_decimal.ErTemp1_Dec,
            // wartosc sygnalu sterowania PID czujnika 1
            exchange_dynamic_decimal.SumReg1_Dec,
            // wartosc ograniczonego sygnalu sterowania PID czujnika 1
            exchange_dynamic_decimal.LimitSumReg1_Dec,
            // temperatura odczytana z czujnika 1
            exchange_dynamic_decimal.CurrTemp2_Dec,
            // uchyb czujnika 1
            exchange_dynamic_decimal.ErTemp2_Dec);
}

void Print_Reg_PI_Sens_Together(void){
    
    printf("\n%ld   %ld %ld   %ld %ld     %ld %ld",
            // temperatura zadana
            exchange_eeprom.target_temp_dec,
            // temperatura odczytana z czujnika 1
            exchange_dynamic_decimal.CurrTemp1_Dec,
            // uchyb czujnika 2
            exchange_dynamic_decimal.ErTemp1_Dec,
            // wartosc sygnalu sterowania PID czujnika 1
            exchange_dynamic_decimal.SumReg1_Dec,
            // wartosc ograniczonego sygnalu sterowania PID czujnika 1
            exchange_dynamic_decimal.LimitSumReg1_Dec,
            // temperatura odczytana z czujnika 2
            exchange_dynamic_decimal.CurrTemp2_Dec,
            // uchyb czujnika 2
            exchange_dynamic_decimal.ErTemp2_Dec);
}












