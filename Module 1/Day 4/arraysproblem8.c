#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}
int calculateElapsedDays(struct Date date1, struct Date date2) {
    int days = 0;
    for (int year = date1.year + 1; year < date2.year; year++) {
        days += isLeapYear(year) ? 366 : 365;
    }
    for (int month = date1.month + 1; month <= 12; month++) {
        days += getDaysInMonth(month, date1.year);
    }
    days += getDaysInMonth(date1.month, date1.year) - date1.day;
    for (int month = 1; month < date2.month; month++) {
        days += getDaysInMonth(month, date2.year);
    }
    days += date2.day;

    return days;
}
int main() {
    struct Date date1, date2;
    printf("Enter the first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);
    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);
    int daysElapsed = calculateElapsedDays(date1, date2);
    printf("Number of days elapsed: %d\n", daysElapsed);
    return 0;
}
