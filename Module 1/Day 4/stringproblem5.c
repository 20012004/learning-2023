#include <stdio.h>
#include <string.h>
void rotateString(char *str, int n) {
    int len = strlen(str);
    n %= len;
    if (n < 0)
        n += len;
    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    i = 0, j = n - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    i = n, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int main() {
    char str[100];
    int n;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &n);
    str[strcspn(str, "\n")] = '\0';
    rotateString(str, n);
    printf("Rotated string: %s\n", str);
    return 0;
}
