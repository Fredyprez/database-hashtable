#ifndef STUDENT_NODE_H

#define STUDENT_NODE_H
#include "student.h"
struct Node {
    struct Student* student;
    struct Node* next;
};

struct Node* createNode(struct Student* student);
void destroyNode(struct Node** nodePtr);
void printNode(struct Node* node);










#endif