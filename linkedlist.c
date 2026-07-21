#include <stdlib.h>
#include "student.c"
#include "linkedlist.h"

struct Node* createNode(struct Student* student){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->student = student;
    newNode->next = NULL;
    return newNode;
}

void destroyNode(struct Node** nodePtr){
    if (nodePtr == NULL || *nodePtr == NULL) return;
    struct Node* removeNode = *nodePtr;
    destroyStudent(&(removeNode->student));
    free(removeNode);
    *nodePtr = NULL;
}

