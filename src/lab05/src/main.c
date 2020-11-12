/**
 * Main function, application entry
 */

#include "../headers/externalDependencies.h"
#include "../headers/internalDependencies.h"

/**
 * Main function
 * @param  argc Argument counter
 * @param  argv Argument list
 * @return      Execution result
 */
int main(int argc, char** argv) {
    int result = 0;

    set set1Head;
    set set2Head;
    set unionHead;
    set intersectionHead;

    set1Head.value = 0;
    set1Head.next = NULL;

    set2Head.value = 0;
    set2Head.next = NULL;

    unionHead.value = 0;
    unionHead.next = NULL;

    intersectionHead.value = 0;
    intersectionHead.next = NULL;

    printf("Reading first set...\n");
    do {
        result = readSetFromFile(&set1Head);
        if (result == RETURN_OK) {
            printf("First set successfully read!\n");
        } else if (result == RETURN_WARN_FILE_NOT_OPENED) {
            printf("NOTE: File could not be opened!\n");
            printf("Please check that the file name (with path and extension) is correctly entered, and try again!!!\n");
        } else if (result == RETURN_ERROR_ALLOC_FAILED) {
            printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
            printf("Clearing out data...\n");
            deleteSet(&set1Head);
            return RETURN_OK;
        }
    } while (result != RETURN_OK);

    printf("Reading second set...\n");
    do {
        result = readSetFromFile(&set2Head);
        if (result == RETURN_OK) {
            printf("Second set successfully read!\n");
        } else if (result == RETURN_WARN_FILE_NOT_OPENED) {
            printf("NOTE: File could not be opened!\n");
            printf("Please check that the file name (with path and extension) is correctly entered, and try again!!!\n");
        } else if (result == RETURN_ERROR_ALLOC_FAILED) {
            printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
            printf("Clearing out data...\n");
            deleteSet(&set1Head);
            deleteSet(&set2Head);
            return RETURN_OK;
        }
    } while (result != RETURN_OK);

    printf("Calculating union of sets...\n");
    result = calculateSetUnion(set1Head.next, set2Head.next, &unionHead);
    if (result == RETURN_OK) {
        printf("Union successfully calculated");
    } else if (result == RETURN_ERROR_ALLOC_FAILED) {
        printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
        printf("Clearing out data...\n");
        deleteSet(&set1Head);
        deleteSet(&set2Head);
        deleteSet(&unionHead);
        return RETURN_OK;
    }

    printf("Calculating intersection of sets...\n");
    result = calculateSetIntersection(set1Head.next, set2Head.next, &intersectionHead);
    if (result == RETURN_OK) {
        printf("Intersection successfully calculated");
    } else if (result == RETURN_ERROR_ALLOC_FAILED) {
        printf("ERROR: There was an error with memory handling, so the application must terminate!\n");
        printf("Clearing out data...\n");
        deleteSet(&set1Head);
        deleteSet(&set2Head);
        deleteSet(&unionHead);
        deleteSet(&intersectionHead);
        return RETURN_OK;
    }

    printf("Printing results...\n");

    printf("#######\n");
    printf("Set 1:\n");
    printSet(set1Head.next);

    printf("#######\n");
    printf("Set 2:\n");
    printSet(set2Head.next);

    printf("#######\n");
    printf("Union:\n");
    printSet(unionHead.next);

    printf("#######\n");
    printf("Intersection:\n");
    printSet(intersectionHead.next);

    printf("Clearing out data...\n");
    deleteSet(&set1Head);
    deleteSet(&set2Head);
    deleteSet(&unionHead);
    deleteSet(&intersectionHead);

    printf("Exiting application...\n");
    return RETURN_OK;
}
