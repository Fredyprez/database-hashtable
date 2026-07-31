#include "linkedlist.h"

#include <stdlib.h>

struct LinkedList* createList() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->sizeList = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertListNode(struct LinkedList* list, struct Student* student){
    struct Node* insertNode = createNode(student);
    if (list->head == NULL){
        list->head = insertNode;
        list->tail = insertNode;
    }
    else {
        list->tail->next = insertNode;
        list->tail = insertNode;
    }
    list->sizeList++;
}

void removeListNode(struct LinkedList* list, int searchKey){
    struct Node* prev = searchListPrev(list, searchKey);
    struct Node* cur = NULL;
    if (prev == NULL){
        if (list->head == NULL) return;
        else {
            cur = list->head;
            if (cur == list->tail){
                list->head = NULL;
                list->tail = NULL;
                destroyNode(&cur);
            }
            else {
                list->head = cur->next;
                destroyNode(&cur);
            }
        }
     } 
     else {
        cur = prev->next;
        if (cur == list->tail){
            prev->next = NULL;
            list->tail = prev;
            destroyNode(&cur);
        }
        else {
            prev->next = cur->next;
            destroyNode(&cur);
        }
     }
}

struct Node* searchListPrev(struct LinkedList* list, int searchKey){
    struct Node* node = list->head;
    for (; node != NULL; node = node->next)
        if (node->next != NULL && node->next->student->key == searchKey) return node;
    return NULL;
}

void destroyList(struct LinkedList** listPtr){
    if (listPtr == NULL && *listPtr == NULL) return;
    struct LinkedList* list = *listPtr;
    struct Node* cur = list->head;
    struct Node* curNext = NULL;
    if (cur != NULL){
    for (; cur != NULL; cur = curNext){
            curNext = cur->next;
            destroyNode(&cur);
        }   
    }
    // implement **"free(list);"** if lists are individually allocated using malloc()
    *listPtr = NULL;
}

void printList(struct LinkedList* list){
    if (list->head == NULL && list->tail == NULL)
        return;
    for (struct Node* node = list->head; node != NULL; node = node->next)
        printNode(node);
}

void printListNode(struct LinkedList* list, int searchKey){
    if (list->head == NULL && list->tail == NULL) return;
    if (list->head->student->key == searchKey){
        printStudent(list->head->student);
        return;
    }
    struct Node* node = searchListPrev(list, searchKey);
    if (node == NULL) return;
    node = node->next;
    printStudent(node->student);
}