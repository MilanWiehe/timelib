#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    int i = 0;
    int tageszahlen = 0;
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    printf("Tag:");
    scanf("%i", &day);

    printf("Monat:");
    scanf("%i", &month);

    printf("Jahr:");
    scanf("%i", &year);

    if(exist_date(day, month, year) == 0) {
        printf("Dieses Datum ist ungültig");
    }

    else {

        if (is_leapyear(year) == 1) {
            tage[2] = 29;
        }

        for (i=0; i <= month - 2; i++) {
            tageszahlen += tage[i];
        }

        tageszahlen += day;
    }
    return tageszahlen;

    return 0;
}

int exist_date(int day, int month, int year)
{
    //int get_days_for_month(day, month, year);
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (year > 2400 || get_days_for_month(month, year) == -1 || day > tage[month] || day < 0)
    {
        return 0;
    }
    else {
        return 1;
    }

}


int get_days_for_month(int month, int year)
{
    int tage[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //int is_leapyear(year);

    if (month < 0 || month > 12 || is_leapyear(year) == -1) {
        return -1;
    }
    else {

        return tage[month];
    }
}


int is_leapyear(int year)
{

    int Schaltjahr = 0;

    //Überprüfung ob das Jahr durch 4 ohne Rest teilbar ist
    if(year % 4 == 0) {
        //Überprüfung ob das Jahr durch 100 ohne Rest teilbar ist
        if(year % 100 == 0) {
            //Überprüfung ob das Jahr durch 400 ohne Rest teilbar ist
            if (year % 400 == 0) {
                Schaltjahr = 1;
            }
            else {
                Schaltjahr = 0;
            }
        }
        else {
            Schaltjahr = 1;
        }
    }
    else {
        Schaltjahr = 0;
    }

    if (year < 1582) {
        Schaltjahr = -1;
    }

    return Schaltjahr;
}


int main()
{
    int day = 0;
    int month = 0;
    int year = 0;

    printf("Tag des Jahres: %i\n", day_of_the_year(day, month, year));
    return 0;
}
