#include <stdio.h>
int main() {
    int array[] = {1, 2, 3, 4, 5};
    int length = sizeof(array) / sizeof(array[0]);
    int sum = 0;
    float average;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    average = (float)sum / length;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    return 0;
}
