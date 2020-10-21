/**
 * Public functions declarations
 */
#ifndef FUNCTION_DECLARATIONS_H
    #define FUNCTION_DECLARATIONS_H

    // IO functions
    person* readDataFromFile(int*, double*);
    int printDataToConsole(person*, const int);

    // Memory management functions
    person* allocMemory(const int);
    int deallocMemory(person*);

    // Utility functions
    int calculateRelativeGrade(person*, const int, const double);

#endif // FUNCTION_DECLARATIONS_H
