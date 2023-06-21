#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void searchStudents(const struct Student* students, int size, const char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student Details:\n");
            printf("1. Roll No: %d\n", students[i].rollno);
            printf("2. Name: %s\n", students[i].name);
            printf("3. Marks: %.2f\n", students[i].marks);
            printf("\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student Not Found.\n");
    }
}
int main() {
    int size = 5;
    struct Student students[] = {
        {1001, "John", 78.5},
        {1002, "Alice", 92.0},
        {1003, "Bob", 85.5},
        {1004, "Emma", 76.0},
        {1005, "David", 90.5}
    };
    char searchName[20];
    printf("Enter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 
    searchStudents(students, size, searchName);
    return 0;
}
