#include <stdio.h>

int MonthDays(int year, int month);

int main()
{
    int ndays, month, year;

    scanf("%d", &year);
    for(month = 1; month <= 12; month++){
        ndays = MonthDays(year, month);
        printf("%d ", ndays);
    }

    return 0;
}

int MonthDays(int y, int m){
    const int an[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return m == 2 ? y % 4 == 0 && y % 100 != 0 || y % 400 == 0 ? 29 : 28 : an[m];
}