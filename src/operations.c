#include <stdio.h>

#include "mvector.h"

Vector* v_add(Vector* v1, Vector* v2) {

    Vector *result;
    double *coords_r;

    double *coords1 = v1->coords;
    double *coords2 = v2->coords;

    unsigned int size1 = v1->size;
    unsigned int size2 = v2->size;

    if(size1 != size2) {
        return NULL;
    }

    result = v_create_zeroed(size1);
    coords_r = result->coords;

    for(unsigned int i = 0; i < size1; i++) {
        coords_r[i] = coords1[i] + coords2[i];
    }

    return result;
}

Vector* v_subtract(Vector* v1, Vector* v2) {

    Vector *result;
    double *coords_r;

    double *coords1 = v1->coords;
    double *coords2 = v2->coords;

    unsigned int size1 = v1->size;
    unsigned int size2 = v2->size;

    if(size1 != size2) {
        return NULL;
    }

    result = v_create_zeroed(size1);
    coords_r = result->coords;

    for(unsigned int i = 0; i < size1; i++) {
        coords_r[i] = coords1[i] - coords2[i];
    }

    return result;
}

Vector* v_scalar_mult(double scalar, Vector* v)
{
    Vector *result;
    double *coords_r;

    double *coords;
    unsigned int size;

    coords = v->coords;
    size = v->size;
    result = v_create_zeroed(size);
    coords_r = result->coords;

    for(unsigned int i = 0; i < size; i++) {
        coords_r[i] = scalar * coords[i];
    }

    return result;
}