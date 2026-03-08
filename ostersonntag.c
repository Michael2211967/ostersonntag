/* Berechnung des Ostersonntag nach Gauß für 1583 bis 2199 */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "tools.h"

time_t get_easter(int year)
{
  struct tm t = {0};

  int m,n,a,b,c,d,e,f,g;
  switch(year/100)
  {
    case 15 : 
    case 16 : m=22, n=2; break;
    case 17 : m=23, n=3; break;
    case 18 : m=23, n=4; break;
    case 19 :
    case 20 : m=24, n=5; break;
    case 21 : m=24, n=6;
  }
  a = year % 19;
  b = year % 4;
  c = year % 7;
  d = (19*a+m) % 30;
  e = (2*b+4*c+6*d+n) % 7;
  f = 22+d+e;
  g =d+e-9;

  t.tm_year = year - 1900;
  t.tm_isdst = -1; // Wichtig: Automatische Sommerzeit-Erkennung
  if (f<=31)
    {
      t.tm_mday = f;
      t.tm_mon = 2; // März ist 2 (0-basiert)
    }
  else
  {
    if (g==26) g =19;
    if (g==25 && d==28 && a>10) g=18;
    t.tm_mday = g;
    t.tm_mon = 3; // April ist 3
  }
  return mktime(&t);  
}
int main()
{
  char buffer[100];
  int year = 0;
  char *title = "Osterdatum nach Gauss";
  char *dashes = "--------------------------------------------------";
  int length_title = strlen(title) + 6; 
  setlocale(LC_ALL, "");
  printf("\t%.*s\n", length_title, dashes);
  printf("\t   %s\n", title);
  printf("\t%.*s\n", length_title, dashes);
  while(year < 1583 || year > 2199)
  {
    year = getSafeInt("\nJahr zwischen 1583 und 2199 eingeben: ");
    #ifdef _WIN32
    if (year < 1970 || year > 2038) {
        printf("\n Hinweis: Unter Windows werden Daten vor 1970 (Unix-Epoche)\n");
        printf(" leider nicht von den Systemfunktionen unterstuetzt.\n");
        printf(" Bitte ein Jahr zwischen 1970 und 2038 eingeben.\n");
        return 1; 
    }
    #endif
    if(year < 1583){
      printf("Eingabe ist unterhalb vom Bereich!\n");
    }
    else if (year > 2199){
      printf("Eingabe ist oberhalb vom Bereich!\n");
    }
  }
  time_t easter_day = get_easter(year);
  struct tm *t_ptr = localtime(&easter_day);
  strftime(buffer, sizeof(buffer), "%d. %B", t_ptr);
  printf("\n Ostersonntag %d ist der %s\n", year, buffer);
  return 0;
}
