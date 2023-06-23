#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void changeCase(FILE *sourceFile, FILE *targetFile, char option) {
    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        switch (option) {
            case 'u':
                fputc(toupper(ch), targetFile);
                break;
            case 'l':
                fputc(tolower(ch), targetFile);
                break;
            case 's':
                if (islower(ch))
                    fputc(toupper(ch), targetFile);
                else
                    fputc(ch, targetFile);
                break;
            default:
                fputc(ch, targetFile);
                break;
        }
    }
}
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp <option> <source_file> <target_file>\n");
        return 1;
    }
    char *option = argv[1];
    char *sourcePath = argv[2];
    char *targetPath = argv[3];
    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }
    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }
    changeCase(sourceFile, targetFile, *option);
    printf("File copied successfully.\n");
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
