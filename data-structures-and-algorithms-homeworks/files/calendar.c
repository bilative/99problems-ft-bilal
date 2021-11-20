#include <stdio.h>
#include <conio.h>

// Actually this was little hard problem for me, So I searched on internet and I fixed
//a code already exist (there was bug, I fixed it with initial_gap and position equations)

int main(void) {
  int year;
  int leap_year;
  int days;
  int month;
  int gap;
  int position;
  int number_of_day;
  int initial_gap;
  do {
    printf("This function only calculates calendars between 1994 and 1999: ");
    scanf("%d", & year);
  } while (year < 1994 || year > 1999);
  switch (year) {

  case 1994:
    position = 7;
    break;

  case 1995:
    position = 1;
    break;

  case 1996:
    position = 2;
    break;

  case 1997:
    position = 4;
    break;

  case 1998:
    position = 5;
    break;

  case 1999:
    position = 6;
    break;
  }
  if (year % 400 == 0) {
    leap_year = 1;
  } else if (year % 4 == 0 && year % 100 != 0) {
    leap_year = 1;
  } else {
    leap_year = 0;
  }
  for (month = 1; month <= 12; month+=1) {
    switch (month) {

    case 1:
      printf("\n\nJanuary %d\n", year);
      days = 31;
      break;

    case 2:
      printf("\n\nFebruary %d\n", year);
      days = leap_year == 1 ? 29 : 28;
      break;

    case 3:
      printf("\n\nMarch %d\n", year);
      days = 31;
      break;

    case 4:
      printf("\n\nApril %d\n", year);
      days = 30;
      break;

    case 5:
      printf("\n\nMay %d\n", year);
      days = 31;
      break;

    case 6:
      printf("\n\nJune %d\n", year);
      days = 30;
      break;

    case 7:
      printf("\n\nJuly %d\n", year);
      days = 31;
      break;

    case 8:
      printf("\n\nAugust %d\n", year);
      days = 31;
      break;

    case 9:
      printf("\n\nSeptember %d\n", year);
      days = 30;
      break;

    case 10:
      printf("\n\nOctober %d\n", year);
      days = 31;
      break;

    case 11:
      printf("\n\nNovember %d\n", year);
      days = 30;
      break;

    case 12:
      printf("\n\nDecember %d\n", year);
      days = 31;
      break;
    }
    printf(" S  M  T  W  R  F  S\n");
    
    initial_gap = (position-1) * 3 + 1;
        // Equation for true gap size begining of the month
    
    for (gap = 1; gap < initial_gap; gap+=1) {
      printf(" ");
    }
    for (number_of_day = 1; number_of_day <= days; number_of_day+=1) {
      printf("%2d ", number_of_day);
      if (position % 7 == 0) {
        printf("\n");
        position = 1;
      } else {
        position += 1;
      }
    }
  }
  getch();
  return 0;
}