#include "student.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char* strdup(const char *s); - This function returns a pointer to a null-terminated byte string, 
//which is a duplicate of the string pointed to by s. 
//The memory obtained is done dynamically using malloc and hence it can be freed using free().

struct Student* createStudent(int addKey, char* addName, char* addEmail){
    struct Student* newStudent = malloc(sizeof(struct Student));
    newStudent->key = addKey; newStudent->name = strdup(addName); newStudent->email = strdup(addEmail);
    return newStudent;
}

void destroyStudent(struct Student** studentPtr){
    if (studentPtr == NULL || *studentPtr == NULL) return;
    else {
        struct Student* removeStudent = *studentPtr;
        free(removeStudent->name); 
        free(removeStudent->email); 
        free(removeStudent);
        *studentPtr = NULL;
    }
}

void printStudent(struct Student* student){
    if (student == NULL){ 
        printf("Student does not exist\n");
    }
    else {
        printf("Id: %d\tName: %s\tEmail: %s\n",
            student->key,
            student->name,
            student->email);
    }
}