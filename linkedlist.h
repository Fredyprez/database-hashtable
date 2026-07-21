#include "hashmap.h"

struct Node {
    struct Student* student;
    struct Node* next;
};

struct Node* createNode(struct Student* student);