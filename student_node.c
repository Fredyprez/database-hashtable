#include "student.h"
#include "student_node.h"

#include <stdlib.h>

struct Node* createNode(struct Student* student){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->student = student;
    newNode->next = NULL;
    return newNode;
}
void destroyNode(struct Node** nodePtr){
    struct Node* node = *nodePtr;
    destroyStudent(&node->student);
    free(node);
    *nodePtr = NULL;
}

void printNode(struct Node* node){
    printStudent(node->student);
}