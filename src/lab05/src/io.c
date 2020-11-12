/**
 * Input and output functions
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

/**
 * Local function declarations
 */

int getFilenameFromUser(char*);

/**
 * Print set to console
 * @param  current First element of set
 * @return         Result of operation
 */
int printSet(position current) {
    int i = 0;

    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;

        if (current != NULL)
            printf(", ");
    }
    printf("\n");

    return RETURN_OK;
}

/**
 * Read set from file
 * @param  head Head of set
 * @return      Result of operation
 */
int readSetFromFile(position head) {
    FILE* filePtr = NULL;
    char filename[FILE_NAME_LENGTH] = "\0";

    int value = 0;

    int result = 0;

    getFilenameFromUser(filename);
    filePtr = fopen(filename, "r");
    if (filePtr == NULL)
        return RETURN_WARN_FILE_NOT_OPENED;


    while (!feof(filePtr)) {
        // Read an element from set
        fscanf(filePtr, " %d", &value);

        result = addValueToSet(head, value);
        if (result == RETURN_ERROR_ALLOC_FAILED) {
            fclose(filePtr);
            return RETURN_ERROR_ALLOC_FAILED;
        }

    }

    fclose(filePtr);
    return RETURN_OK;
}

/**
 * Local functions
 */

/**
 * Get file name from user via console
 * @param  target String to contain file name
 * @return        Result of operation
 */
int getFilenameFromUser(char* target) {
    printf("Please enter the file name (with path and extension):\t");
    scanf(" %s", target);
    return RETURN_OK;
}
