/**
 * Data management functions
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

/**
 * Allocate memory for new element and fill it with data
 * @param  value  Value
 * @return        Newly allocated element (or NULL if allocation failed)
 */
position createNewElement(int value) {
    position target = NULL;

    target = (position) malloc(sizeof(set));
    if (target == NULL)
        return NULL;

    target->value = value;
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
