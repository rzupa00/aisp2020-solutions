/**
 * Data collections used in application
 */
#ifndef DATA_COLLECTIONS_H
#define DATA_COLLECTIONS_H

struct _polynomial;
typedef struct _polynomial polynomial;
typedef polynomial* position;
struct _polynomial {
    int value;
    int exponent;

    position next;
};

#endif
