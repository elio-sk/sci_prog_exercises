#ifndef DATE
#define DATE
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

typedef struct Date Date;


Date* newDate(int d, int m, int y);



Date* deleteDate(Date* date);



void setDateDay(Date* date, int d);

void setDateMonth(Date* date, int m);

void setDateYear(Date* date, int y);



int getDateDay(Date* date);

int getDateMonth(Date* date);

int getDateYear(Date* date);



int isMeaningful(Date* date);

#endif
