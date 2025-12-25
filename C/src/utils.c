#include <stdlib.h>
#include "../include/utils.h"

double *ones(size_t size) {
    double *out = malloc(size*sizeof(double));
    
    if (!out) 
        return NULL;

    for (size_t i = 0; i < size; ++i)
        out[i] = 1.0;

    return out;
}

double *zeros(size_t size) {
    double *out = malloc(size*sizeof(double));

    if (!out)
        return NULL;

    for (size_t i = 0; i < size; ++i)
        out[i] = 0.0;

    return out;
}
