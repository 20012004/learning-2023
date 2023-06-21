#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
void parseString(const char* input, struct Student* students, int size) {
    char temp[20];
    int i = 0;
    const char* delimiter = " ";
    char* token = strtok((char*)input, delimiter);
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        strcpy(students[i].name, token);

        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
        i++;
    }
}
int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    printf("Enter the student details:\n");
    for (int i = 0; i < size; i++) {
        char input[100];
        printf("Enter details for student %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        parseString(input, &students[i], 1);
    }
    printf("\nStudent details:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    free(students);
    return 0;
}
