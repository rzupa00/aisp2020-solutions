/**
 * Collections of data used in application
 */
#ifndef DATA_COLLECTIONS_H
    #define DATA_COLLECTIONS_H

    #include "./internalDependencies.h"

    struct _person;
    typedef struct _person person;
    struct _person {
        char firstName[NAME_LENGTH];
        char lastName[NAME_LENGTH];

        double absGrade;
        double relGrade;
    };

#endif // DATA_COLLECTIONS_H
