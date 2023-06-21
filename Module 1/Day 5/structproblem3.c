#include <stdio.h>
struct Time {
    int hours;
    int minutes;
    int seconds;
};
struct Time calculateTimeDifference(struct Time start, struct Time end) {
    struct Time diff;
    int totalSecondsStart, totalSecondsEnd, totalSecondsDiff;
    totalSecondsStart = start.hours * 3600 + start.minutes * 60 + start.seconds;
    totalSecondsEnd = end.hours * 3600 + end.minutes * 60 + end.seconds;
    totalSecondsDiff = totalSecondsEnd - totalSecondsStart;
    diff.hours = totalSecondsDiff / 3600;
    totalSecondsDiff %= 3600;
    diff.minutes = totalSecondsDiff / 60;
    diff.seconds = totalSecondsDiff % 60;
    return diff;
}
int main() {
    struct Time startTime, endTime, diffTime;
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    diffTime = calculateTimeDifference(startTime, endTime);
    printf("\nDifference between the two time periods:\n");
    printf("Hours: %d\n", diffTime.hours);
    printf("Minutes: %d\n", diffTime.minutes);
    printf("Seconds: %d\n", diffTime.seconds);

    return 0;
}
