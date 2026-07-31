#include "hashmap.h"
#include "hashmap_chain.h"
#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>

#define COLLISIONS 0

void initChainHashMap(struct HashMap* hashMap){
    hashMap->hashData = createChainHashData(hashMap);
    hashMap->insertStudent = insertStudentChain;
    hashMap->removeStudent = removeStudentChain;
    hashMap->searchStudent = searchChain;
    hashMap->printHashMap = printChainHashData;
    hashMap->printStudent = printStudentChain;
}

struct ChainHashData* createChainHashData(struct HashMap* hashMap){
    struct ChainHashData* dataChain = (struct ChainHashData*)malloc(sizeof(struct ChainHashData));
    hashMap->hashData = dataChain;
    dataChain->buckets = (struct LinkedList*)calloc(hashMap->tableSize, sizeof(struct LinkedList));
    return dataChain;
}

void initChainHashData(struct ChainHashData* data, int size){
    struct LinkedList* bucket = NULL;
    for (int i = 0; i < size; i++){
        bucket = &data->buckets[i];
    }
}

void destroyChainHashData(struct HashMap* hashMap){
    struct ChainHashData* data = hashMap->hashData;
    for (int i = 0; i < hashMap->tableSize; i++){
        struct LinkedList* list = &data->buckets[i];
        destroyList(&list);
    }
    free(data->buckets);
    free(data);
}
int searchChain(struct HashMap* hashMap, int searchKey){
    int index = hash(searchKey, hashMap->tableSize, COLLISIONS);
    struct ChainHashData* data = hashMap->hashData;
    struct LinkedList* bucket = &data->buckets[index];
    struct Node* node = searchListPrev(bucket, searchKey);
    if (node == NULL) return -1;
    node = node->next;
    return index;
}

void insertStudentChain(struct HashMap* hashMap, int studentKey, char* studentName, char* studentEmail){
    struct Student* student = createStudent(studentKey, studentName, studentEmail);
    struct ChainHashData* data = hashMap->hashData;
    int index = hash(student->key, hashMap->tableSize, COLLISIONS);
    struct LinkedList* bucket = &data->buckets[index];
    insertListNode(bucket, student);
}

void removeStudentChain(struct HashMap* hashMap, int removeKey){
    struct ChainHashData* data = hashMap->hashData;
    int index = hash(removeKey, hashMap->tableSize, COLLISIONS);
    struct LinkedList* bucket = &data->buckets[index];
    removeListNode(bucket, removeKey);
}

void printChainHashData(struct HashMap* hashMap){
    struct ChainHashData* data = hashMap->hashData;
    struct LinkedList* bucket = NULL;
    for (int i = 0; i < hashMap->tableSize; i++){
        bucket = &data->buckets[i];
        printList(bucket);
    }
}
void printStudentChain(struct HashMap* hashMap, int searchKey){
    int index = hash(searchKey, hashMap->tableSize, COLLISIONS);
    struct ChainHashData* data = hashMap->hashData;
    struct LinkedList* bucket = &data->buckets[index];
    printListNode(bucket, searchKey);
}