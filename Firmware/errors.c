/**

 * FIRMA: 
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * errors.c
 
 * OPIS:
 * plik errors zawiera funkcje sprawdzajaca bledy czujnikow 
 License: MIT | SPDX-License-Identifier: MIT
 */

#include <stdbool.h>
#include <stdlib.h>
#include "xc.h"
#include "errors.h"
#include "TypyZmiennych.h"
#include "definicje.h"
#include "exchange.h"

/* Funkcja odpowiedzialna za sprawdzenie bledow czujnikow*/
void CheckSensorErrorsON(void) {

    //napiecie zasilania musi byc w granicach: 10 -> 32 V, jesli nie jest nalezy wylaczyc i zglosic blad

    static const uWord ConstVdcT = 900; // 900 ms niskiego napiecia i wlacza sie blad
    static const sWord ConstTempSensMax = 140; // maksymalna temp  czujnika (odczyt ADCBUF) - 140*C           //////////// 96
    static const sWord ConstTempSensMin = -20; // minimalna temp czujnika (odczyt ADCBUF) - (-20)*C)       /////////////// 4000
    static const uWord ConstTempSens1T = 900; // 900ms min/maks temp czujnika zanim wyrzuci blad
    static const uWord ConstTempSens2T = 900; // 900ms min/maks temp czujnika zanim wyrzuci blad
    static const sWord ConstVdcLow = ((10.0 / 7.784) / STALA_V); // minimalne napiecie zasilania - 10V
    static const sWord ConstVdcHigh = ((32.0 / 7.784) / STALA_V); // maksymalne napiecie zasilnania - 32 V
    static const uWord ConstTimerHeatEr = 500; // 500ms roznic w pinach skutkuje bledem
    static const uWord ConstTimerOverloadHeatEr = 750; // czas przekroczenia overload grzalki 1 (750ms)
    static const uWord ConstTimerWarningHeat = 400; // 400ms na wykrycie braku podlaczenia grzalki 1
    static const sWord MaxCurrent = ((5.0 * STALA_V_TO_DEC) * RSENSE) / I_OUT_TO_I_SENSE; // max 5.0 A to przeciazenie
    static const sWord MinCurrent = ((0.05 * STALA_V_TO_DEC) * RSENSE) / I_OUT_TO_I_SENSE; // 50 mA minimalny prad -> sluzy do wykrycia pracy grzalki

    /* bledy zasilania */
    if ((exchange_dynamic.VDC <= ConstVdcLow) || (exchange_dynamic.VDC >= ConstVdcHigh)) { // jezeli odczytane napiecie jest mniejsze od 10 lub wieksze od 32 V
        if (++ErVar.TimerVdc <= ConstVdcT) { // i stan ten trwa ponizej 900 ms 
            WizD_Error_Bit.VdcErrorLow = false; // flaga bledu zbyt niskiego napiecia  = 0 - brak bledu
            WizD_Error_Bit.VdcErrorHigh = false; // flaga bledu zbyt wysokiego napiecia = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 900 ms 
            if (exchange_dynamic.VDC <= ConstVdcLow) { // i jezeli VDC < od 10 V, to
                WizD_Error_Bit.VdcErrorLow = true; // // flaga bledu zbyt niskiego napiecia  = 1 - zgloszenie bledu
            }
            if (exchange_dynamic.VDC >= ConstVdcHigh) { // jezeli VDC wieksze od 32 V
                WizD_Error_Bit.VdcErrorHigh = true; // flaga bledu zbyt wysokiego napiecia = 0 - zgloszenie bledu

            }
        }
    } else { // jezeli odczytane napiecie wynosi od 10 do 32 V, to
        WizD_Error_Bit.VdcErrorLow = false; // flaga bledu zbyt niskiego napiecia  = 0 - brak bledu
        WizD_Error_Bit.VdcErrorHigh = false; // flaga bledu zbyt wysokiego napiecia = 0 - brak bledu
        ErVar.TimerVdc = 0; // wyzeruj licznik czasu wystapienia bledow zasilania
    }

    /* bledy temp czujnika 1 */
    if ((exchange_dynamic_decimal.CurrTemp1_Dec >= ConstTempSensMax) || (exchange_dynamic_decimal.CurrTemp1_Dec <= ConstTempSensMin)) {
    //if ((AnalogData.TEMP_SENS_1 <= ConstTempSensMax) || (AnalogData.TEMP_SENS_1 >= ConstTempSensMin)) { // jezeli odczytana temp czujnika 1 jest < min temp czujnika 1 lub > maks temp czujnika
        if (++ErVar.TimerTempSens1 <= ConstTempSens1T) { // i stan ten trwa ponizej 900 ms 
            WizD_Error_Bit.TempSens1ErrorMax = false; // flaga bledu zbyt wysokiej temp czujnika 1  = 0 - brak bledu
            WizD_Error_Bit.TempSens1ErrorMin = false; // flaga bledu zbyt niskiej temp czujnika 1  = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 900 ms 
            if (exchange_dynamic_decimal.CurrTemp1_Dec >= ConstTempSensMax) { // i jezeli odczytana temp czujnika 1 > maks temp czujnika 1
                WizD_Error_Bit.TempSens1ErrorMax = true; // flaga bledu zbyt wysokiej temp czujnika 1  = 1 - zgloszenie bledu
            }
            if (exchange_dynamic_decimal.CurrTemp1_Dec <= ConstTempSensMin) { // jezeli odczytana temp czujnika 1 < min temp czujnika 1
                WizD_Error_Bit.TempSens1ErrorMin = true; // flaga bledu zbyt niskiej temp czujnika 1  = 1 - zgloszenie bledu

            }
        }
    } else { // jezeli odczytana temp miesci sie w wyznaczonym przedziale
        WizD_Error_Bit.TempSens1ErrorMax = false; // flaga bledu zbyt wysokiej temp czujnika 1  = 0 - brak bledu
        WizD_Error_Bit.TempSens1ErrorMin = false; // flaga bledu zbyt niskiej temp czujnika 1  = 0 - brak bledu
        ErVar.TimerTempSens1 = 0; // wyzeruj licznik czasu wystapienia bledow 1 czujnika temp 
    }

    /* bledy temp czujnika 2 */
    if ((exchange_dynamic_decimal.CurrTemp2_Dec >= ConstTempSensMax) || (exchange_dynamic_decimal.CurrTemp2_Dec <= ConstTempSensMin)) {
    //if ((AnalogData.TEMP_SENS_2 <= ConstTempSensMax) || (AnalogData.TEMP_SENS_2 >= ConstTempSensMin)) { // jezeli odczytana temp czujnika 2 jest < min temp czujnika 2 lub > maks temp czujnika 2
        if (++ErVar.TimerTempSens2 <= ConstTempSens2T) { // i stan ten trwa ponizej 900 ms 
            WizD_Error_Bit.TempSens2ErrorMax = false; // flaga bledu zbyt wysokiej temp czujnika 2  = 0 - brak bledu
            WizD_Error_Bit.TempSens2ErrorMin = false; // flaga bledu zbyt niskiej temp czujnika 2  = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 900 ms 
            if (exchange_dynamic_decimal.CurrTemp2_Dec >= ConstTempSensMax) { // i jezeli odczytana temp czujnika 2 > maks temp czujnika 2
                WizD_Error_Bit.TempSens2ErrorMax = true; // flaga bledu zbyt wysokiej temp czujnika 2  = 1 - zgloszenie bledu
            }
            if (exchange_dynamic_decimal.CurrTemp2_Dec <= ConstTempSensMin) { // jezeli odczytana temp czujnika 2 < min temp czujnika 2
                WizD_Error_Bit.TempSens2ErrorMin = true; // flaga bledu zbyt niskiej temp czujnika 2  = 1 - zgloszenie bledu

            }
        }
    } else { // jezeli odczytana temp miesci sie w wyznaczonym przedziale
        WizD_Error_Bit.TempSens2ErrorMax = false; // flaga bledu zbyt wysokiej temp czujnika 2  = 0 - brak bledu
        WizD_Error_Bit.TempSens2ErrorMin = false; // flaga bledu zbyt niskiej temp czujnika 2  = 0 - brak bledu
        ErVar.TimerTempSens2 = 0; // wyzeruj licznik czasu wystapienia bledow 2 czujnika temp 
    }

    /* bledy wyjsc grzalek */
    if ((HEATER_1 != GIN_HEATER_1) || (HEATER_2 != GIN_HEATER_2)) { // jezeli stan wyjscia != stanowi sterowania grzalki 1 lub grzalki 2
        if (++ErVar.TimerHeatEr <= ConstTimerHeatEr) { // i stan ten trwa ponizej 500 ms 
            WizD_Error_Bit.Heat1ErrorOut = false; // flaga bledu wyjscia grzalki 1 = 0 - brak bledu
            WizD_Error_Bit.Heat2ErrorOut = false; // flaga bledu wyjscia grzalki 2 = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 500 ms 
            if (HEATER_1 != GIN_HEATER_1) { // jezeli stan wyjscia != stanowi sterowania grzalki 1
                WizD_Error_Bit.Heat1ErrorOut = true; // flaga bledu wyjscia grzalki 1 = 1 - zgloszenie bledu
            }
            if (HEATER_2 != GIN_HEATER_2) { // jezeli stan wyjscia != stanowi sterowania grzalki 2
                WizD_Error_Bit.Heat2ErrorOut = true; // flaga bledu wyjscia grzalki 2 = 1 - zgloszenie bledu

            }
        }
    } else { // jezeli stan wyjscia = stanowi sterowania
        WizD_Error_Bit.Heat1ErrorOut = false; // flaga bledu wyjscia grzalki 1 = 0 - brak bledu
        WizD_Error_Bit.Heat2ErrorOut = false; // flaga bledu wyjscia grzalki 2 = 0 - brak bledu
        ErVar.TimerHeatEr = 0; // wyzeruj licznik czasu wystapienia bledow wyjsc grzalek
    }

    /* blad zbyt niskiego pradu grzalek */
    if ((exchange_dynamic.Current3 <= MinCurrent) || (exchange_dynamic.Current4 <= MinCurrent)) { // jezeli odczytany prad grzalki 1 lub grzalki 2 < od min pradu grzalek
        if (++ErVar.TimerWarningHeat <= ConstTimerWarningHeat) { // i stan ten trwa ponizej 400 ms
            WizD_Error_Bit.WarningHeat1 = false; // flaga bledu zbyt niskiego pradu grzalki 1 = 0 - brak bledu
            WizD_Error_Bit.WarningHeat2 = false; // flaga bledu zbyt niskiego pradu grzalki 2 = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 400 ms
            if (exchange_dynamic.Current3 <= MinCurrent) { // jezeli odczytany prad grzalki 1 < min pradu grzalki 1
                WizD_Error_Bit.WarningHeat1 = true; // flaga bledu zbyt niskiego pradu grzalki 2 = 1 - zgloszenie bledu
            }
            if (exchange_dynamic.Current4 <= MinCurrent) { // jezeli odczytany prad grzalki 2 < min pradu grzalki 2
                WizD_Error_Bit.WarningHeat2 = true; // flaga bledu zbyt niskiego pradu grzalki 2 = 1 - zgloszenie bledu

            }
        }
    } else { // jezeli odczytany prad grzalek jest > min prad grzalek
        WizD_Error_Bit.WarningHeat1 = false; // flaga bledu zbyt niskiego pradu grzalki 1 = 0 - brak bledu
        WizD_Error_Bit.WarningHeat2 = false; // flaga bledu zbyt niskiego pradu grzalki 2 = 0 - brak bledu
        ErVar.TimerWarningHeat = 0; // wyzeruj licznik czasu wystapienia bledow zbyt niskiego pradu grzalek
    }

    /* blad przeciazenia grzalek */
    if ((exchange_dynamic.Current3 >= MaxCurrent) || (exchange_dynamic.Current4 >= MaxCurrent)) { // jezeli odczytany prad grzalki 1 lub grzalki 2 > od maks pradu grzalek
        if (++ErVar.TimerOverloadHeatEr <= ConstTimerOverloadHeatEr) { // i stan ten trwa ponizej 400 ms
            WizD_Error_Bit.Heat1ErrorOverload = false; // flaga bledu zbyt wysokiego pradu grzalki 1 = 0 - brak bledu
            WizD_Error_Bit.Heat2ErrorOverload = false; // flaga bledu zbyt wysokiego pradu grzalki 1 = 0 - brak bledu
        } else { // jezeli stan ten trwa powyzej 400 ms
            if (exchange_dynamic.Current3 >= MaxCurrent) { // jezeli odczytany prad grzalki 1 > maks pradu grzalki 1
                WizD_Error_Bit.Heat1ErrorOverload = true; // flaga bledu zbyt wysokiego pradu grzalki 1 = 1 - zgloszenie bledu
            }
            if (exchange_dynamic.Current4 >= MaxCurrent) { // jezeli odczytany prad grzalki 2 > maks pradu grzalki 1
                WizD_Error_Bit.Heat2ErrorOverload = true; // flaga bledu zbyt wysokiego pradu grzalki 2 = 1 - zgloszenie bledu

            }
        }
    } else { // jezeli odczytany prad grzalek jest < maks prad grzalek
        WizD_Error_Bit.Heat1ErrorOverload = false; // flaga bledu zbyt wysokiego pradu grzalki 1 = 0 - brak bledu
        WizD_Error_Bit.Heat2ErrorOverload = false; // flaga bledu zbyt wysokiego pradu grzalki 2 = 0 - brak bledu
        ErVar.TimerOverloadHeatEr = 0; // wyzeruj licznik czasu wystapienia bledow zbyt wysokiego pradu grzalek
    }
}

/* brak stacyjki */
void CheckSensorErrorsOFF(void) {

    WizD_Error_Bit.WarningHeat1 = 0;
    WizD_Error_Bit.WarningHeat2 = 0;
    WizD_Error_Bit.Heat1ErrorOut = 0;
    WizD_Error_Bit.Heat1ErrorOverload = 0;
    WizD_Error_Bit.Heat2ErrorOut = 0;
    WizD_Error_Bit.Heat2ErrorOverload = 0;
    WizD_Error_Bit.TempSens1ErrorMax = 0;
    WizD_Error_Bit.TempSens1ErrorMin = 0;
    WizD_Error_Bit.TempSens2ErrorMax = 0;
    WizD_Error_Bit.TempSens2ErrorMin = 0;
    WizD_Error_Bit.VdcErrorHigh = 0;
    WizD_Error_Bit.VdcErrorLow = 0;
    ErVar.TimerVdc = 0; // czas za niskiego/wysokiego napiecia zasilania
    ErVar.TimerTempSens1 = 0; // czas wyst?powania b??dów czujnika temperatury numer 1
    ErVar.TimerTempSens2 = 0; // czas wyst?powania b??dów czujnika temperatury numer 2  
    ErVar.TimerHeatEr = 0; // czas wystepowania bledu grzalek 
    ErVar.TimerWarningHeat; // czas zbyt niskiego pradu grza?ek
    ErVar.TimerOverloadHeat1Er = 0; // czas przekroczenia pradu grzalki numer 1
    ErVar.TimerOverloadHeat2Er = 0; // czas przekroczenia pradu grzalki numer 2
}