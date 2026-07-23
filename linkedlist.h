#ifndef LINKEDLIST_H

#define LINKEDLIST_H
#include "student_node.h"

struct LinkedList {
    struct Node* head;
    struct Node* tail;
    int sizeList;
};
struct LinkedList* createList();
void insertListNode(struct LinkedList* list, struct Student* student);
void removeListNode(struct LinkedList* list, int searchKey);
struct Node* searchList(struct LinkedList* list, int searchKey);
void destroyList(struct LinkedList** listPtr);
void printList(struct LinkedList* list);
#endif