#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 366;

    printf("%d days is %d years, %d months and %d days in total, if all months are 30 days long, and a year is 365 days."
           , days, days / 365, days % 365 / 30, days % 365 % 30);

    return 0;
}
