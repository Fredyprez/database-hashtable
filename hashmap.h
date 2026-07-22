#ifndef HASHMAP_H

#define HASHMAP_H

#include "student.h"

enum type {
    OPEN, CHAIN //add whatever implementation type
};

struct HashMap {
    void* hashData;

    void (*insertStudent)(struct HashMap*, int, char*, char*);
    void (*removeStudent)(struct HashMap*, int);
    int (*searchStudent)(struct HashMap*, int);
    void (*printHashMap)(struct HashMap*);
    void (*printStudent)(struct HashMap*, int);

    int tableSize;
    enum type implementation;
};

int hashOne(int key, int size);
int hashTwo(int key);
int hash(int key, int size, int collisions);

struct HashMap* initHashMap(enum type implementation, int size);
struct HashMap* createHashMap(int size);
void destroyHashMap(struct HashMap** map);
#endif