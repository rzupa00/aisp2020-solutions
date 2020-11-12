/**
 * List management functions
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

/**
 * Local function declarations
 */
int createElementAndInsert(position, int);
int insert(position, position);
int deleteNextElement(position);

/**
 * Add node to set (append or add new)
 * @param  head     Pointer to start of set
 * @param  value    Value to be added
 * @return          Result of operation
 */
int addValueToSet(position head, int value) {
    position previous = head;

    while (previous->next != NULL && previous->next->value < value)
        previous = previous->next;

    if (previous->next == NULL || previous->next->value < value)
        return createElementAndInsert(previous, value);

    return RETURN_OK;
}

/**
 * Calculate union of 2 sets
 * NOTE: Union is empty at beginning
 * @param  set1          First element of first set
 * @param  set2          First element of second set
 * @param  unionCurrent  Union to be calculated
 * @return               Result of operation
 */
int calculateSetUnion(position set1, position set2, position unionCurrent) {
    int result = 0;

    while (set1 != NULL && set2 != NULL) {
        if (set1->value < set2->value) {
            result = createElementAndInsert(unionCurrent, set1->value);
            set1 = set1->next;
        } else if (set1->value > set2->value) {
            result = createElementAndInsert(unionCurrent, set2->value);
            set2 = set2->next;
        } else {
            result = createElementAndInsert(unionCurrent, set1->value);
            set1 = set1->next;
            set2 = set2->next;
        }

        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        unionCurrent = unionCurrent->next;
    }

    while (set1 != NULL) {
        result = createElementAndInsert(unionCurrent, set1->value);
        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        set1 = set1->next;
        unionCurrent = unionCurrent->next;
    }

    while (set2 != NULL) {
        result = createElementAndInsert(unionCurrent, set2->value);
        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        set2 = set2->next;
        unionCurrent = unionCurrent->next;
    }

    return RETURN_OK;
}

/**
 * Calculate intersection of 2 sets
 * NOTE: Intersection is empty at beginning
 * @param  set1          First element of first polynomial
 * @param  set2          First element of second polynomial
 * @param  intersection  Intersection to be calculated
 * @return               Result of operation
 */
int calculateSetIntersection(position set1, position set2, position intersection) {
    int result = 0;

    while (set1 != NULL && set2 != NULL) {
        if (set1->value == set2->value) {
            result = createElementAndInsert(intersection, set1->value);
            if (result == RETURN_ERROR_ALLOC_FAILED)
                return RETURN_ERROR_ALLOC_FAILED;

            set1 = set1->next;
            set2 = set2->next;
            intersection = intersection->next;
        } else if (set1->value < set2->value) {
            set1 = set1->next;
        } else {
            set2 = set2->next;
        }
    }

    return RETURN_OK;
}

/**
 * Delete set
 * @param set  Head of set
 * @return     Result of operation
 */
int deleteSet(position set) {
    while (set->next != NULL)
        deleteNextElement(set);

    return RETURN_OK;
}

/**
 * Local functions
 */

/**
 * Allocate memory for new element and add it to list right after the desired element
 * @param  previous  Element after which the new element will be located
 * @param  value     Value to be added
 * @return           Result of operation
 */
int createElementAndInsert(position previous, int value) {
    position target = createNewElement(value);
    if (target == NULL)
        return RETURN_ERROR_ALLOC_FAILED;

    return insert(previous, target);
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
 * Delete next element in polynomial
 * @param  previous Previous element of the element to be deleted
 * @return          Result of operation
 */
int deleteNextElement(position previous) {
    position target = previous->next;

    if (target == NULL)
        return RETURN_OK;

    previous->next = target->next;
    deleteElement(target);

    return RETURN_OK;
}
