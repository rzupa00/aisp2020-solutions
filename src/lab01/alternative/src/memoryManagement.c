/**
 * Memory management functions
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

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
