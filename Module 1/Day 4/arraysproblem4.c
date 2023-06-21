#include <stdio.h>
int main() {
    int array[] = {5,4,2,8,7,1,6,9};
    int length = sizeof(array) / sizeof(array[0]);
    int sumOdd = 0;
    int sumEven = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            sumEven += array[i];
        } else {
            sumOdd += array[i];
        }
    }
    int difference = sumOdd - sumEven;
    printf("Diff between odd and even elements: %d\n", difference);
    return 0;
}
