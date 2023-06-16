#include <stdio.h>
void generatePattern(int n) {
    int i, j;
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
    
        for (j = 1; j <= 2 * (n - i); j++) {
            printf(" ");
        }
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}
int main() {
    int n = 5;
    generatePattern(n);
    return 0;
}