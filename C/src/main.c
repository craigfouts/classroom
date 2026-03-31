#include <stdio.h>
#include <stdlib.h>

void test(int a[][4], int len) {
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < 4; ++j)
            printf("%d\n", a[i][j]);
}

int main(void) {
    int f[][4] = {
        {1, 4, 3, 2},
        {4, 6, 1, 6}
    };

    test(f, 2);

    return 0;
}
