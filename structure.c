#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct date
{
  int   day;     
  char  *month;
  int   year;
};

struct NOTE2 
{
   char          *Name;
   int           TELE;
   struct date   DATE;
   struct NOTE2* next;
};

