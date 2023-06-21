#include <stdio.h>
int calculateTotalSec(int hr, int min, int sec) {
    int totalSec = (hr * 3600) + (min * 60) + sec;
    return totalSec;
}
int main() {
    int hr, min, sec;
    printf("Enter the time (hours minutes seconds): ");
    scanf("%d %d %d", &hr, &min, &sec);
    int totalSec = calculateTotalSec(hr, min, sec);
    printf("Total seconds: %d\n", totalSec);
    return 0;
}
