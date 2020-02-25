#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    int i = 0;
    int day_number = 0;
    int day_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    input_date(&day, &month, &year); //Eingabe von Tag, Monat, Jahr und die Überprüfung.

    if (is_leapyear(year) == 1) { //Überprüfung ob es sich um ein Schaltjahr handelt.
        day_arr[2] = 29;
    }

    for (i=0; i <= month - 2; i++) { //Ausrechnen der Tagesanzahl bis zum aktuellen Monat.
        day_number += day_arr[i];
    }

    day_number += day; //Hinzufügen der Tage des aktuellen Monats.

    return day_number;

    return 0;
}


void input_date(int *day, int *month, int *year)
{
    do {
    printf("Tag:");
    scanf("%i", &*day);
    fflush(stdin);

    printf("Monat:");
    scanf("%i", &*month);
    fflush(stdin);

    printf("Jahr:");
    scanf("%i", &*year);
    fflush(stdin);

    } while(exist_date(*day, *month, *year) == 0);

}





int exist_date(int day, int month, int year)
{
    //int get_days_for_month(day, month, year);
    int day_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (year > 2400 || get_days_for_month(month, year) == -1 || day > day_arr[month - 1] || day < 0)
    {
        printf("Dieses Datum ist ungültig");
        return 0;
    }
    else {
        return 1;
    }

}



int get_days_for_month(int month, int year)
{
    int day_arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (month < 0 || month > 12 || is_leapyear(year) == -1) {
        return -1;
    }

    else {
        return day_arr[month];
    }
}


int is_leapyear(int year)
{

    int leapyear = 0;

    //Überprüfung ob das Jahr durch 4 ohne Rest teilbar ist
    if(year % 4 == 0) {
        //Überprüfung ob das Jahr durch 100 ohne Rest teilbar ist
        if(year % 100 == 0) {
            //Überprüfung ob das Jahr durch 400 ohne Rest teilbar ist
            if (year % 400 == 0) {
                leapyear = 1;
            }
            else {
                leapyear = 0;
            }
        }
        else {
            leapyear = 1;
        }
    }
    else {
        leapyear = 0;
    }

    if (year < 1582) {
        leapyear = -1;
    }

    return leapyear;
}


int main()
{
    int day = 0;
    int month = 0;
    int year = 0;

    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
