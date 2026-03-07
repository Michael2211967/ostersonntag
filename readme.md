# ostersonntag für das Terminal

** Ein modernes Terminal-Programm in der CMD/Powershell/Bash

Zur Sicherung vor Eingabefehlern nutzt das Programm mein
getSafeInt aus meiner tools.c

in https://github.com/Michael2211967/mod

Es berechnet zuverlässig unter Linux den im Eingabeprompt er-
wähnten Bereich.

Kompiliert mit MinGW trat der Fehler auf, daß bei Eingaben von
Jahren vor 1970 und nach 2038 kein Datum berechnet wurde.