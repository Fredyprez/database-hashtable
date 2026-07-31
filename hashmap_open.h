#ifndef HASHMAP_OPEN_H

#define HASHMAP_OPEN_H
#include "student.h"

struct OpenHashData {
    struct Student** table;
    int* status;
};

void initOpenHashMap(struct HashMap* hashMapOpen);

struct OpenHashData* createOpenHashData(struct HashMap* hashMap);

void destroyOpenHashData(struct HashMap* hashMap);

int searchOpen(struct HashMap* hashMap, int searchKey);

void insertStudentOpen(struct HashMap* hashMap, int studentKey, char* studentName, char* studentEmail);
void removeStudentOpen(struct HashMap* hashMap, int removeKey);

void printOpenHashData(struct HashMap* hashMap);
void printStudentOpen(struct HashMap* hashMap, int searchKey);
#endif