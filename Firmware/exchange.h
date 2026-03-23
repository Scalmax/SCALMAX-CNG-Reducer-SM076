/**

 * FIRMA:
 * SCALMAX Pawel Poplawski
  
 * PLIK:
 * exchange.h
  
 * OPIS:
 * plik naglowkowy exchange (modul komunikacji) zawierajacy strukty z danymi
 * diagnostycznymi
 License: MIT | SPDX-License-Identifier: MIT
 */

#ifndef EXCHANGE_H
#define	EXCHANGE_H

#include "definicje.h"
#include "TypyZmiennych.h"

// struktura ze zmiennymi do zapisu przez uzytkownika w pamieci eeprom

struct tag_exchange_eeprom_t {
    int8_t regulator; // zmienna wyboru regulatora
    int8_t temp_sens; // zmienna wyboru czujnika temperatury
    int8_t Czujnik; // zmienna 
    int32_t Min_Val_a; // wartosc minimalna sygnalu sterowania regulatora
    int32_t Max_Val_a; // wartosc maksymalna sygnalu sterowania regulatora
    int32_t target_temp; // zmienna temperatury zadanej przez uzytkownika
    int32_t target_temp_dec; // zmienna temperatury zadanej przez uzytkownika w postaci dziesietnej
    int32_t Kp; // wspolczynnika wzmocnienia czlonu regulatora typu P
    int32_t Ki; // wspolczynnik wzmocnienia czlonu regulatora typu I
    int32_t Kd; // wspolczynnik wzmocnienia czlonu regulatora typu D

};

typedef struct tag_exchange_eeprom_t exchange_eeprom_t;
extern volatile exchange_eeprom_t exchange_eeprom;

// struktura ze zmiennymi dynamicznymi do odczytu przez uzytkownika

struct tag_exchange_dynamic_t {
    int32_t ErTemp1; // uchyb pid 1
    int32_t ErTemp2; // uchyb pid 1
    int32_t ErLastTemp1; // uchyb poprzedni pid 1
    int32_t ErLastTemp2; // uchyb poprzedni pid 1
    int32_t ErSumTemp1; // suma uchybow pid 1
    int32_t ErSumTemp2; // suma uchybow pid 1
    int32_t ErDiffTemp1; // uchyb rozniczki pid 1
    int32_t ErDiffTemp2; // uchyb rozniczki pid 1
    int32_t CurrTemp1; // temperatura wyjsciowa (obecna) czujnik 1
    int32_t CurrTemp2; // temperatura wyjsciowa (obecna) czujnik 1
    int32_t PropReg1; // wartosc czlonu proporcjonalnego pid 1
    int32_t PropReg2; // wartosc czlonu proporcjonalnego pid 2
    int32_t IntReg1; // wartosc czlonu calkujacego pid 1
    int32_t IntReg2; // wartosc czlonu calkujacego pid 1
    int32_t DiffReg1; // wartosc czlonu rozniczkujacego pid 1
    int32_t DiffReg2; // wartosc czlonu rozniczkujacego pid 1
    int32_t SumReg1; // wartosc sygnalu sterujacego (wezel sumacyjny poszczegolnych czlonow P, I, D) pid 1
    int32_t SumReg2; // wartosc sygnalu sterujacego (wezel sumacyjny poszczegolnych czlonow P, I, D) pid 2
    int32_t LimitSumReg1; // wartosc ograniczonego sygnalu sterujacego pid 1
    int32_t LimitSumReg2; // wartosc ograniczonego sygnalu sterujacego pid 2
    sWord Current3;
    sWord Current4;
    sWord VDC;

};

typedef struct tag_exchange_dynamic_t exchange_dynamic_t;
extern volatile exchange_dynamic_t exchange_dynamic;


// Dynamic_decimal

struct tag_exchange_dynamic_decimal_t {
    SdWord CurrTemp1_Dec; // wartosc dziesietna temperatury wyjsciowej z czujnika 1
    SdWord CurrTemp2_Dec; // wartosc dziesietna temperatury wyjsciowej z czujnika 2
    SdWord ErTemp1_Dec; //wartosc dziesietna uchybu pid 1
    SdWord ErTemp2_Dec; //wartosc dziesietna uchybu pid 2
    SdWord ErLastTemp1_Dec; // wartosc dziesietna uchybu poprzedniego pid 1
    SdWord ErLastTemp2_Dec; // wartosc dziesietna uchybu poprzedniego pid 2
    SdWord ErSumTemp1_Dec; //wartosc dziesietna sumy uchybow pid 1
    SdWord ErSumTemp2_Dec; //wartosc dziesietna sumy uchybow pid 2
    SdWord ErDiffTemp1_Dec; // wartosc dziesietna uchybu czlonu rozniczkujacego pid 1
    SdWord ErDiffTemp2_Dec; // wartosc dziesietna uchybu czlonu rozniczkujacego pid 2
    SdWord IntReg1_Dec; // wartosc dziesietna wartosci czlonu calkujacego pid 1
    SdWord IntReg2_Dec; // wartosc dziesietna wartosci czlonu calkujacego pid 2
    SdWord DiffReg1_Dec; // wartosc dziesietna wartosci czlonu rozniczkujacego pid 1
    SdWord DiffReg2_Dec; // wartosc dziesietna wartosci czlonu rozniczkujacego pid 2
    SdWord PropReg1_Dec; // wartosc dziesietna wartosci czlonu proporcjonalnego pid 1
    SdWord PropReg2_Dec; // wartosc dziesietna wartosci czlonu proporcjonalnego pid 2
    SdWord SumReg1_Dec; // wartos dziesietna wartosci sygnalu sterujacego (wezel sumacyjny poszczegolnych czlonow P, I, D) pid 1
    SdWord SumReg2_Dec; // wartos dziesietna wartosci sygnalu sterujacego (wezel sumacyjny poszczegolnych czlonow P, I, D) pid 2
    SdWord LimitSumReg1_Dec; //wartosc dziesietna  wartosci ograniczonego sygnalu sterujacego pid 1
    SdWord LimitSumReg2_Dec; //wartosc dziesietna  wartosci ograniczonego sygnalu sterujacego pid 2

};
typedef struct tag_exchange_dynamic_decimal_t exchange_dynamic_decimal_t;
extern volatile exchange_dynamic_decimal_t exchange_dynamic_decimal;

// ADC

struct tag_ValueReadADC_t {
    uint8_t iADC1; // zmienna okreslajaca kolejne indeksy w tablicy dla ADC1
    uint8_t iADC2; // zmienna okreslajaca kolejne indeksy w tablicy dla ADC2
    uint8_t iADC3; // zmienna okreslajaca kolejne indeksy w tablicy dla ADC3 
    uint8_t iADC4; // zmienna okreslajaca kolejne indeksy w tablicy dla ADC4
    uint8_t iADC5; // zmienna okreslajaca kolejne indeksy w tablicy dla ADC5
    uint8_t jADC; // Zmienna okreslajaca ile proek ma byc filtrowanych dla ADC
    uint32_t pomiarADC1; // Zmienna niezbedna do odczytu pomiaru z przetwornika ADC1 
    uint32_t pomiarADC2; // Zmienna niezbedna do odczytu pomiaru z przetwornika  ADC2
    uint32_t pomiarADC3; // Zmienna niezbedna do odczytu pomiaru z przetwornika  ADC3
    uint32_t pomiarADC4; // Zmienna niezbedna do odczytu pomiaru z przetwornika  ADC4
    uint32_t pomiarADC5; // Zmienna niezbedna do odczytu pomiaru z przetwornika  ADC5
    uint32_t SumPomADC1; // Zmienna reprezentujaca sume wszystkich pobranych probek z ADC1 
    uint32_t SumPomADC2; // Zmienna reprezentujaca sume wszystkich pobranych probek z ADC2
    uint32_t SumPomADC3; // Zmienna reprezentujaca sume wszystkich pobranych probek z ADC3
    uint32_t SumPomADC4; // Zmienna reprezentujaca sume wszystkich pobranych probek z ADC4
    uint32_t SumPomADC5; // Zmienna reprezentujaca sume wszystkich pobranych probek z ADC5
    uint32_t FiltrpomiarADC1[FILTR_ILE_PROBEK]; // Tablica (bufor), zawierajaca probki ADC1 ( ilosc okresla uzytkownik )
    uint32_t FiltrpomiarADC2[FILTR_ILE_PROBEK]; // Tablica (bufor), zawierajaca probki ADC2 ( ilosc okresla uzytkownik )
    uint32_t FiltrpomiarADC3[FILTR_ILE_PROBEK]; // Tablica (bufor), zawierajaca probki ADC3 ( ilosc okresla uzytkownik )
    uint32_t FiltrpomiarADC4[FILTR_ILE_PROBEK]; // Tablica (bufor), zawierajaca probki ADC4 ( ilosc okresla uzytkownik )
    uint32_t FiltrpomiarADC5[FILTR_ILE_PROBEK]; // Tablica (bufor), zawierajaca probki ADC5 ( ilosc okresla uzytkownik )
};

typedef struct tag_ValueReadADC_t ValueReadADC_t;
extern volatile ValueReadADC_t ValueReadADC;

//PWM

struct tag_PWMData_t {
    uint32_t OC1_Okres; // zmienna okresu dla OC1 
    uint32_t OC2_Okres; // zmienna okresu dla OC2 
    uint32_t OC1_Wypelnienie; // zmienna cyklu pracy generatora dla OC1
    uint32_t OC2_Wypelnienie; // zmienna cyklu pracy generatora dla OC2
};

typedef struct tag_PWMData_t PWMData_t;
extern volatile PWMData_t PWMData;

//TMR1 podliczniki
struct tag_Podlicznik_Bit_t{
    
                UdWord podlicznik_1ms; // zmienna podlicznika dla 1 ms
                UdWord podlicznik_10ms; // zmienna podlicznika dla 10 ms
                UdWord podlicznik_100ms; // zmienna podlicznika dla 100 ms
                UdWord podlicznik_1s; // zmienna podlicznika dla 1 s
                UdWord podlicznik_60s; // zmienna podlicznika dla 60 ms
                UdWord podlicznik_1h; // zmienna podlicznika dla 1 godziny

                UdWord Counter_10ms; // licznik cykli zegara dla 10 ms
                UdWord Counter_100ms; // licznik cykli zegara dla 100 ms
                UdWord Counter_1s; // licznik cykli zegara dla 1 s
                UdWord Counter_60s; // licznik cykli zegara dla 60 s
                UdWord Counter_1h; // licznik cykli zegara dla 1 godziny
    
};

typedef struct tag_Podlicznik_Bit_t Podlicznik_Bit_t;
extern volatile Podlicznik_Bit_t Podlicznik_Bit;


struct tag_Podlicznik_Flag_t{
    
                uByte podlicznik_1ms : 1; // flaga podlicznika dla 1 ms
                uByte podlicznik_10ms : 1; // zmienna podlicznika dla 10 ms
                uByte podlicznik_100ms : 1; // zmienna podlicznika dla 100 ms
                uByte podlicznik_1s : 1; // zmienna podlicznika dla 1 s
                uByte podlicznik_60s : 1; // zmienna podlicznika dla 60 ms
                uByte podlicznik_1h : 1; // zmienna podlicznika dla 1 godziny
    
};

typedef struct tag_Podlicznik_Flag_t Podlicznik_Flag_t;
extern volatile Podlicznik_Flag_t Podlicznik_Flag;


// TMR1 flagi licznikow

struct tag_F1TimerRT_t {
    uint8_t TimerFlag_1ms; // flaga timera 1 ms
    uint8_t TimerFlag_10ms; // flaga timera 10ms
    uint8_t TimerFlag_100ms; // flaga timera 100ms
    uint8_t TimerFlag_1s; // flaga timera 1s
    uint8_t TimerFlag_60s; // flaga timera 60s
    uint8_t TimerFlag_1h; // flaga timera 1h
    uint32_t CountMainLoop; // zmienna licznika petli glownej
    uint32_t OpPer1s; // zmienna licznika petli glownej dla 1 sekundy
};

typedef struct tag_F1TimerRT_t F1TimerRT_t;
extern volatile F1TimerRT_t F1TimerRT;

// zmienne ADC

struct tag_AnalogData_t {
    int32_t TEMP_SENS_1; // pomiar temperatury czujnik 1 (UNI)
    int32_t TEMP_SENS_2; // pomiar temperatury czujnik 2 (LevelInpic)
    int32_t VDC; // pomiar napiecia zasilajacego (VDC)
    int32_t Current3; // pomiar pradu grzalki 1 (CurrVN3)
    int32_t Current4; // pomiar pradu grzalki 2 (CurrVN4)
};

typedef struct tag_AnalogData_t AnalogData_t;
extern volatile AnalogData_t AnalogData;

// Zmienne wspoczynnikow wielomianu

struct tag_CoeffPolynominal_t {
    int32_t A6; // zmienna A6 wspolczynnika wielomianu 6'ego stopnia
    int32_t A5; // zmienna A5 wspolczynnika wielomianu 6'ego stopnia
    int32_t A4; // zmienna A4 wspolczynnika wielomianu 6'ego stopnia
    int32_t A3; // zmienna A3 wspolczynnika wielomianu 6'ego stopnia
    int32_t A2; // zmienna A2 wspolczynnika wielomianu 6'ego stopnia
    int32_t A1; // zmienna A1 wspolczynnika wielomianu 6'ego stopnia
    int32_t A0; // zmienna A0 wspolczynnika wielomianu 6'ego stopnia
};

typedef struct tag_CoeffPolynominal_t CoeffPolynominal_t;
extern volatile CoeffPolynominal_t CoeffPolynominal;

// UART

struct tag_zmienneUART_t {
    uint8_t k; // zmienna uzywana w petli for funkcji (UART_Read)
    uint8_t OdebranoZnak; // flaga odbioru znaku
    uint8_t OdebranoZnak1; // flaga odbioru znaku 
    uint8_t OdebranoZnak2;
    uint8_t OdebraneSlowo; // flaga odbioru slowa (UART_Read)
    uint8_t IloscBajtow; // zmienna ilosci bajtow (UART_Write)
    uint8_t IloscBajtowWysylanych; // zmienna ilosci bajtow wysylanych (UART_Write)
    uint8_t DlugoscBufforaZapisu; // zmienna dlugosci bufora odczytu (UART_Write)
    int8_t wybor; // flaga wyboru
    uint8_t flaga : 1; // nie wykorzystana
    uint8_t FlagaBledu : 1;
    int32_t Dane_Ch; // flaga zmiany nastaw UART   
    uint32_t Dane_Er; // flaga bledow czujnikow
    uint8_t wybor1;
};

typedef struct tag_zmienneUART_t zmienneUART_t;
extern volatile zmienneUART_t zmienneUART;

/* struktura tekstowa */
struct tag_tekst_t {
    char *string; // zmienna string - "Ktora nastawe chcesz zmienic - wybierz jedna cyfre z dostepnych\n"
};

typedef struct tag_tekst_t tekst_t;
extern volatile tekst_t tekst;

struct tag_TWizD_Flag_Bit_t {
    uByte OutHeat1 : 1; // stan wyjscia grzalki 1
    uByte OutHeat2 : 1; // stan wyjscia grzalki 2 
};

typedef struct tag_TWizD_Flag_Bit_t TWizD_Flag_Bit_t;
extern volatile TWizD_Flag_Bit_t WizD_Flag_Bit;

struct tag_TWizD_Error_Bit_t {
    uWord VdcErrorLow : 1; // blad zasilania niskiego napiecia
    uWord VdcErrorHigh : 1; // blad zasilania wysokiego napiecia
    uWord Heat1ErrorOut : 1; // blad wyjscia grzalki 1
    uWord Heat2ErrorOut : 1; // blad zasilania grzalki 2
    uWord Heat1ErrorOverload : 1; // blad wyjscia grzalki 1 -> przeciazenie lub zwarcie
    uWord Heat2ErrorOverload : 1; // blad wyjscia grzalki 2 -> przeciazenie lub zwarcie
    uWord TempSens1ErrorMax : 1; // blad czujnika temp 1 - przekroczenie temp maks lub zwarcie
    uWord TempSens1ErrorMin : 1; // blad czujnika temp 1 - przekroczenie temp min lub odlacozny
    uWord TempSens2ErrorMax : 1; // blad czujnika temp 2 - przekroczenie temp maks lub zwarcie
    uWord TempSens2ErrorMin : 1; // blad czujnika temp 2 - przekroczenie temp min lub odlaczony  
    uWord WarningHeat1 :1; // ostrze?enie o braku podlaczenia grzalki 1
    uWord WarningHeat2 :1; // ostrze?enie o braku podlaczenia grzalki 2
};


typedef struct tag_TWizD_Error_Bit_t TWizD_Error_Bit_t;
extern volatile TWizD_Error_Bit_t WizD_Error_Bit;

struct tag_ErVar_t {
    uWord TimerNoDataSensor; // czas braku danych analogowych
    uWord TimerOverloadHeat1Er; // czas przekroczenia pradu grzalki 1
    uWord TimerOverloadHeat2Er; // czas przekroczenia pradu grzalki 2

    uWord TimerVdc;
    uWord TimerTempSens1;
    uWord TimerTempSens2;
    uWord TimerHeatEr;
    uWord TimerWarningHeat;
    uWord TimerOverloadHeatEr;
};

typedef struct tag_ErVar_t ErVar_t;
extern volatile ErVar_t ErVar;

#endif	/* EXCHANGE_H */