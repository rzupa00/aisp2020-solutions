/**
 * Data collections used in application
 */
#ifndef DATA_COLLECTIONS_H
    #define DATA_COLLECTIONS_H

    #include "./internalDependencies.h"

    struct _person;
    typedef struct _person person;
    typedef person* position;
    struct _person {
        char firstName[FIRST_NAME_LENGTH];
        char lastName[LAST_NAME_LENGTH];
        int yearOfBirth;

        position next;
    };

#endif // DATA_COLLECTIONS_H
