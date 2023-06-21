#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapFields(struct Point* p1, struct Point* p2) {
    int temp;
    temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;
    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}
int main() {
    struct Point point1, point2;
    printf("Enter the x and y coordinates of the first point: ");
    scanf("%d %d", &(point1.x), &(point1.y));
    printf("Enter the x and y coordinates of the second point: ");
    scanf("%d %d", &(point2.x), &(point2.y));
    printf("\nBefore swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);
    swapFields(&point1, &point2);
    printf("\nAfter swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);
    return 0;
}
