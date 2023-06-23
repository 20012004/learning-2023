#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 50
#define MAX_ENTRIES 100
typedef struct {
    int entryNo;
    char sensorNo[MAX_FIELD_LENGTH];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_FIELD_LENGTH];
} LogEntry;
void parseCSVLine(char *line, LogEntry *entry) {
    char *token;
    int fieldIndex = 0;

    token = strtok(line, ",");
    while (token != NULL && fieldIndex < 6) {
        switch (fieldIndex) {
            case 0:
                entry->entryNo = atoi(token);
                break;
            case 1:
                strcpy(entry->sensorNo, token);
                break;
            case 2:
                entry->temperature = atof(token);
                break;
            case 3:
                entry->humidity = atoi(token);
                break;
            case 4:
                entry->light = atoi(token);
                break;
            case 5:
                strcpy(entry->timestamp, token);
                break;
            default:
                break;
        }
        fieldIndex++;
        token = strtok(NULL, ",");
    }
}

void printLogEntry(LogEntry entry) {
    printf("EntryNo: %d\n", entry.entryNo);
    printf("SensorNo: %s\n", entry.sensorNo);
    printf("Temperature: %.1f\n", entry.temperature);
    printf("Humidity: %d\n", entry.humidity);
    printf("Light: %d\n", entry.light);
    printf("Timestamp: %s\n", entry.timestamp);
    printf("-----------------------\n");
}
void displayLog(LogEntry *log, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printLogEntry(log[i]);
    }
}
int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    LogEntry log[MAX_ENTRIES];
    int numEntries = 0;
    fgets(line, MAX_LINE_LENGTH, file); 
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && numEntries < MAX_ENTRIES) {
        parseCSVLine(line, &log[numEntries]);
        numEntries++;
    }
    displayLog(log, numEntries);

    fclose(file);
    return 0;
}
