#include <stdio.h>
#include <stdlib.h>
struct Date {
    int day;
    int month;
    int year;
};
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return daysInMonth[month - 1];
}
int calculateElapsedDays(struct Date startDate, struct Date endDate) {
    int days = 0;
    for (int year = startDate.year + 1; year < endDate.year; year++) {
        if (isLeapYear(year))
            days += 366;
        else
            days += 365;
    }
    for (int month = startDate.month + 1; month <= 12; month++)
        days += getDaysInMonth(month, startDate.year);
    for (int month = 1; month < endDate.month; month++)
        days += getDaysInMonth(month, endDate.year);
    days += getDaysInMonth(startDate.month, startDate.year) - startDate.day + 1;
    days += endDate.day - 1;
    return days;
}
struct Date parseDate(const char* dateString) {
    struct Date date;
    sscanf(dateString, "%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}
int main() {
    char startDateString[11], endDateString[11];
    struct Date startDate, endDate;
    printf("Enter the start date (DD/MM/YYYY): ");
    scanf("%s", startDateString);
    printf("Enter the end date (DD/MM/YYYY): ");
    scanf("%s", endDateString);
    startDate = parseDate(startDateString);
    endDate = parseDate(endDateString);
    int elapsedDays = calculateElapsedDays(startDate, endDate);
    printf("Number of days elapsed: %d\n", elapsedDays);
    return 0;
}
