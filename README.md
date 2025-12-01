# 🚗 Bilregister – C-Program  
Ett komplett textbaserat fordonsregister skrivet i C, utvecklat för att hantera fordon, ägare och filbaserad lagring. Programmet använder en menystruktur där användaren kan lägga till, ta bort, visa, sortera och slumpa fram fordon.

---

![Status](https://img.shields.io/badge/status-active-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey)
![License](https://img.shields.io/badge/license-educational-yellow)

---

## 📖 Översikt

Detta projekt implementerar ett fordonsregister som innehåller upp till **10 fordon**.  
Varje fordon har:
- fordonstyp  
- märke  
- registreringsnummer  
- ägare (namn + ålder)

Registret sparas automatiskt till fil vid avslut och laddas igen vid programmets start.

---

## ✨ Funktioner

### 🟩 1. Lägg till fordon
- Tar emot fordonets och ägarens information.
- Kontrollerar att registret inte är fullt.

### 🟥 2. Ta bort fordon
- Tar bort ett fordon på användarvald position (1–10).
- Hanterar ogiltiga värden och tomma platser.

### 🔤 3. Sortera efter bilmärke
- Alfabetisk sortering på bilmärke (case-insensitive eller valfritt).

### 🔎 4. Visa fordon
- Skriver ut all info om valt fordon inklusive ägare.

### 📄 5. Visa hela registret
- En rad per fordon.
- Ägarinformation visas inte här.

### 🎲 6. Slumpa fordon
- Skapar ett fordon med slumpmässiga men rimliga värden.
- Varje egenskap har minst 10 möjliga alternativ.

### ⏻ 0. Avsluta
- Sparar registret till fil.

---

## 📁 Projektstruktur

