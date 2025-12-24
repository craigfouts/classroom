#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t i;
    [[maybe_unused]] int j;
    double A[5] = {
        9.0,
        2.9,
        3.E+25,
        .00007
    };

    for (i = 0; i < 5; ++i) {
        printf("Element %zu is %g, \tits square is %g\n", i, A[i], A[i]*A[i]);
    }

    return 0;
}
