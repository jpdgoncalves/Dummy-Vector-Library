#include <stdlib.h>

#include "mvector.h"

Vector* v_create_zeroed(unsigned int size) {

    Vector *v = malloc(sizeof(Vector) + size * sizeof(double));
    v->size = size;

    return v;
}

Vector* v_create_from_coords(double *coords, unsigned int size)
{
    Vector *v = v_create_zeroed(size);
    
    for(unsigned int i = 0; i < size; i++) {
        v->coords[i] = coords[i];
    }

    return v;
}