#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RETURN_OK 0

#define NAME_LENGTH 50
#define FILE_NAME_LENGTH 50
#define LINE_LENGTH 256

struct _person;
typedef struct _person person;
struct _person {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];

    double absGrade;
    double relGrade;
};

// IO functions
person* readDataFromFile(int*, double*);
int getFileName(char*);
int printDataToConsole(person*, const int);

// Memory management functions
person* allocMemory(const int);
int deallocMemory(person*);

// Utility functions
int calculateRelativeGrade(person*, const int, const double);

/**
 * Entry function of application
 * @param  argc Number of command line parameters
 * @param  argv Command line parameters
 * @return      Execution result of application
 */
int main(int argc, char** argv) {
    person* data = NULL;
    int dataCount = 0;

    double maxAbsGrade = 0.0;

    int result = 0;

    data = readDataFromFile(&dataCount, &maxAbsGrade);
    if (data == NULL) {
        printf("There was a problem inside readDataFromFile()\n");
        return RETURN_OK;
    }

    result = calculateRelativeGrade(data, dataCount, maxAbsGrade);

    result = printDataToConsole(data, dataCount);

    result = deallocMemory(data);

    return RETURN_OK;
}

/**
 * IO Functions
 */

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
 * Get file name from console
 * @param  fileName String to contain file name
 * @return          Result of operation
 */
int getFileName(char* fileName) {
    printf("Please enter the file name (with path and extension):\n");
    scanf(" %s", fileName);
    return RETURN_OK;
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

/**
 * Memory management functions
 */

/**
 * Allocate memory for array of objects
 * @param  dataCount Number of objects
 * @return           Pointer to address of first object in array (NULL in case of error)
 */
person* allocMemory(const int dataCount) {
    person* data = NULL;

    data = (person*) malloc(sizeof(person) * dataCount);
    if (data == NULL) {
        printf("ERROR: Allocation failed\n");
        return NULL;
    }

    return data;
}

/**
 * Deallocate (free) memory
 * @param  data Array of objects
 * @return      Result of operation
 */
int deallocMemory(person* data) {
    free(data);
    return RETURN_OK;
}

/**
 * Utility functions
 */

/**
 * Function to calculate relative grade variable for every object in array
 * @param  data        Array of objects
 * @param  dataCount   Number of objects in array
 * @param  maxAbsGrade Maximum absolute grade
 * @return             Result of operation
 */
int calculateRelativeGrade(person* data, const int dataCount, const double maxAbsGrade) {
    int i = 0;
    for (i = 0; i < dataCount; ++i)
        data[i].relGrade = data[i].absGrade / maxAbsGrade * 100;

    return 0;
}
