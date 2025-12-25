#include <stdio.h>
#include <stdlib.h>
#include "GLFW/glfw3.h"
#include "../include/utils.h"

int main(void) {
    size_t size = 5;
    double *arr = zeros(size);

    if (arr) {
        for (size_t i = 0; i < size; ++i)
            printf("Element %zu: %f\n", i, arr[i]);

        free(arr);
    }

    return 0;
}
