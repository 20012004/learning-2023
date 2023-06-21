#include <stdio.h>
#include <math.h>
int convertToDecimal(char* number, int base) {
    int decimal = 0;
    int length = strlen(number);
    for (int i = 0; i < length; i++) {
        int digit;
        if (number[i] >= '0' && number[i] <= '9') {
            digit = number[i] - '0';
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            digit = number[i] - 'A' + 10;
        } else if (number[i] >= 'a' && number[i] <= 'f') {
            digit = number[i] - 'a' + 10;
        } else {
            printf("Invalid input!\n");
            return -1;
        }
        if (digit >= base) {
            printf("Invalid input!\n");
            return -1;
        }
        decimal += digit * pow(base, length - 1 - i);
    }
    return decimal;
}
int main() {
    char number[32];
    int base;
    printf("Enter a number: ");
    scanf("%s", number);
    printf("Enter the base (2, 8, 16): ");
    scanf("%d", &base);
    int decimal = convertToDecimal(number, base);
    if (decimal != -1) {
        printf("Decimal representation: %d\n", decimal);
    }
    return 0;
}
