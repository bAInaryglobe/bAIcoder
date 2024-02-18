#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void function_0(); 
void function_1();

#define MAX_LINE_LENGTH 100

int main() {
    FILE *settingsFile;
    char line[MAX_LINE_LENGTH];
    char *variable, *value;

    // Open the settings file 
    settingsFile = fopen("settings.ini", "r");
    if (settingsFile == NULL) {
        printf("Error: Unable to open settings.ini\n");
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), settingsFile) != NULL) {
        // Basic parsing (assumes simple "variable=value" format)
        variable = strtok(line, "="); 
        value = strtok(NULL, "=");

        // Remove any trailing newline from the value 
        if (value) {
            value[strcspn(value, "\n")] = 0; 
        }

        // Call the appropriate function based on the value
        if (strcmp(value, "0") == 0) {
            function_0();
        } else if (strcmp(value, "1") == 0) {
            function_1();
        } else {
            printf("Warning: Invalid value for variable %s\n", variable);
        }
    }

    fclose(settingsFile);
    return 0;
}

// Sample placeholder functions
void function_0() {
    printf("Function 0 called\n");
}

void function_1() {
    printf("Function 1 called\n");
}


