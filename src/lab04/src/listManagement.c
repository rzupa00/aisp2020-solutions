/**
 * List management functions
 */

#include "../headers/internalDependencies.h"
#include "../headers/externalDependencies.h"

/**
 * Local function declarations
 */
int createElementAndInsert(position, int, int);
int insert(position, position);
int deleteNextElement(position);

/**
 * Add node to polynomial (append or add new)
 * @param  head     Pointer to start of polynomial
 * @param  value    Value to be added
 * @param  exponent Exponent to be added
 * @return          Result of operation
 */
int addValueToPolynomial(position head, int value, int exponent) {
    position previous = head;

    while (previous->next != NULL && previous->next->exponent > exponent)
        previous = previous->next;

    if (previous->next == NULL || previous->next->exponent < exponent)
        return createElementAndInsert(previous, value, exponent);

    previous->next->value += value;
    return RETURN_OK;
}

/**
 * Calculate sum of 2 polynomials
 * NOTE: Sum is empty at beginning
 * @param  poly1  First element of first polynomial
 * @param  poly2  First element of second polynomial
 * @param  sum    Sum to be calculated
 * @return        Result of operation
 */
int calculatePolynomialSum(position poly1, position poly2, position sum) {
    int result = 0;

    while(poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            result = createElementAndInsert(sum, poly1->value, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = createElementAndInsert(sum, poly2->value, poly2->exponent);
            poly2 = poly2->next;
        } else {
            result = createElementAndInsert(sum, poly1->value + poly2->value, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        sum = sum->next;
    }

    while (poly1 != NULL) {
        result = createElementAndInsert(sum, poly1->value, poly1->exponent);
        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        poly1 = poly1->next;
        sum = sum->next;
    }

    while (poly2 != NULL) {
        result = createElementAndInsert(sum, poly2->value, poly2->exponent);
        if (result == RETURN_ERROR_ALLOC_FAILED)
            return RETURN_ERROR_ALLOC_FAILED;

        poly2 = poly2->next;
        sum = sum->next;
    }

    return RETURN_OK;
}

/**
 * Calculate product of 2 polynomials
 * NOTE: Product is empty at beginning
 * @param  poly1    First element of first polynomial
 * @param  poly2    First element of second polynomial
 * @param  product  Product to be calculated
 * @return          Result of operation
 */
int calculatePolynomialProduct(position poly1, position poly2, position product) {
    int result = 0;
    position bookmark = poly2;


    while (poly1 != NULL) {
        poly2 = bookmark;

        while (poly2 != NULL) {
            result = addValueToPolynomial(
                product,
                poly1->value * poly2->value,
                poly1->exponent + poly2->exponent);

            if (result == RETURN_ERROR_ALLOC_FAILED)
                return RETURN_ERROR_ALLOC_FAILED;

            poly2 = poly2->next;
        }

        poly1 = poly1->next;
    }

    return RETURN_OK;
}

/**
 * Delete polynomial
 * @param  poly Head of list
 * @return      Result of operation
 */
int deletePolynomial(position poly) {
    while (poly->next != NULL)
        deleteNextElement(poly);

    return RETURN_OK;
}

/**
 * Local functions
 */

/**
 * Allocate memory for new element and add it to list right after the desired element
 * @param  previous    Element after which the new element will be located
 * @param  value       Value to be added
 * @param  lastName    Exponent to be added
 * @return             Result of operation
 */
int createElementAndInsert(position previous, int value, int exponent) {
    position target = createNewElement(value, exponent);
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
