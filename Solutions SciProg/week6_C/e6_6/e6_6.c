#include "date.h"

Date* newDate(int d, int m, int y){
    Date* date = malloc(sizeof(Date));
    date->day = d;
    date->month = m;
    date->year = y;
    return date;
}


Date* deleteDate(Date* date){
    free(date);
    return NULL;
}


void setDateDay(Date* date, int d){
    date->day = d;
}

void setDateMonth(Date* date, int m){
    date->month = m;
}

void setDateYear(Date* date, int y){
    date->year = y;
}

int getDateDay(Date* date){
    return date->day;
}

int getDateMonth(Date* date){
    return date->month;
}

int getDateYear(Date* date){
    return date->year;
}



int isMeaningful(Date* date){
    if (date->day < 1 || date->day > 31)
        return 0;
    if (date->month < 1 || date->month > 12)
        return 0;
    if (date->year < 1900)
        return 0;
    if (date->month == 2)
    {
        if (date->day == 29 && date->year % 4 != 0)
            return 0;
        if (date->day == 30 || date->day == 31)
            return 0;
    }
    if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)
        if (date->day > 30)
            return 0;
    return 1;
}


int main(){
    Date* date = newDate(1, 1, 1900);
    printf("Current day: %d\n", getDateDay(date));
    printf("Current month: %d\n", getDateMonth(date));
    printf("Current year: %d\n", getDateYear(date));

    printf("Enter a new date: ");
    
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);

    Date* new_date = newDate(day, month, year);
    if (isMeaningful(new_date)){
        printf("The new date is meaningful.");
        setDateDay(date, day);
        setDateMonth(date, month);
        setDateYear(date, year);
        printf("New day: %d\n", getDateDay(date));
        printf("New month: %d\n", getDateMonth(date));
        printf("New year: %d\n", getDateYear(date));
    }
    else
        printf("New date is not meaningful. \n");
    
    deleteDate(date);
    return 0;
}
