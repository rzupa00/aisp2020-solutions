/**
 * Input and output functions
 */

#include "../headers/internalDependencies.h"

/**
 * Local function declarations
 */
int displayMainMenu(void);
int getMainMenuSelection(void);
int clearScreen();
int getFilenameFromUser(char*);

/**
 * Print main menu to user and get selection
 * @return  Menu selection
 */
int menuIO(void) {
    int target = 0;

    displayMainMenu();
    target = getMainMenuSelection();
    clearScreen();

    return target;
}

/**
 * Print list to console
 * @param  current First element of list
 * @return         Result of operation
 */
int printDataToConsole(position current) {
    int i = 1;

    if (current == NULL)
        return RETURN_WARN_EMPTY_LIST;

    while (current != NULL) {
        printf("%d\t%s %s\t %d\n", i++, current->firstName, current->lastName, current->yearOfBirth);
        current = current->next;
    }

    return RETURN_OK;
}

/**
 * Get element data from user (via console)
 * @param  firstName   First name
 * @param  lastName    Last name
 * @param  yearOfBirth Year of birth
 * @return             Result of operation
 */
int getDataFromUser(char* firstName, char* lastName, int* yearOfBirth) {
    printf("If you wish to cancel this operation, %d for number values or %s for string values\n",
        USER_SUBMENU_CANCEL_INTEGER,
        USER_SUBMENU_CANCEL_STRING);
    printf("Please enter the required data:\n");

    do {
        printf("First name:\t");
        scanf(" %s", firstName);
    } while (strlen(firstName) == 0);
    
    do {
        printf("Last name:\t");
        scanf(" %s", lastName);
    } while (strlen(lastName) == 0);

    do {
        printf("Year of birth:\t");
        scanf(" %d", yearOfBirth);
    } while ((*yearOfBirth) == 0);

    return RETURN_OK;
}

/**
 * Get last name from user (via console)
 * @param  target Target last name
 * @return        Result of operation
 */
int getLastNameFromUser(char* target) {
    printf("Please enter the sought last name:\t");
    scanf(" %s", target);
    return RETURN_OK;
}

/**
 * Read data from file
 * @param  head Head of list
 * @return      Result of operation
 */
int readDataFromFile(position head) {
    FILE* filePtr = NULL;
    char filename[FILE_NAME_LENGTH] = "\0";
    position last = NULL;

    char lineBuffer[LINE_BUFFER_LENGTH] = "\0";
    char firstName[FIRST_NAME_LENGTH] = "\0";
    char lastName[LAST_NAME_LENGTH] = "\0";
    int yearOfBirth = 0;

    int result = 0;

    last = findLastElement(head);

    getFilenameFromUser(filename);

    if (strcmp(filename, USER_SUBMENU_CANCEL_STRING) == 0)
        return RETURN_OPERATION_CANCELLED;

    filePtr = fopen(filename, "r");
    if (filePtr == NULL)
        return RETURN_WARN_FILE_NOT_OPENED;


    while (!feof(filePtr)) {
        // Reset value of line buffer and data
        strcpy(lineBuffer, "\0");
        strcpy(firstName, "\0");
        strcpy(lastName, "\0");
        yearOfBirth = 0;

        fgets(lineBuffer, LINE_BUFFER_LENGTH - 1, filePtr);
        if (strlen(lineBuffer) > 0) {
            // Line contains data

            sscanf(lineBuffer, " %s %s %d", firstName, lastName, &yearOfBirth);

            result = createElementAndInsert(last, firstName, lastName, yearOfBirth);
            if (result == RETURN_ERROR_ALLOC_FAILED)
                return RETURN_ERROR_ALLOC_FAILED;

            last = last->next;
        }
    }

    fclose(filePtr);
    return RETURN_OK;
}

/**
 * Print list to file
 * @param  current First element of list
 * @return         Result of operation
 */
int printDataToFile(position current) {
    FILE* filePtr = NULL;
    char filename[FILE_NAME_LENGTH] = "\0";

    if (current == NULL) {
        return RETURN_WARN_EMPTY_LIST;
    }

    getFilenameFromUser(filename);
    if (strcmp(filename, USER_SUBMENU_CANCEL_STRING) == 0) {
        return RETURN_OK;
    }

    filePtr = fopen(filename, "w");
    if (filePtr == NULL) {
        return RETURN_ERROR_FILE_NOT_OPENED;
    }

    while (current != NULL) {
        fprintf(filePtr, "%s %s %d\n", current->firstName, current->lastName, current->yearOfBirth);
        current = current->next;
    }

    fclose(filePtr);
    return RETURN_OK;
}

/**
 * Local functions
 */

/**
 * Display main menu in console
 * @return  OK
 */
int displayMainMenu(void) {
    printf("####################################\n");
    printf("# Insert to beginning ---------- %d #\n", USER_MENU_INSERT_TO_BEGINNING);
    printf("# Insert to end ---------------- %d #\n", USER_MENU_INSERT_TO_END);
    printf("# Insert before element -------- %d #\n", USER_MENU_INSERT_BEFORE_ELEMENT);
    printf("# Insert after element --------- %d #\n", USER_MENU_INSERT_AFTER_ELEMENT);
    printf("# Print list ------------------- %d #\n", USER_MENU_PRINT_TO_CONSOLE);
    printf("# Read from file --------------- %d #\n", USER_MENU_READ_FROM_FILE);
    printf("# Print to file ---------------- %d #\n", USER_MENU_PRINT_TO_FILE);
    printf("# Delete element --------------- %d #\n", USER_MENU_DELETE);
    printf("# Find element ----------------- %d #\n", USER_MENU_FIND);
    printf("# Sort list -------------------- %d #\n", USER_MENU_SORT);
    printf("# Exit application ------------- %d #\n", USER_MENU_EXIT);
    printf("####################################\n\n\n\n");

    printf("Please enter your choice:\t");

    return RETURN_OK;
}

/**
 * Get main menu selection from user
 * @return  Main menu selection
 */
int getMainMenuSelection(void) {
    int target = 0;
    scanf(" %d", &target);
    return target;
}

/**
 * Clear console screen
 * @return  OK
 */
int clearScreen() {
    system(CLEAR_SCREEN);
    return RETURN_OK;
}

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
