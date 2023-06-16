#include <stdio.h>
#include <limits.h>
int getSmallestDigit(int num) {
    int smallest = INT_MAX;
    while (num > 0) {
        int digit = num % 10;
        if (digit < smallest) {
            smallest = digit;
        }
        num /= 10;
    }
    return smallest;
}
int getLargestDigit(int num) {
    int largest = INT_MIN;
    while (num > 0) {
        int digit = num % 10;
        if (digit > largest) {
            largest = digit;
        }
        num /= 10;
    }
    return largest;
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Not Valid\n");
        return 0;
    }
    int i, number, smallest, largest;
    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &number);
        if (i == 1) {
            smallest = getSmallestDigit(number);
            largest = getLargestDigit(number);
        } else {
            int currentSmallest = getSmallestDigit(number);
            int currentLargest = getLargestDigit(number);
            if (currentSmallest < smallest) {
                smallest = currentSmallest;
            }
            if (currentLargest > largest) {
                largest = currentLargest;
            }
        }
    }
    if (n > 0) {
        printf("Smallest Digit: %d\n", smallest);
        printf("Largest Digit: %d\n", largest);
    }
    return 0;
}
