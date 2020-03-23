#include <stdio.h>
#include <stdlib.h>

#include "../build/mvector.h"

void print_vector(Vector *v) {
    printf("Vector size=%d: (", v->size);

    for(unsigned int i = 0; i < v->size; i++) {
        printf("%f", v->coords[i]);
        if(i < v->size - 1) {
            printf(",");
        }
    }

    printf(")\n");
}

void test_operations() {

    Vector *v1;
    Vector *v2;
    Vector *result;

    double coords[2];
    unsigned int size;

    size = 2;
    coords[0] = 3;
    coords[1] = 4;
    v1 = v_create_from_coords(coords, size);

    coords[0] = 2;
    coords[1] = 1;
    v2 = v_create_from_coords(coords, size);

    printf("Testing operations\n");
    print_vector(v1);
    print_vector(v2);

    result = v_add(v1, v2);
    print_vector(result);
    free(result);

    result = v_subtract(v1, v2);
    print_vector(result);
    free(result);

    result = v_scalar_mult(2, v1);
    print_vector(result);
    free(result);

    free(v1);
    free(v2);

}

void test_calculations() {
    
    Vector *v1;
    Vector *v2;
    Vector *result;

    double coords[2];
    unsigned int size;

    size = 2;
    coords[0] = 3;
    coords[1] = 4;
    v1 = v_create_from_coords(coords, size);

    coords[0] = 2;
    coords[1] = 1;
    v2 = v_create_from_coords(coords, size);
    
    printf("Testing calculations\n");
    print_vector(v1);
    print_vector(v2);

    double dot_product = v_dot_product(v1, v2);
    printf("v1 . v2 = %f\n", dot_product);

    double magnitude = v_magnitude(v1);
    printf("Magnitude of v1 = %f\n", magnitude);

    result = v_normalize(v1, 2);
    double n_magnitude = v_magnitude(result);
    print_vector(result);
    printf("Normalized magnitude = %f\n", n_magnitude);
    free(result);

    free(v1);
    free(v2);
}

int main(void) {

    double coords[2] = {3,4};
    unsigned int size = 2;

    Vector *v = v_create_from_coords(coords, size);

    print_vector(v);

    free(v);

    test_operations();
    test_calculations();

    return 0;
}