#include <stdlib.h>
#include <math.h>

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

Vector* v2d_create_from_ang_mag(double angle, double magnitude)
{
    Vector *v;
    Vector *temp;
    double coords[2] = { sin(angle) , cos(angle) };

    temp = v_create_from_coords(coords, 2);
    v = v_normalize(temp, magnitude);

    free(temp);
    return v;
}