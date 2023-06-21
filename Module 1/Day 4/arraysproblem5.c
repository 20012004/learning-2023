#include <stdio.h>
int main() {
    int array[] = {2,4,7,8,9,12,6,10};
    int length = sizeof(array) / sizeof(array[0]);
    int sumOdd = 0;
    int sumEven = 0;
    printf("Odd indexed elements: ");
    for (int i = 1; i < length; i += 2) {
        printf("%d ", array[i]);
        sumOdd += array[i];
    }
    printf("\nEven indexed elements: ");
    for (int i = 0; i < length; i += 2) {
        printf("%d ", array[i]);
        sumEven += array[i];
    }
    int difference = sumOdd - sumEven;
   printf("\nDiff between odd-indexed and even-indexed elements: %d\n", difference);
    return 0;
}
