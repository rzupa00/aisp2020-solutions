/**
 * Main function, application entry
 */

#include "../headers/internalDependencies.h"
#include "../headers/externalDependencies.h"

/**
 * Main function
 * @param  argc Argument counter
 * @param  argv Argument list
 * @return      Execution result
 */
int main(int argc, char** argv) {
    int result = 0;

    polynomial poly1;
    polynomial poly2;
    polynomial sum;
    polynomial product;

    poly1.value = 0;
    poly1.exponent = 0;
    poly1.next = NULL;

    poly2.value = 0;
    poly2.exponent = 0;
    poly2.next = NULL;

    sum.value = 0;
    sum.exponent = 0;
    sum.next = NULL;

    product.value = 0;
    product.exponent = 0;
    product.next = NULL;

    printf("Reading first polynomial...\n");
    do {
        result = readPolynomialFromFile(&poly1);
        if (result == RETURN_OK) {
            printf("First polynomial successfully read!\n");
        } else if (result == RETURN_WARN_FILE_NOT_OPENED) {
            printf("NOTE: File could not be opened!\n");
            printf("Please check that the file name (with path and extension) is correctly entered, and try again!!!\n");
        } else if (result == RETURN_ERROR_ALLOC_FAILED) {
            printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
            printf("Clearing out data...\n");
            deletePolynomial(&poly1);
            return RETURN_OK;
        }
    } while (result != RETURN_OK);

    printf("Reading second polynomial...\n");
    do {
        result = readPolynomialFromFile(&poly2);
        if (result == RETURN_OK) {
            printf("Second polynomial successfully read!\n");
        } else if (result == RETURN_WARN_FILE_NOT_OPENED) {
            printf("NOTE: File could not be opened!\n");
            printf("Please check that the file name (with path and extension) is correctly entered, and try again!!!\n");
        } else if (result == RETURN_ERROR_ALLOC_FAILED) {
            printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
            printf("Clearing out data...\n");
            deletePolynomial(&poly1);
            deletePolynomial(&poly2);
            return RETURN_OK;
        }
    } while (result != RETURN_OK);

    printf("Calculating sum of polynomials...\n");
    result = calculatePolynomialSum(poly1.next, poly2.next, &sum);
    if (result == RETURN_OK) {
        printf("Sum successfully calculated");
    } else if (result == RETURN_ERROR_ALLOC_FAILED) {
        printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
        printf("Clearing out data...\n");
        deletePolynomial(&poly1);
        deletePolynomial(&poly2);
        deletePolynomial(&sum);
        return RETURN_OK;
    }

    printf("Calculating product of polynomials...\n");
    result = calculatePolynomialProduct(poly1.next, poly2.next, &product);
    if (result == RETURN_OK) {
        printf("Product successfully calculated");
    } else if (result == RETURN_ERROR_ALLOC_FAILED) {
        printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
        printf("Clearing out data...\n");
        deletePolynomial(&poly1);
        deletePolynomial(&poly2);
        deletePolynomial(&sum);
        deletePolynomial(&product);
        return RETURN_OK;
    }

    printf("Printing results...\n");

    printf("#######\n");
    printf("Polynomial 1:\n");
    printPolynomial(poly1.next);

    printf("#######\n");
    printf("Polynomial 2:\n");
    printPolynomial(poly2.next);

    printf("#######\n");
    printf("Sum:\n");
    printPolynomial(sum.next);

    printf("#######\n");
    printf("Product:\n");
    printPolynomial(product.next);

    printf("Clearing out data...\n");
    deletePolynomial(&poly1);
    deletePolynomial(&poly2);
    deletePolynomial(&sum);
    deletePolynomial(&product);

    printf("Exiting application...\n");
    return RETURN_OK;
}
