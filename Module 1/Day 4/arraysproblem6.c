#include <stdio.h>
void convertToBinary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}
void convertToOctal(int decimal) {
    int octal[32];
    int i = 0;
    while (decimal > 0) {
        octal[i] = decimal % 8;
        decimal /= 8;
        i++;
    }
    printf("Octal representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}
void convertToHexadecimal(int decimal) {
    char hexadecimal[32];
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 'A' - 10;
        }
        decimal /= 16;
        i++;
    }
    printf("Hexadecimal representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}
int main() {
    int decimal;
    printf("Enter a decimal no: ");
    scanf("%d",&decimal);
    convertToBinary(decimal);
    convertToOctal(decimal);
    convertToHexadecimal(decimal);
    return 0;
}
