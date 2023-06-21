#include <stdio.h>
#include <stdbool.h>
#include <regex.h>
bool validateEmail(const char* email) {
    regex_t regex;
    int reti;
    const char* pattern = "^[Za-z0-9._%+-]+@[Za-z0-9.-]+\\.[Za-z]{2,}$";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }
    reti = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    if (reti == 0) {
        return true; 
    } else {
        return false; 
    }
}
int main() {
    char email[100];
    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    if (validateEmail(email)) {
        printf("Valid email address!\n");
    } else {
        printf("Invalid email address!\n");
    }
    return 0;
}
