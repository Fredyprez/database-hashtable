#ifndef HASHMAP_CHAIN_H

#define HASHMAP_CHAIN_H
#include "student.h"

struct ChainHashData {
    struct Student** table;
    int* status;
};

void initChainHashMap(struct HashMap* hashMapChain);

struct ChainHashData* createChainHashData(struct HashMap* map);

void destroyChainHashData(struct HashMap* hashMap);

int searchChain(struct HashMap* map, int searchKey);

void insertStudentChain(struct HashMap* map, int studentKey, char* studentName, char* studentEmail);
void removeStudentChain(struct HashMap* map, int removeKey);

void printChainHashData(struct HashMap* hashMap);
void printStudentChain(struct HashMap* hashMap, int searchKey);
#endif