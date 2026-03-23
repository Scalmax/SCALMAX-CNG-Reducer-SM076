/**

 * FIRMA: 
 * SCALMAX Pawel Poplawski
 
 * PLIK:
 * errors.h
 
 * OPIS:
 * plik nag?ówkowy errors zawiera deklaracje funkcji sprawdzajacych bledy czujnikow 
 License: MIT | SPDX-License-Identifier: MIT
 */
#ifndef ERRORS_H
#define	ERRORS_H

#include <xc.h> // include processor files - each processor file is guarded.  

void CheckSensorErrorsON(void);
void CheckSensorErrorsOFF (void);

#endif	/* ERRORS_H */