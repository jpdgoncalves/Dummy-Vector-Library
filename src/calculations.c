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

double v2d_angle(Vector *v)
{
    double angle;
    double *coords;
    
    if(v->size != 2) {
        return -361;
    }

    coords = v->coords;
    angle = atan2(coords[0], coords[1]);

    return angle;
}

double v2d_angle_between(Vector *v1, Vector *v2)
{
    double angle;
    double mag1;
    double mag2;
    double dot_product;

    if(v1->size != 2 || v2->size != 2) {
        return -361;
    }

    dot_product = v_dot_product(v1, v2);
    mag1 = v_magnitude(v1);
    mag2 = v_magnitude(v2);
    angle = acos(dot_product / (mag1 * mag2));

    return angle;
}