#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct date
{
  int   day;     
  char  month[10];
  int   year;
};

struct NOTE1
{
  char          Name[20];
  int           TELE;
  struct date   DATE;
};

struct NOTE2 
{
  char          Name[20];
  char          TELE[10];
  struct date   DATE;
};

int main() 
{
  struct NOTE2 person;
  struct NOTE1 BLOCK2[7];
  
  printf("Введите ФИО: ");
  scanf("%s", person.Name);
  printf("Введите дату рождения\nЧисло: ");
  scanf("%d", &person.DATE.day);
  printf("Месяц: ");
  scanf("%s", person.DATE.month);
  printf("Год: ");
  scanf("%d", &person.DATE.year);
  printf("Введите телефонный номер: ");
  scanf("%s", person.TELE);


  printf("\nВы ввели : %s, дата рождения %d %s %d года, телефон: %s\n",
  person.Name, person.DATE.day, person.DATE.month, person.DATE.year, person.TELE);
  return 0;
}