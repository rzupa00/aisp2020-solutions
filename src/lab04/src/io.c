/**
 * Input and output functions
 */

#include "../headers/internalDependencies.h"
#include "../headers/externalDependencies.h"

/**
 * Local function declarations
 */

int getFilenameFromUser(char*);

/**
 * Print polynomial to console
 * @param  current First element of polynomial
 * @return         Result of operation
 */
int printPolynomial(position current) {
    int i = 0;

    while (current != NULL) {
        printf("%d * X^%d", current->value, current->exponent);
        current = current->next;

        if (current != NULL)
            printf(" + ");
    }
    printf("\n");

    return RETURN_OK;
}

/**
 * Read polynomial from file
 * @param  head Head of polynomial
 * @return      Result of operation
 */
int readPolynomialFromFile(position head) {
    FILE* filePtr = NULL;
    char filename[FILE_NAME_LENGTH] = "\0";

    char lineBuffer[LINE_BUFFER_LENGTH] = "\0";
    int value = 0;
    int exponent = 0;

    int result = 0;

    getFilenameFromUser(filename);
    filePtr = fopen(filename, "r");
    if (filePtr == NULL)
        return RETURN_WARN_FILE_NOT_OPENED;


    while (!feof(filePtr)) {
        // Reset value of line buffer and data
        strcpy(lineBuffer, "\0");
        value = 0;
        exponent = 0;

        fgets(lineBuffer, LINE_BUFFER_LENGTH - 1, filePtr);
        if (strlen(lineBuffer) > 0) {
            // Line contains data

            sscanf(lineBuffer, " %d %d", &value, &exponent);
            result = addValueToPolynomial(head, value, exponent);
            if (result == RETURN_ERROR_ALLOC_FAILED)
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
