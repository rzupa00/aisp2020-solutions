/**
 * Data management functions
 */

#include "../headers/internalDependencies.h"
#include "../headers/externalDependencies.h"

/**
 * Allocate memory for new element and fill it with data
 * @param  value     Value
 * @param  exponent  Exponent
 * @return           Newly allocated element (or NULL if allocation failed)
 */
position createNewElement(int value, int exponent) {
    position target = NULL;

    target = (position) malloc(sizeof(polynomial));
    if (target == NULL)
        return NULL;

    target->value = value;
    target->exponent = exponent;
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
