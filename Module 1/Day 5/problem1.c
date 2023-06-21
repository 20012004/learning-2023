#include <stdio.h>
struct Box {
    double length;
    double width;
    double height;
};
double calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}
double calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}
int main() {
    struct Box box;
    struct Box* boxPtr;
    box.length = 6.0;
    box.width = 4.0;
    box.height = 3.0;
    boxPtr = &box;
    printf("By Using (*ptr).\n");
    printf("Length: %.2f\n", (*boxPtr).length);
    printf("Width: %.2f\n", (*boxPtr).width);
    printf("Height: %.2f\n", (*boxPtr).height);
    printf("\nBy Using ptr->\n");
    printf("Length: %.2f\n", boxPtr->length);
    printf("Width: %.2f\n", boxPtr->width);
    printf("Height: %.2f\n", boxPtr->height);
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);
    printf("\nVolume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);
    
    return 0;
}
