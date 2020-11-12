/**
 * Function declarations
 */
#ifndef FUNCTION_DECLARATIONS_H
#define FUNCTION_DECLARATIONS_H

#include "./internalDependencies.h"

/**
 * IO functions
 */
int printPolynomial(position);
int readPolynomialFromFile(position);

/**
 * Polynomial management functions
 */
int addValueToPolynomial(position, int, int);
int calculatePolynomialSum(position, position, position);
int calculatePolynomialProduct(position, position, position);
int deletePolynomial(position);

/**
 * Memory management
 */
position createNewElement(int value, int exponent);
int deleteElement(position);

#endif
