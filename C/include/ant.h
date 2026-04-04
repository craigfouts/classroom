#ifndef ANT_H
#define ANT_H

#include "stdlib.h"
#include "string.h"

struct AntAPI;

typedef struct {
    const struct AntAPI *api;
    char *name;
} Ant;

extern const struct AntAPI {
    Ant *(*new)(const char *name);
    void (*del)(Ant *ant);
    char *(*getName)(Ant *ant);
    void (*setName)(Ant *ant, const char *name);
} antAPI;

#endif
