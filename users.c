#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME 100
#define MAX_FILES 100

// A function to create a new file in the RAM/user folder
void create_file(char *filename) {
    char path[MAX_FILENAME];
    sprintf(path, "RAM/user/%s", filename); // Concatenate the folder name and the file name
    FILE *fp = fopen(path, "w"); // Open the file in write mode
    if (fp == NULL) { // Check if the file was created successfully
        printf("Error: could not create file %s\n", filename);
        exit(1); // Exit with an error code
    }
    fclose(fp); // Close the file
    printf("Created file %s\n", filename);
}

// A function to list the files in the RAM/user folder and ask the user to choose one
char *choose_file() {
    char *files[MAX_FILES]; // An array to store the file names
    int count = 0; // A variable to count the number of files
    DIR *dir = opendir("RAM/user"); // Open the folder
    if (dir == NULL) { // Check if the folder was opened successfully
        printf("Error: could not open folder RAM/user\n");
        exit(1); // Exit with an error code
    }
    struct dirent *entry; // A structure to store the directory entry
    while ((entry = readdir(dir)) != NULL) { // Loop through the entries
        if (entry->d_type == DT_REG) { // Check if the entry is a regular file
            files[count] = strdup(entry->d_name); // Copy the file name to the array
            count++; // Increment the count
        }
    }
    closedir(dir); // Close the folder
    if (count == 0) { // Check if the folder is empty
        printf("No files found in RAM/user\n");
        return NULL; // Return NULL
    }
    if (count == 1) { // Check if the folder has only one file
        printf("Only one file found in RAM/user: %s\n", files[0]);
        return files[0]; // Return the file name
    }
    // If the folder has more than one file, list them and ask the user to choose one
    printf("Multiple files found in RAM/user:\n");
    for (int i = 0; i < count; i++) { // Loop through the files
        printf("%d. %s\n", i + 1, files[i]); // Print the file name with a number
    }
    printf("Enter the number of the file you want to log in as: ");
    int choice; // A variable to store the user's choice
    scanf("%d", &choice); // Read the user's choice
    if (choice < 1 || choice > count) { // Check if the choice is valid
        printf("Invalid choice\n");
        exit(1); // Exit with an error code
    }
    return files[choice - 1]; // Return the chosen file name
}

int main(int argc, char *argv[]) {
    char *filename; // A variable to store the file name
    if (argc > 1) { // Check if an argument was provided
        filename = argv[1]; // Set the file name to the argument
        create_file(filename); // Create the file
    } else { // If no argument was provided
        filename = choose_file(); // Choose a file from the folder
        if (filename == NULL) { // Check if the folder was empty
            filename = "default"; // Set the file name to default
            create_file(filename); // Create the file
        }
    }
    printf("Logged in as %s\n", filename); // Print the login message
    return 0; // Exit with a success code
}


