# ostersonntag für das Terminal

** Ein modernes Terminal-Programm in der CMD/Powershell/Bash

Zur Sicherung vor Eingabefehlern nutzt das Programm mein
getSafeInt aus meiner tools.c

in https://github.com/Michael2211967/mod

Es berechnet zuverlässig unter Linux den im Eingabeprompt er-
wähnten Bereich.

Kompiliert mit MinGW trat der Fehler auf, daß bei Eingaben von
Jahren vor 1970 und nach 2038 kein Datum berechnet wurde.

## Installation & Klonen

Dieses Projekt nutzt das Repository mod als Submodule für Hilfsfunktionen (wie getSafeInt).

Um das Projekt inklusive der benötigten Tools zu klonen, verwende bitte:

```bash git clone --recursive https://github.com/Michael2211967/ostersonntag.git```

## Alternativ (falls du bereits normal geklont hast):

```bash
cd ostersonntag
git submodule update --init --recursive```
