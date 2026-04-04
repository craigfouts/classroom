#include "../include/ant.h"

static Ant *_new(const char *name);
static void _del(Ant *ant);
static char *_getName(Ant *ant);
static void _setName(Ant *ant, const char *name);

const struct AntAPI antAPI = {
    .new = &_new,
    .del = &_del,
    .getName = &_getName,
    .setName = &_setName
};

static Ant *_new(const char *name) {
    Ant *ant = malloc(sizeof(Ant));
    ant->api = &antAPI;
    ant->name = malloc(strlen(name));
    strcpy(ant->name, name);

    return ant;
}

static void _del(Ant *ant) {
    free(ant->name);
    free(ant);
}

static char *_getName(Ant *ant) {
    return ant->name;
}

static void _setName(Ant *ant, const char *name) {
    ant->name = realloc(ant->name, strlen(name));
    strcpy(ant->name, name);
}
