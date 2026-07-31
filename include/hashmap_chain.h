#ifndef HASHMAP_CHAIN_H

#define HASHMAP_CHAIN_H
#include "student.h"
#include "linkedlist.h"

struct ChainHashData {
    struct LinkedList* buckets;
};

void initChainHashMap(struct HashMap* hashMapChain);

struct ChainHashData* createChainHashData(struct HashMap* map);

void destroyChainHashData(struct HashMap* hashMap);

int searchChain(struct HashMap* hashMap, int searchKey);

void insertStudentChain(struct HashMap* hashMap, int studentKey, char* studentName, char* studentEmail);
void removeStudentChain(struct HashMap* hashMap, int removeKey);

void printChainHashData(struct HashMap* hashMap);
void printStudentChain(struct HashMap* hashMap, int searchKey);
#endif