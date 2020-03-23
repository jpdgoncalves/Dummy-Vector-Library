#include <stdio.h>
#include <math.h>

#include "mvector.h"

double v_dot_product(Vector *v1, Vector *v2)
{
    double result = 0;
    double *coords1 = v1->coords;
    double *coords2 = v2->coords;
    unsigned int size = v1->size;

    if(v1->size != v2->size) {
        return 0;
    }

    for(unsigned int i = 0; i < size; i++) {
        result += coords1[i] * coords2[i];
    }
    
    return result;
}

double v_magnitude(Vector *v)
{
    double total = 0;
    double *coords = v->coords;
    unsigned int size = v->size;

    for(unsigned int i = 0; i < size; i++) {
        double coord = coords[i];
        total += coord * coord;
    }

    return sqrt(total);
}

Vector* v_normalize(Vector *v, double magnitude) {
    
    Vector *normalized = v_create_zeroed(v->size);
    double *n_coords = normalized->coords;
    double *coords = v->coords;
    double prev_magnitude;
    double ratio;
    unsigned int size = v->size;

    prev_magnitude = v_magnitude(v);
    ratio = magnitude / prev_magnitude;

    for(unsigned int i = 0; i < size; i++) {
        n_coords[i] = coords[i] * ratio;
    }

    return normalized;
}