/**
 * Data collections used in application
 */
#ifndef DATA_COLLECTIONS_H
    #define DATA_COLLECTIONS_H

    #include "./internalDependencies.h"

    struct _set;
    typedef struct _set set;
    typedef set* position;
    struct _set {
        int value;

        position next;
    };

#endif
