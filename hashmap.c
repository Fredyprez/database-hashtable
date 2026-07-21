#include "hashmap.h"
#include "hashmap_open.h"

#include <stdlib.h>

int hashOne(int key, int size){
    return key % size;
}

int hashTwo(int key){
    return key % 7;
}

int hash(int key, int size, int collisions){
    int initIndex = hashOne(key, size);
    int index = initIndex + collisions*hashTwo(key);
    return index % size;
}

struct HashMap* initHashMap(enum type implementation, int size){
    struct HashMap* hashMap = NULL;
    switch (implementation){
        case OPEN:
            hashMap = createHashMap(size);
            initOpenHashMap(hashMap);
            hashMap->implementation = implementation;
            break;
        case CHAIN:
            break;
    }
    return hashMap;
}

struct HashMap* createHashMap(int size){
    struct HashMap* hashMap = (struct HashMap*)malloc(sizeof(struct HashMap));
    hashMap->tableSize = size;
    return hashMap;
}

void destroyHashMap(struct HashMap** mapPtr){
    if (mapPtr == NULL || *mapPtr == NULL) return;
    struct HashMap* removeMap = *mapPtr;
    switch (removeMap->implementation){
        case OPEN:
            destroyOpenHashData(removeMap);
            break;
        case CHAIN:
            break;
    }
    free(removeMap);
    *mapPtr = NULL;
}