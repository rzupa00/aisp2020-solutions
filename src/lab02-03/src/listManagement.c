/**
 * List management functions
 */

#include "../headers/internalDependencies.h"

/**
 * Local function declarations
 */

int getDataAndInsert(position);
int insert(position, position);
position findPreviousElement(position, char*);
int deleteNextElement(position);

/**
 * Insert element to beginning of list
 * @param  head Head of list
 * @return      Result of operation
 */
int insertToBeginning(position head) {
    return getDataAndInsert(head);
}

/**
 * Insert element to end of list
 * @param  head Head of list
 * @return      Result of operation
 */
int insertToEnd(position head) {
    position last = findLastElement(head);
    return getDataAndInsert(last);
}

/**
 * Insert new element before the desired element
 * @param  head Head of list
 * @return      Result of operation
 */
int insertBeforeElement(position head) {
    char nextLastName[LAST_NAME_LENGTH] = "\0";
    position previous = NULL;

    getLastNameFromUser(nextLastName);
    if (strcmp(nextLastName, USER_SUBMENU_CANCEL_STRING) == 0)
        return RETURN_OPERATION_CANCELLED;

    previous = findPreviousElement(head, nextLastName);
    if (previous == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    return getDataAndInsert(previous);
}

/**
 * Insert new element after the desired element
 * @param  head Head of list
 * @return      Result of operation
 */
int insertAfterElement(position head) {
    char nextLastName[LAST_NAME_LENGTH] = "\0";
    position previous = NULL;

    getLastNameFromUser(nextLastName);
    if (strcmp(nextLastName, USER_SUBMENU_CANCEL_STRING) == 0)
        return RETURN_OPERATION_CANCELLED;

    previous = findPreviousElement(head, nextLastName);
    if (previous == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    previous = previous->next;
    if (previous == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    return getDataAndInsert(previous);
}

/**
 * Allocate memory for new element and add it to list right after the desired element
 * @param  previous    Element after which the new element will be located
 * @param  firstName   First name of new object
 * @param  lastName    Last name of new object
 * @param  yearOfBirth Year of birth of new object
 * @return             Result of operation
 */
int createElementAndInsert(
        position previous,
        char* firstName,
        char* lastName,
        int yearOfBirth) {
    position target = createNewElement(firstName, lastName, yearOfBirth);
    if (target == NULL)
        return RETURN_ERROR_ALLOC_FAILED;

    return insert(previous, target);
}

/**
 * Delete desired element from list
 * @param  head Head of list
 * @return      Result of operation
 */
int deleteElementFromList(position head) {
    char targetLastName[LAST_NAME_LENGTH] = "\0";
    position previous = NULL;

    getLastNameFromUser(targetLastName);
    if (strcmp(targetLastName, USER_SUBMENU_CANCEL_STRING) == 0)
        return RETURN_OPERATION_CANCELLED;

    previous = findPreviousElement(head, targetLastName);
    if (previous == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    return deleteNextElement(previous);
}

/**
 * Delete entire list
 * @param  head Head of list
 * @return      Result of operation
 */
int deleteList(position head) {
    while (head->next != NULL)
        deleteNextElement(head);

    return RETURN_OK;
}

/**
 * Sort list by last name
 * @param  head Head of list
 * @return      Result of operation
 */
int sortList(position head) {
    position first = NULL;
    position previousFirst = NULL;
    position second = NULL;
    position lastSorted = NULL;

    if (head->next == NULL)
        return RETURN_WARN_EMPTY_LIST;

    if (head->next->next == NULL)
        return RETURN_OK;

    // Main loop
    while (head->next != lastSorted) {
        previousFirst = head;
        first = previousFirst->next;

        // Secondary loop
        while (first->next != lastSorted) {
            second = first->next;

            if (strcmp(first->lastName, second->lastName) > 0) {
                // Replace first and second node
                // New order: previousFirst->second->first

                previousFirst->next = second;
                first->next         = second->next;
                second->next        = first;
            } else {
                first = first->next;
            }

            previousFirst = previousFirst->next;
        }

        // Move lastSorted 1 step backwards, because everything after lastSorted
        // (including lastSorted) is alredy sorted
        lastSorted = previousFirst->next;
    }

    return RETURN_OK;
}

int findElementInList(position head) {
    char targetLastName[LAST_NAME_LENGTH] = "\0";
    position previous = NULL;

    if (head->next == NULL)
        return RETURN_WARN_EMPTY_LIST;

    getLastNameFromUser(targetLastName);
    if (strcmp(targetLastName, USER_SUBMENU_CANCEL_STRING) == 0)
        return RETURN_OPERATION_CANCELLED;

    previous = findPreviousElement(head, targetLastName);
    if (previous == NULL || previous->next == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    printf("Data found!!!\n");
    printf("Sought data is:\n");
    printf("%s %s %d\n",
        previous->next->firstName,
        previous->next->lastName,
        previous->next->yearOfBirth);

    return RETURN_OK;
}

/**
 * Find last element in list
 * @param  target Head of list
 * @return      Last element in list
 */
position findLastElement(position target) {
    while (target->next != NULL)
        target = target->next;

    return target;
}

/**
 * Local functions
 */

/**
 * Get data from user (via console) and insert element at desired position
 * @param  previous Previous element in list (after which the new data will be inserted)
 * @return          Result of operation
 */
int getDataAndInsert(position previous) {
    char firstName[FIRST_NAME_LENGTH] = "\0";
    char lastName[LAST_NAME_LENGTH] = "\0";
    int yearOfBirth = 0;

    getDataFromUser(firstName, lastName, &yearOfBirth);
    if (strcmp(firstName, USER_SUBMENU_CANCEL_STRING) == 0 ||
        strcmp(lastName, USER_SUBMENU_CANCEL_STRING) == 0 ||
        yearOfBirth == USER_SUBMENU_CANCEL_INTEGER) {
        return RETURN_OPERATION_CANCELLED;
    }

    return createElementAndInsert(previous, firstName, lastName, yearOfBirth);
}

/**
 * Insert element at desired position in list
 * @param  previous Previous element, after which the new element will be inserted
 * @param  target   Element to be inserted
 * @return          Result of operation
 */
int insert(position previous, position target) {
    target->next = previous->next;
    previous->next = target;

    return RETURN_OK;
}

/**
 * Find previous element of the desired element (by last name)
 * @param  target       First element from which the search shall be started
 * @param  nextLastName Last name of the element after the sought element
 * @return              Found element (or NULL if element was not found)
 */
position findPreviousElement(position target, char* nextLastName) {
    while (target->next != NULL && strcmp(target->next->lastName, nextLastName) != 0)
        target = target->next;

    if (target->next == NULL)
        return NULL;

    return target;
}

/**
 * Delete next element in list
 * @param  previous Previous element of the element to be deleted
 * @return          Result of operation
 */
int deleteNextElement(position previous) {
    position target = previous->next;

    if (target == NULL)
        return RETURN_WARN_ELEMENT_NOT_FOUND;

    previous->next = target->next;
    deleteElement(target);

    return RETURN_OK;
}
