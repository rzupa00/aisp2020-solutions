/**
 * Main function, application entry
 */

#include "../headers/internalDependencies.h"

/**
 * Main function
 * @param  argc Argument counter
 * @param  argv Argument list
 * @return      Execution result
 */
int main(int argc, char** argv) {
    int isAppRunning = 1; // True

    int menuSelection = 0;
    int result = 0;

    // Initialize empty list
    person head;
    head.next = NULL;

    // Main application loop
    do {
        // Print main menu to console and get selection
        menuSelection = menuIO();

        switch (menuSelection) {
        case USER_MENU_INSERT_TO_BEGINNING:
            result = insertToBeginning(&head);
            if (result == RETURN_OK) {
                printf("SUCCESS!!! Data successfully added.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_ERROR_ALLOC_FAILED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_INSERT_TO_END:
            result = insertToEnd(&head);
            if (result == RETURN_OK) {
                printf("SUCCESS!!! Data successfully added.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_ERROR_ALLOC_FAILED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_INSERT_BEFORE_ELEMENT:
            result = insertBeforeElement(&head);
            if (result == RETURN_OK) {
                printf("SUCCESS!!! Data successfully added.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_ELEMENT_NOT_FOUND) {
                printf("Data could not be added because the location for it was not found!\n");
                printf("Please try again!\n");
            } else if (result == RETURN_ERROR_ALLOC_FAILED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_INSERT_AFTER_ELEMENT:
            result = insertAfterElement(&head);
            if (result == RETURN_OK) {
                printf("SUCCESS!!! Data successfully added.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_ELEMENT_NOT_FOUND) {
                printf("Data could not be added because the location for it was not found!\n");
                printf("Please try again!\n");
            } else if (result == RETURN_ERROR_ALLOC_FAILED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_PRINT_TO_CONSOLE:
            result = printDataToConsole(head.next);
            if (result == RETURN_OK) {
            } else if (result == RETURN_WARN_EMPTY_LIST) {
                printf("There was no output because the list is empty.\n");
                printf("Try adding a few elements first.\n");
            }
            break;

        case USER_MENU_READ_FROM_FILE:
            result = readDataFromFile(&head);
            if (result == RETURN_OK) {
                printf("SUCCESS!!! Data successfully read from file.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_FILE_NOT_OPENED) {
                printf("NOTE: File could not be opened!\n");
                printf("Please try again and check the file name and path\n");
            } else if (result == RETURN_ERROR_ALLOC_FAILED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_PRINT_TO_FILE:
            result = printDataToFile(head.next);
            if (result == RETURN_OK) {
                printf("Data was printed to file successfully.\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_EMPTY_LIST) {
                printf("Data was not printed to file because the list is empty.\n");
                printf("Try adding a few elements first.\n");
            } else if (result == RETURN_ERROR_FILE_NOT_OPENED) {
                isAppRunning = 0;
            }
            break;

        case USER_MENU_SORT:
            result = sortList(&head);
            if (result == RETURN_OK) {
                printf("Data was successfully sorted.\n");
            } else if (result == RETURN_WARN_EMPTY_LIST) {
                printf("NOTE: the list is empty!\n");
                printf("Try adding a few elements first!\n");
            }
            break;

        case USER_MENU_FIND:
            result = findElementInList(&head);
            if (result == RETURN_OK) {
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_ELEMENT_NOT_FOUND) {
                printf("Data was not found in list!\n");
            } else if (result == RETURN_WARN_EMPTY_LIST) {
                printf("NOTE: list is empty!\n");
                printf("Try adding a few elements first!\n");
            }
            break;

        case USER_MENU_DELETE:
            result = deleteElementFromList(&head);
            if (result == RETURN_OK) {
                printf("Data successfully deleted!\n");
            } else if (result == RETURN_OPERATION_CANCELLED) {
                printf("Operation cancelled!\n");
            } else if (result == RETURN_WARN_ELEMENT_NOT_FOUND) {
                printf("NOTE: data was not found in list\n");
            } else if (result == RETURN_WARN_EMPTY_LIST) {
                printf("NOTE: list is empty!\n");
                printf("Try adding a few elements first!\n");
            }
            break;

        case USER_MENU_EXIT:
            result = RETURN_OK;
            isAppRunning = 0;
            break;

        default:
            printf("NOTE: Unknown command given!!!\n");
            printf("Please try again!\n");
        }
    } while (isAppRunning == 1);

    if (result == RETURN_ERROR_ALLOC_FAILED) {
        printf("ERROR!!! There was a problem with the memory and the application must terminate!\n");
    } else if (result == RETURN_ERROR_FILE_NOT_OPENED) {
        printf("ERROR!!! There was a problem with the file system and the application must terminate!\n");
    }

    // Delete all elements from list
    deleteList(&head);

    printf("Exiting application...");
    return RETURN_OK;
}
