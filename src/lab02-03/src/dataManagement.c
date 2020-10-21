/**
 * Data management functions
 */

#include "../headers/internalDependencies.h"

/**
 * Allocate memory for new element and fill it with data
 * @param  firstName   First name
 * @param  lastName    Last name
 * @param  yearOfBirth Year of birth
 * @return             Newly allocated element (or NULL if allocation failed)
 */
position createNewElement(char* firstName, char* lastName, int yearOfBirth) {
    position target = NULL;

    target = (position) malloc(sizeof(person));
    if (target == NULL)
        return NULL;

    strcpy(target->firstName, firstName);
    strcpy(target->lastName, lastName);
    target->yearOfBirth = yearOfBirth;
    target->next = NULL;

    return target;
}

/**
 * Deallocate memory of target element
 * @param  target Target element
 * @return        Result of operation
 */
int deleteElement(position target) {
    free(target);
    return RETURN_OK;
}
