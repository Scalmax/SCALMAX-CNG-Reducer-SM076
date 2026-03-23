/**

 * FIRMA: 
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * adc_temp.c
 
 * OPIS:
 * plik adc_temp zawiera funckje realizujaca algorytm Hornera niezbedny do 
 * obliczenia temperatury dla wielomianu dowolnego stopnia 
 * Dodatkowo plik zawiera funkcje wyboru czujnika temperatury oraz funkcje 
 * przypisujaca kolejne wspolczynniki wielomianu do zmiennych
 License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdint.h>
#include "adc_temp.h"
#include "fixed_t.h"
#include "definicje.h"

/* Funkcja odpowiadajaca za wybor czujnika temperatury */
void WyborCzujnikaTemperatury(uint8_t czujnik) {
    // przypisanie odpowiedniego rodzaju czujnika do zmiennej temp_sens
    exchange_eeprom.temp_sens = czujnik;

    switch (TEMP_SENS) {
            // NTC 2K
        case 1:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_2K); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 2K
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_2K); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 2K
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_2K); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 2K
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_2K); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 2K
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_2K); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 2K
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_2K); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 2K
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_2K); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 2K
            break;

            // NTC 2K2
        case 2:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_2K2); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 2K2
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_2K2); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 2K2
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_2K2); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 2K2
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_2K2); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 2K2
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_2K2); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 2K2
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_2K2); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 2K2
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_2K2); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 2K2
            break;

            // NTC 3K3
        case 3:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_3K3); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 3K3
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_3K3); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 3K3
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_3K3); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 3K3
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_3K3); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 3K3
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_3K3); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 3K3
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_3K3); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 3K3
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_3K3); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 3K3
            break;

            //NTC 4K7
        case 4:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_4K7); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 4K7
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_4K7); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 4K7
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_4K7); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 4K7
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_4K7); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 4K7
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_4K7); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 4K7
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_4K7); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 4K7
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_4K7); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 4K7
            break;

            // NTC 6K8
        case 5:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_6K8); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 6K8
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_6K8); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 6K8
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_6K8); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 6K8
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_6K8); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 6K8
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_6K8); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 6K8
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_6K8); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 6K8
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_6K8); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 6K8
            break;

            // NTC 10K
        case 6:

            CoeffPolynominal.A6 = FIXED16_T_FROM_FLOAT(A6_10K); // przypisanie wartosci wspolczynnika a6 w fixed16_t do zmiennej A6 dla NTC 10K
            CoeffPolynominal.A5 = FIXED16_T_FROM_FLOAT(A5_10K); // przypisanie wartosci wspolczynnika a5 w fixed16_t do zmiennej A5 dla NTC 10K
            CoeffPolynominal.A4 = FIXED16_T_FROM_FLOAT(A4_10K); // przypisanie wartosci wspolczynnika a4 w fixed16_t do zmiennej A4 dla NTC 10K
            CoeffPolynominal.A3 = FIXED16_T_FROM_FLOAT(A3_10K); // przypisanie wartosci wspolczynnika a3 w fixed16_t do zmiennej A3 dla NTC 10K
            CoeffPolynominal.A2 = FIXED16_T_FROM_FLOAT(A2_10K); // przypisanie wartosci wspolczynnika a2 w fixed16_t do zmiennej A2 dla NTC 10K
            CoeffPolynominal.A1 = FIXED16_T_FROM_FLOAT(A1_10K); // przypisanie wartosci wspolczynnika a1 w fixed16_t do zmiennej A1 dla NTC 10K
            CoeffPolynominal.A0 = FIXED16_T_FROM_FLOAT(A0_10K); // przypisanie wartosci wspolczynnika a0 w fixed16_t do zmiennej A0 dla NTC 10K
            break;

        default:
            break;
    }

}

//funkcja realizujaca algorytm Hornera dla wielomianu 6'ego stopnia

fixed16_t adc_temp(int32_t adc) {

    int32_t pomiar = adc;
    
    pomiar <<= 5; // przesuniecie wyniku o 5 bit 

    fixed16_t res = CoeffPolynominal.A6; // u = An
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A5; // u = (u*adc) + An-1  
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A4; // u = (u*adc) + An-2     
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A3; // u = (u*adc) + An-3
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A2; // u = (u*adc) + An-4
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A1; // u = (u*adc) + An-5
    res = fixed16_t_mul(res, pomiar) + CoeffPolynominal.A0; // u = (u*adc) + An-6
    //
    /* w przypadku wielomianu innego stopnia, gdzie n != 6  nalezy zmienic wartosci wspolczynnikow zgodnie z plikiem czujniki.charakterystyka.ods
     * oraz w algorytmie Hornera dodac/usunac okreslone rownania zgodnie z przyjetymi zalozeniami
     */

    return res; // zwraca wartosc (res) - temperature w fixed16_t
}
