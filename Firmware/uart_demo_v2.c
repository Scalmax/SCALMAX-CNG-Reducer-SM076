/**
 
 * FIRMA:
 * SCALMAX Pawel Poplawski

 * PLIK:
 * uart_demo_v2.c
 
 * OPIS:
 * plik uart_demo zawiera funkcje wykorzystywane do zapewnienia komunikacji 
 * w formie asynchronicznego przekazu i odbioru danych za posrednictwem portu 
 * szeregowego 
License: MIT | SPDX-License-Identifier: MIT
 */


#include "./mcc_generated_files/drivers/uart.h"
#include "uart_demo_v2.h"
#include "exchange.h"
#include "fixed_t.h"
#include "mcc_generated_files/uart1.h"
#include "TimeTick.h"
#include "mcc_generated_files/tmr1.h"
#include "obs_timerow.h"
#include "definicje.h"
#include "printf.h"
#include "mcc_generated_files/system_types.h"

static char Re_Buff[RECEIVE_TABLE_SIZE]; // Bufor odczytu
uint8_t Wr_Buff[TRANSMIT_TABLE_SIZE]; // Bufor zapisu

/* Funkcja odpowiadajaca za odczyt wprowadzonych danych */
void UART_Read(void) {

    // Poczekaj az dane beda gotowe 
    while (UART1_IsRxReady() == 0) {
        break;
    }

    for (zmienneUART.k = 0; zmienneUART.k < sizeof (Re_Buff); zmienneUART.k++) {
        Re_Buff[zmienneUART.k] = uart[UART0].Read();
        // Blokada az do momentu dostepnosci
        if (Re_Buff[zmienneUART.k] == '\n') // jezeli odczyta ENTER
        {
            zmienneUART.OdebraneSlowo = zmienneUART.k;
            break;
        }
    }
}

/* Funkcja odpowiadajaca za transmisje */
void UART_Write(char *tekst) {

    // kiedy ilosc bajtow jest mniejsza od dlugosci wpisanego tekstu
    while (zmienneUART.IloscBajtow < strlen(tekst)) {
        // wpisz do UART1 podany tekst po 1 bajcie
        uart[UART0].Write(tekst[zmienneUART.IloscBajtow]);
        // zwieksz ilosc bajtow o 1 wraz z kazdym kolejnym wykonaniem petli
        zmienneUART.IloscBajtow++;
    }
    // jezeli ilosc bajtow rowna sie dlugosc tekstu
    if (zmienneUART.IloscBajtow == strlen(tekst)) {
        // ilosc bajtow rowna sie zero
        zmienneUART.IloscBajtow = 0;
    }
}

/* Funkcja odpowiadajaca za konwersje danych typu string char do int */
uint8_t char_to_int(char* txt) {

    uint8_t sum = 0; // zmienna sumy
    uint8_t digit = 0; // zmienna cyfry
    uint8_t i = 0;
    uint8_t decimal = 10;

    for (i = 0; i < strlen(txt); i++) {
        // jezeli txt[i] jest rozne od ENTER i znaku poczatku nowego wiersza
        if ((txt[i] != '\n') && (txt[i] != '\r')) {
            // digit (cyfra) = kazdy kolejny odczytany znak - 48 (0 w ASCII to 48)
            digit = txt[i] - 0x30;
            // suma = poprzednia liczba * 10 + kolejna oczytana cyfra
            sum = (sum * decimal) + digit;
        } else // jezeli nie spelnia warunkow, to nie rob nic
        {
            break;
        }
    }
    return sum; // funkcja zwraca wartosc sumy
}

/* Funkcja odpowiadajaca za mozliwosc wprowadzenia nastaw, odczytania i
 przypisania ich do zmiennych 
 */
void UART_Printf(void) {

    /* Gdy numer zmiennej mniejszy od liczby zmiennych wykonaj instrukcje */
    while (++zmienneUART.Dane_Ch <= LICZBA_ZMIENNYCH) {

        switch (zmienneUART.Dane_Ch) {

            case 1: // wybor regulatora

                tekst.string = "\n\n\n Wybierz jaki regulator chcesz uzyc (0 - PID, 1 - PI): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Odczytaj wpisany znak
                exchange_eeprom.regulator = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while ((exchange_eeprom.regulator < 0) || (exchange_eeprom.regulator > 1)) { // kiedy uzytkownik wpisze zla cyfre

                    tekst.string = "\n Sprobuj jeszcze raz: "; // Wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.regulator = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }

                if (exchange_eeprom.regulator == 0) { // Jezeli uzytkownik wpisze 0

                    tekst.string = " Wybrano regulator PID\n"; // Wyswietl komunikat o wyborze regulatora PID
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                } else { // Jezeli uzytkownik wpisze 1

                    tekst.string = " Wybrano regulator PI\n"; // Wyswietl komunikat o wyborze regulatora PI
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                }
                break; // wyjdz

            case 2: // temperatura zadana

                tekst.string = "\n Podaj temperature zadana (max 120 stopni): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Oczytaj wpisany znak
                exchange_eeprom.target_temp_dec = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while (exchange_eeprom.target_temp_dec > TARGET_TEMP_MAX) { // kiedy uzytkownik wpisze zla liczbe

                    tekst.string = "\n Sprobuj jeszcze raz: "; // Wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.target_temp_dec = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }
                exchange_eeprom.target_temp = fixed16_t_from_int(TARGET_TEMP); // konwersja przypisanej liczby do fixed16_t
                break; // wyjdz

            case 3: // wspolczynnik wzmocnienia KP

                tekst.string = "\n Podaj wspolczynnik wzmocnienia Kp (1 - 10): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Oczytaj wpisany znak
                exchange_eeprom.Kp = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while ((exchange_eeprom.Kp < (MIN_VAL_SET + 1)) || (exchange_eeprom.Kp > MAX_VAL_SET)) { // kiedy uzytkownik wpisze zla liczbe

                    tekst.string = "\n Sprobuj jeszcze raz: "; // Wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.Kp = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }
                break; // wyjdz

            case 4: // wspolczynnik wzmocnienia Ki

                tekst.string = "\n Podaj wspolczynnik wzmocnienia Ki (0 - 10): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Oczytaj wpisany znak
                exchange_eeprom.Ki = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while ((exchange_eeprom.Ki < MIN_VAL_SET) || (exchange_eeprom.Ki > MAX_VAL_SET)) { // kiedy uzytkownik wpisze zla liczbe
                    tekst.string = "\n Sprobuj jeszcze raz: "; // wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.Ki = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }
                break; // wyjdz

            case 5: // wspolczynnik wzmocnienia Kd

                if (exchange_eeprom.regulator == 0) { // jezeli uzytkownik wybral regulator PID
                    tekst.string = "\n Podaj wspolczynnik wzmocnienia Kd (0 - 10): "; // Wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Oczytaj wpisany znak
                    exchange_eeprom.Kd = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                    while ((exchange_eeprom.Kd < MIN_VAL_SET) || (exchange_eeprom.Kd > MAX_VAL_SET)) { // kiedy uzytkownik wpisze zla liczbe
                        tekst.string = "\n Sprobuj jeszcze raz: "; // Wyswietl polecenie
                        UART_Write(tekst.string); // wpisz tekst do zmiennej
                        UART_Read(); // Ponownie odczytaj znak
                        exchange_eeprom.Kd = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                    }
                } else { // Jezeli uzytkownik wybral regulator PI, to wyjdz
                    break;
                }
                break; // wyjdz

            case 6: // wartosc minimalna sygnalu sterowania

                tekst.string = "\n Podaj wartosc minimalna sygnalu sterowania (0 - 100): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Oczytaj wpisany znak
                exchange_eeprom.Min_Val_a = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while ((exchange_eeprom.Min_Val_a < MIN_VAL_UART) || (exchange_eeprom.Min_Val_a > (MAX_VAL_UART / 2))) { // kiedy uzytkownik wpisze zla liczbe
                    tekst.string = "\n Sprobuj jeszcze raz: "; // wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.Min_Val_a = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }
                break; // wyjdz

            case 7: // dla licznika rownego 7

                tekst.string = "\n Podaj wartosc maksymalna sygnalu sterowania(0 - 200): "; // Wyswietl polecenie
                UART_Write(tekst.string); // wpisz tekst do zmiennej
                UART_Read(); // Oczytaj wpisany znak
                exchange_eeprom.Max_Val_a = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej

                while ((exchange_eeprom.Max_Val_a < MIN_VAL_UART) || (exchange_eeprom.Max_Val_a > MAX_VAL_UART)) { // kiedy uzytkownik wpisze zla liczbe
                    tekst.string = "\n Sprobuj jeszcze raz: "; // Wyswietl polecenie
                    UART_Write(tekst.string); // wpisz tekst do zmiennej
                    UART_Read(); // Ponownie odczytaj znak
                    exchange_eeprom.Max_Val_a = char_to_int(Re_Buff); // dokonaj konwersji char na int i  przypisz znak do zmiennej
                }
                break; // wyjdz

                // Jezeli numer zmiennej > liczby_zmiennych to wyjdz
            default:
                break; // wyjdz
        }

        if (zmienneUART.OdebranoZnak == true) { // Jezeli flaga = true , to zmien stan flagi na false
            zmienneUART.OdebranoZnak = false; /// wyzeruj flage Odebranoznak
            zmienneUART.Dane_Ch = LICZBA_ZMIENNYCH + 1; // 
        }
    }
}

/* Funkcja odpowiadajaca za wyswietlenie danych diagnostycznych */
void UART_Receive_Data(void) {

    /* Funkcja odpowiadajaca za konwersje wartosci danych z fixed16_t do int */
    Konwersja_Danych_FixedToInt();

    // Jezeli uzytkownik wybral regulator PID, to:
    if (exchange_eeprom.regulator == 0) {

        Print_Reg_PID_Sens_Together(); // Wyswietl dane diagnostyczne obu czujnikow - PID
    }// Jezeli uzytkownik wybral regulator PI, to:
    else {

        Print_Reg_PI_Sens_Together(); // Wyswietl dane diagnostyczne obu czujnikow - PI
    }
}

/* Funkcja wyboru czynnosci UART */
void UART_WyborDzialania(void) {

    // Jezeli dane sa gotowe
    while (UART1_IsRxReady()) {

        for (zmienneUART.k = 0; zmienneUART.k < sizeof (Re_Buff); zmienneUART.k++) {
            Re_Buff[zmienneUART.k] = uart[UART0].Read();

            // Blokada az do momentu dostepnosci
            if (Re_Buff[zmienneUART.k] == '\n') // Jezeli odebebrany zostanie ENTER
            {

                tekst.string = "\n\n\nWybierz co chcesz zrobic: \n" // wpisz tekst do zmiennej
                        "\n 0 - Zmien nastawy regulatora\n"
                        "\n 1 - Sprawdz bledy czujnikow\n"
                        "\n 2 - Powrot - wyswietl dane diagnostyczne\n\n";

                UART_Write(tekst.string); // Wyswietl wpisany tekst
                UART_Read(); // Odczytaj znak
                zmienneUART.wybor = char_to_int(Re_Buff); // Przypisz wpisana liczbe do zmiennej

                while ((zmienneUART.wybor < 0) || (zmienneUART.wybor > 2)) { // jezeli wybrane dane nie mieszcza sie w przedziale

                    tekst.string = "\n\n\nSprobuj jeszcze raz: \n\n" // wpisz tekst do zmiennej
                            "\nWybierz co chcesz zrobic: \n"
                            "\n 0 - Zmien nastawy regulatora\n"
                            "\n 1 - Sprawdz bledy czujnikow\n"
                            "\n 2 - Powrot\n\n";
                    UART_Write(tekst.string); // Wyswietl wpisany tekst
                    UART_Read(); // odczytaj znak
                    zmienneUART.wybor = char_to_int(Re_Buff); // Przypisz wpisana liczbe do zmiennej
                }

                if (zmienneUART.wybor == 0) {

                    zmienneUART.Dane_Ch = 0; // wyzeruj flage Dane_Ch
                    tekst.string = "\n\nCo chcesz zrobic? - wybierz jedna cyfre z dostepnych\n" // wpisz tekst do zmiennej
                            "\n 0 - Zmiana typu regulatora"
                            "\n 1 - Zmiana temperatury zadanej"
                            "\n 2 - Zmiana wartosci wspolczynnika Kp"
                            "\n 3 - Zmiana wartosci wspolczynnika Ki";
                    UART_Write(tekst.string); // Wyswietl wpisany tekst

                    if (exchange_eeprom.regulator == 0) { // Jezeli uzytkownik wybral regulator PID

                        tekst.string = "\n 4 - Zmiana wartosci wspolczynnika Kd"; // wpisz tekst do zmiennej
                        UART_Write(tekst.string); // Wyswietl wpisany tekst
                    }

                    tekst.string = "\n 5 - Zmiana wartosci minimalnej sygnalu sterowania regulatora" // wpisz tekst do zmiennej
                            "\n 6 - Zmiana wartosci maksymalnej sygnalu sterowania regulatora"
                            "\n 7 - Powrot\n\n";
                    UART_Write(tekst.string); // Wyswietl wpisany tekst
                    UART_Read(); // Odczytaj znak
                    zmienneUART.Dane_Ch = char_to_int(Re_Buff); // Przypisz wpisana liczbe do zmiennej

                    while ((zmienneUART.Dane_Ch < 0) || (zmienneUART.Dane_Ch > 7)) {

                        tekst.string = "\n\n\nCo chcesz zrobic? - wybierz jedna cyfre z dostepnych\n" // wpisz tekst do zmiennej
                                "\n 0 - Zmiana typu regulatora"
                                "\n 1 - Zmiana temperatury zadanej"
                                "\n 2 - Zmiana wartosci wspolczynnika Kp"
                                "\n 3 - Zmiana wartosci wspolczynnika Ki";
                        UART_Write(tekst.string); // Wyswietl wpisany tekst

                        if (exchange_eeprom.regulator == 0) { // Jezeli uzytkownik wybral regulator PID

                            tekst.string = "\n 4 - Zmiana wartosci wspolczynnika Kd"; // wpisz tekst do zmiennej
                            UART_Write(tekst.string); // Wyswietl wpisany tekst
                        }

                        tekst.string = "\n 5 - Zmiana wartosci minimalnej sygnalu sterowania regulatora" // wpisz tekst do zmiennej
                                "\n 6 - Zmiana wartosci maksymalnej sygnalu sterowania regulatora"
                                "\n 7 - Powrot\n\n";
                        UART_Write(tekst.string); // Wyswietl wpisany tekst
                        UART_Read(); // odczytaj znak
                        zmienneUART.Dane_Ch = char_to_int(Re_Buff); // Przypisz wpisana liczbe do zmiennej
                    }

                    zmienneUART.OdebranoZnak = true; // Ustaw flage odebrania znaku na 1
                    break; // wyjdz
                }

                if (zmienneUART.wybor == 1) { // jezeli wybor = 1

                    zmienneUART.OdebranoZnak1 = true; // Ustaw flage odebrania znaku na 1
                    break; // wyjdz
                }

                if (zmienneUART.wybor == 2) { // jezeli wybor = 2
                    break; // wyjdz
                }
            }
        }
    }
}

/* Funkcja odpowiadajaca za odczyt bledow z czujnikow */
void UART_OdczytBledow(void) {

    if (zmienneUART.OdebranoZnak1 == true) {

        zmienneUART.FlagaBledu = true;


        // sprawdzanie wszystkich bledow poniewaz zgodnie ze standardem MISRA - C:2012 
        // nie nalezy stosowac "UNII" (union{})..
        if ((WizD_Error_Bit.Heat1ErrorOut == false)
                && (WizD_Error_Bit.Heat1ErrorOverload == false)
                && (WizD_Error_Bit.Heat2ErrorOut == false)
                && (WizD_Error_Bit.Heat2ErrorOverload == false)
                && (WizD_Error_Bit.TempSens1ErrorMax == false)
                && (WizD_Error_Bit.TempSens1ErrorMin == false)
                && (WizD_Error_Bit.TempSens2ErrorMax == false)
                && (WizD_Error_Bit.TempSens2ErrorMin == false)
                && (WizD_Error_Bit.VdcErrorHigh == false)
                && (WizD_Error_Bit.VdcErrorLow == false)
                && (WizD_Error_Bit.WarningHeat1 == false)
                && (WizD_Error_Bit.WarningHeat2 == false)) {

            tekst.string = "\n\n BRAK BLEDOW\n"; // wpisz tekst do zmiennej
            UART_Write(tekst.string); // wyswietl wpisany tekst

        } else {
            // bledy zasilania
            if (WizD_Error_Bit.VdcErrorLow == true) {// jezeli flaga bledu zbyt niskiego napiecia = 1,to
                tekst.string = "\n\n BLAD 01 - zbyt niskie napiecie zasilania\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // Wyswietl wpisany tekst

            }
            if (WizD_Error_Bit.VdcErrorHigh == true) { // jezeli flaga bledu zbyt wysokiego napiecia = 1,to
                tekst.string = "\n\n BLAD 02 - zbyt wysokie napiecie zasilania\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst
            }
            // bledy 1 czujnika temp
            if (WizD_Error_Bit.TempSens1ErrorMin == true) { // jezeli flaga bledu zbyt niskiej temp na czujniku 1 = 1, to
                tekst.string = "\n\n BLAD 03 - blad czujnika temp 1 - przekroczenie temp minimalnej lub odlaczenie\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }
            if (WizD_Error_Bit.TempSens1ErrorMax == true) { // jezeli flaga bledu zbyt wysokiej temp na czujniku 1 = 1, to
                tekst.string = "\n\n BLAD 04 - blad czujnika temp 1 - przekroczenie temp maksymalnej lub zwarcie\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst
            }
            // bledy 2 czujnika temp
            if (WizD_Error_Bit.TempSens2ErrorMin == true) { // jezeli flaga bledu zbyt niskiej temp na czujniku 2 = 1, to
                tekst.string = "\n\n BLAD 05 - blad czujnika temp 2 - przekroczenie temp minimalnej lub odlaczenie\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }
            if (WizD_Error_Bit.TempSens2ErrorMax == true) { // jezeli flaga bledu zbyt wysokiej temp na czujniku 2 = 1, to
                tekst.string = "\n\n BLAD 06 - blad czujnika temp 2 - przekroczenie temp maksymalnej lub zwarcie\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst
            }

            // bledy 1 grzalki
            if (WizD_Error_Bit.Heat1ErrorOut == true) { // jezeli flaga bledu wyjscia grzalki 1 = 1, to
                tekst.string = "\n\n BLAD 07 - blad wyjscia grzalki 1\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }
            if (WizD_Error_Bit.Heat1ErrorOverload == true) { // jezeli flaga bledu przeciazenia grzalki 1 = 1, to
                tekst.string = "\n\n BLAD 08 - przekroczony prad grzalki 1\n"; // wpisz tekst do zmniennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }
            if (WizD_Error_Bit.WarningHeat1 == true) { // jezeli flaga bledu zbyt niskiego pradu na grzalce 1 = 1, to
                tekst.string = "\n\n BLAD 09 - zbyt niski prad na grzalce 1\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisaney tekst

            }
            if (WizD_Error_Bit.WarningHeat2 == true) { // jezeli flaga bledu zbyt niskiego pradu na grzalce 2 = 1, to
                tekst.string = "\n\n BLAD 12 - zbyt niski prad na grzalce 2\n"; // wpisz tekst do zmniennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }

            // bledy 2 grzalki
            if (WizD_Error_Bit.Heat2ErrorOut == true) { // jezeli flaga bledu wyjscia grzalki 2 = 1, to
                tekst.string = "\n\n BLAD 10 - blad wyjscia grzalki 2\n"; // wpisz tekst do zmiennej
                UART_Write(tekst.string); // wyswietl wpisaney tekst

            }
            if (WizD_Error_Bit.Heat2ErrorOverload == true) { // jezeli flaga bledu przeciazenia grzalki 2 = 1, to
                tekst.string = "\n\n BLAD 11 - przekroczony prad grzalki 2\n"; // wpisz tekst do zmniennej
                UART_Write(tekst.string); // wyswietl wpisany tekst

            }
        }
        zmienneUART.OdebranoZnak1 = false;
        UART_OdczytBledowWybor();
    }
}

// Funkcja odpowiadajaca za wyjscie z funkcji UART_OdczytBledow(); oraz ponowne wyswietlenie danych diagnostycznych

void UART_OdczytBledowWybor(void) {
    // Blokada az do momentu dostepnosci
    while (zmienneUART.FlagaBledu == true) // Jezeli flaga = 1
    {
        tekst.string = "\n\n ENTER - Powrot\n\n"; // wyswietl polecenie
        UART_Write(tekst.string); // wyswietl wpisany tekst
        UART_Read(); // Odczytaj wpisany znak
        zmienneUART.OdebranoZnak2 = char_to_int(Re_Buff); // dokonaj konwersji i przypisz odebrany znak do zmiennej

        if (zmienneUART.OdebranoZnak2 == false) { // jezeli odebrany znak = 0
            zmienneUART.FlagaBledu = false; // wyzeruj flage      
        }
    }
}

