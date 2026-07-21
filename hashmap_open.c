#include "hashmap.h"
#include "hashmap_open.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initOpenHashMap(struct HashMap* hashMapOpen){
    hashMapOpen->hashData = createOpenHashData(hashMapOpen);
    hashMapOpen->insertStudent = insertStudentOpen;
    hashMapOpen->removeStudent = removeStudentOpen;
    hashMapOpen->searchStudent = searchOpen;
    hashMapOpen->printHashMap = printOpenHashData;
    hashMapOpen->printStudent = printStudentOpen;
}

struct OpenHashData* createOpenHashData(struct HashMap* hashMap){
    struct OpenHashData* dataOpen = malloc(sizeof(struct OpenHashData));
    hashMap->hashData = dataOpen;
    dataOpen->status = calloc(hashMap->tableSize, sizeof(int));
    dataOpen->table = calloc(hashMap->tableSize, sizeof(struct Student*));
    return dataOpen;
}

void destroyOpenHashData(struct HashMap* hashMap){
    struct OpenHashData* data = hashMap->hashData;
    for (int i = 0; i < hashMap->tableSize; i++){
        if (data->table[i] != NULL){
            destroyStudent(&data->table[i]);
        }
    }
    free(data->status);
    free(data->table);
    free(data);
}

int searchOpen(struct HashMap* hashMap, int searchKey){
    int collisions = 0; 
    bool found = false;
    struct OpenHashData* data = hashMap->hashData;
    int index = hash(searchKey, hashMap->tableSize, collisions);
    while (data->status[index] != 0 && collisions < hashMap->tableSize/2 && found == false){
        if (data->status[index] == 1  && data->table[index]->key == searchKey) found = true;
        else {
            collisions += 1;
            index = hash(searchKey, hashMap->tableSize, collisions);
        }
    }
        if (found == true) return index;
        else return -1;
}

void insertStudentOpen(struct HashMap* hashMap, int studentKey, char* studentName, char* studentEmail){
    struct Student* addStudent = createStudent(studentKey, studentName, studentEmail);
    int collisions = 0;
    int index = hash(addStudent->key, hashMap->tableSize, collisions);
    struct OpenHashData* data = hashMap->hashData;
    while (data->status[index] == 1 && collisions < hashMap->tableSize/2){
        collisions += 1;
        index = hash(addStudent->key, hashMap->tableSize, collisions);
    }
    if (data->status[index] != 1){
        data->table[index] = addStudent;
        data->status[index] = 1;
    }
}

void removeStudentOpen(struct HashMap* hashMap, int removeKey){
    struct OpenHashData* data = hashMap->hashData;
    int index = searchOpen(hashMap, removeKey);
    if (index == -1) printf("Student does not exist\n");
    else {
        destroyStudent(&data->table[index]);
        data->status[index] = -1;
    }
}

void printOpenHashData(struct HashMap* hashMap){
    if (hashMap == NULL) return;
    struct OpenHashData* data = hashMap->hashData;
    for (int i = 0; i < hashMap->tableSize; i++){
        if (data->status[i] == 1){
            printf("[%d] OCUPY and status is %d\tId: %d\tName: %s\tEmail: %s\n",
                i,
                data->status[i],
                data->table[i]->key,
                data->table[i]->name,
                data->table[i]->email);
        }
        else printf("[%d] EMPTY and status is %d\n", i, data->status[i]);
    }
}
void printStudentOpen(struct HashMap* hashMap, int searchKey){
    if (hashMap == NULL) return;
    int printIndex = searchOpen(hashMap, searchKey);
    struct OpenHashData* data = hashMap->hashData;
    if (printIndex == -1 || printIndex == 0) printf("Student does not exist\n");
    else printf("[%d] OCUPY and status is %d\tId: %d\tName: %s\tEmail: %s\n",
                printIndex,
                data->status[printIndex],
                data->table[printIndex]->key,
                data->table[printIndex]->name,
                data->table[printIndex]->email);
}