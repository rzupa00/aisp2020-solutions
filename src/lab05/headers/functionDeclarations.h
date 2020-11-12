/**
 * Function declarations
 */
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    #include "./internalDependencies.h"

    /**
     * IO functions
     */
    int printSet(position);
    int readSetFromFile(position);

    /**
     * Set management functions
     */
    int addValueToSet(position, int);
    int calculateSetUnion(position, position, position);
    int calculateSetIntersection(position, position, position);
    int deleteSet(position);

    /**
     * Memory management
     */
    position createNewElement(int);
    int deleteElement(position);
#endif
