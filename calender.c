#include <stdio.h>

int get_1st_weekDay(int year)
{

    int day;
    day = ((year) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400)) % 7; 
    return day;
}
int main()
{
    int totalDays, weekDay = 0, speceCounter = 0, year;

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "october", "Novenber", "December"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    printf("Enter your favorite year : ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        monthDay[1] = 29;
    }

    weekDay = get_1st_weekDay(year);

    for (int m = 0; m < 12; m++)
    {
        printf("\n   ................%s................\n\n", months[m]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat   \n\n");

        for (speceCounter = 1; speceCounter <= weekDay; speceCounter++)
        {
            printf("      ");
        }

        totalDays = monthDay[m];
        for (int d = 1; d <= totalDays; d++)
        {
            printf("%6d", d);
            if (++weekDay > 6)
            {
                printf("\n\n");
                weekDay = 0;
            }
        }
    }
    return 0;
}