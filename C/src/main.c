#include "../include/ant.h"
#include "stdio.h"
#include "stdlib.h"

int main(void) {
    Ant *ant = antAPI.new("Craig");

    printf("Name 1: %s\n", antAPI.getName(ant));

    antAPI.setName(ant, "Xinyang");

    printf("Name 2: %s\n", antAPI.getName(ant));

    antAPI.del(ant);

    return 0;
}
