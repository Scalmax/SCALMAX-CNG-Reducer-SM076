[README.MD](https://github.com/user-attachments/files/26193745/README.MD)
#SM076 CNG Reducer Controller - Open Source Project

Kompleksowy system sterowania reduktorem CNG opracowany przez firmę SCALMAX Paweł Popławski.
Projekt obejmuje jednostkę sterującą opartą na mikrokontrolerze dsPIC33EV, dedykowaną wiązkę przewodów oraz dokumentację mechaniczną korpusu.
---
Struktura Projektu (Project Structure)
/Firmware – Kod źródłowy C dla mikrokontrolera Microchip dsPIC33EV128GM106
/Hardware – Schematy ideowe i projekty PCB sterownika (SM076 Reducer Controller)
/Harness  – Dokumentacja techniczna wiązki przewodów (V.3) ze złączem FCI 24-pin oraz wtyczkami Superseal
/Mechanical – Rysunki techniczne (PDF) oraz modele bryłowe (STEP/PAR) korpusu reduktora.
---
Specyfikacja Techniczna (Technical Specification)
Mikrokontroler: dsPIC33EV128GM106
Złącza: Główne złącze FCI 24 Black (J4) oraz wtyczki hermetyczne typu Superseal
Przewody o odporności termicznej od -40°C do +105°C, zabezpieczone bezpiecznikiem 10A
Zasilanie: Układ dostosowany do instalacji 12V z obsługą grzałek o wysokim poborze prądu (przewody 0.75mm² i 1.5mm²)
---
#Licencjonowanie (Licensing)
Projekt jest udostępniany na zasadach Open Source Hardware:
1. Hardware, Harness & Mechanical: CERN-OHL-W v2 Właściciel: SCALMAX Paweł Popławski Link: https://ohwr.org/cernohl
2. Software (Firmware): MIT Copyright (c) 2026 SCALMAX Paweł Popławski, Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files...

Pełna dokumentacja jest własnością:
SCALMAX Paweł Popławski
ul. Polska 2, 15-624 Białystok
NIP:5422586976
---

#⚠️ OSTRZEŻENIE (Safety Disclaimer)
Projekt dotyczy układu sterowania w instalacji gazowej CNG. 
Błędny montaż wiązki, niewłaściwe wykonanie elementów mechanicznych lub uszkodzenie izolacji może prowadzić do pożaru lub wybuchu.
Autor oraz firma SCALMAX Paweł Popławski nie ponoszą odpowiedzialności za jakiekolwiek szkody powstałe w wyniku wykorzystania niniejszej dokumentacji.
*Data ostatniej aktualizacji: 22 marca 2026 r.*
**BUDUJESZ I TESTUJESZ NA WŁASNE RYZYKO (BUILD AT YOUR OWN RISK)**
