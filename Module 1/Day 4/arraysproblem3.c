#include <stdio.h>
void reverseArray(int array[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int array[] = {0,2,4,6,8};
    int length = sizeof(array) / sizeof(array[0]);
    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    reverseArray(array, length);
    printf("\nReversed array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
