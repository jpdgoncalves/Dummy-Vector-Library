#ifndef TRAIN_VECTOR
#define TRAIN_VECTOR

typedef struct
{
    unsigned int size;
    double coords[];
} Vector;

//Allocation
Vector* v_create_zeroed(unsigned int size);

Vector* v_create_from_coords(double* coords, unsigned int size);

Vector* v2d_create_from_ang_mag(double angle, double magnitude);

//Operations
Vector* v_add(Vector* v1, Vector* v2);

Vector* v_subtract(Vector* v1, Vector* v2);

Vector* v_scalar_mult(double scalar, Vector* v2);

//Calculations

double v_dot_product(Vector* v1, Vector* v2);

double v_magnitude(Vector* v);

Vector* v_normalize(Vector* v, double magnitude);

double v2d_angle(Vector* v);

double v2d_angle_between(Vector* v1, Vector* v2);

#endif