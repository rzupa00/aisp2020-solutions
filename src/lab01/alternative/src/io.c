/**
 * I/O (Input / Output) function
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

// Local function declarations
int getFileName(char*);

/**
 * Read content of file and save it to array of objects
 * @param  dataCount   Pointer to number of objects
 * @param  maxAbsGrade Pointer to maximum absolute grade
 * @return             Array of objects read from file (NULL in case of error)
 */
person* readDataFromFile(int* dataCount, double* maxAbsGrade) {
    person* data = NULL;
    person* dataBookmark = NULL;

    FILE* file = NULL;
    char fileName[FILE_NAME_LENGTH] = "\0";

    char lineBuffer[LINE_LENGTH] = "\0";

    int result = 0;

    result = getFileName(fileName);
    if (result == RETURN_OK) {
        printf("File name fetched\n");
    }

    // Open file in read mode
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("WARN: File not found or couldn't be opened\n");
        return NULL;
    }

    // Count number of lines in file
    while (!feof(file)) {
        // Set value of line buffer to empty string
        strcpy(lineBuffer, "\0");

        // Read a line
        fgets(lineBuffer, LINE_LENGTH - 1, file);
        if (strlen(lineBuffer) > 0) ++(*dataCount);
    }

    // Reset file pointer to start of file
    rewind(file);

    // Allocate memory for data
    data = allocMemory(*dataCount);
    if (data == NULL) return NULL;

    // Bookmark start of array
    dataBookmark = data;

    // Read data
    while (!feof(file)) {
        // Set value of line buffer to empty string
        strcpy(lineBuffer, "\0");

        // Read a line
        fgets(lineBuffer, LINE_LENGTH - 1, file);
        if (strlen(lineBuffer) > 0) {
            sscanf(lineBuffer, " %s %s %lf", data->firstName, data->lastName, &data->absGrade);

            // Adjust max absolute grade
            if (data->absGrade > *maxAbsGrade) *maxAbsGrade = data->absGrade;
        }

        ++data;
    }

    // Rewind to start of array
    data = dataBookmark;

    // Close file
    fclose(file);

    return data;
}

/**
 * Print array of objects to console
 * @param  data      Array of objects
 * @param  dataCount Number of objects in array
 * @return           Result of operation
 */
int printDataToConsole(person* data, const int dataCount) {
    int i = 0;
    person* iterator = data;
    printf("Data:\n");
    printf("ID\t Name\t\t\t Abs\t\t Rel\n");
    while (i < dataCount) {
        printf(
            "%d:\t %s %s\t\t %.2lf\t\t %.2lf\n",
            i + 1,
            iterator->firstName,
            iterator->lastName,
            iterator->absGrade,
            iterator->relGrade);

        ++iterator;
        ++i;
    }

    return RETURN_OK;
}

// Local functions

/**
 * Get file name from console
 * @param  fileName String to contain file name
 * @return          Result of operation
 */
int getFileName(char* fileName) {
    printf("Please enter the file name (with path and extension):\n");
    scanf(" %s", fileName);
    return RETURN_OK;
}
