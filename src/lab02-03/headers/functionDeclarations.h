/**
 * Function declarations
 */
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    #include "./internalDependencies.h"

    /**
     * IO functions
     */
    int menuIO(void);
    int printDataToConsole(position);
    int getDataFromUser(char*, char*, int*);
    int getLastNameFromUser(char*);
    int readDataFromFile(position);
    int printDataToFile(position);

    /**
     * List management functions
     */
    int insertToBeginning(position);
    int insertToEnd(position);
    int insertBeforeElement(position);
    int insertAfterElement(position);
    int createElementAndInsert(position, char*, char*, int);
    int deleteElementFromList(position);
    int deleteList(position);
    int sortList(position);
    int findElementInList(position);
    position findLastElement(position);

    /**
     * Memory management
     */
    position createNewElement(char*, char*, int);
    int deleteElement(position);
#endif // FUNCTION_DECLARATIONS_H
