#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};
int compare(const void* a, const void* b) {
    struct Student* studentA = (struct Student*)a;
    struct Student* studentB = (struct Student*)b;
    if (studentA->marks < studentB->marks)
        return 1;
    else if (studentA->marks > studentB->marks)
        return -1;
    else
        return 0;
}
void sortStudents(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compare);
}
void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
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
    sortStudents(students, size);
    printf("Sorted student details:\n");
    displayStudents(students, size);
    return 0;
}
