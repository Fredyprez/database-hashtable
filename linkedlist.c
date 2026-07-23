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
    struct Node* prev = searchList(list, searchKey);
    struct Node* cur = NULL;
    if (prev == NULL){
        if (list->head == NULL) return;
        else {
            cur = list->head;
            list->head = NULL;
            list->tail = NULL;
            destroyNode(&cur);
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

struct Node* searchList(struct LinkedList* list, int searchKey){
    for (struct Node* node = list->head; node != NULL; node = node->next){
        if (node == NULL) break;
        if (node->next != NULL && node->next->student->key == searchKey) return node;
    }
    return NULL;
}

void destroyList(struct LinkedList** listPtr){
    struct LinkedList* list = *listPtr;
    struct Node* cur = NULL;
    struct Node* curNext = NULL;
    for (cur = list->head; cur != NULL; cur = curNext){
        curNext = cur->next;
        destroyNode(&cur);
    }
    free(list);
    *listPtr = NULL;
}

void printList(struct LinkedList* list){
    if (list->head == NULL && list->tail == NULL)
        return;
    for (struct Node* node = list->head; node != NULL; node = node->next)
        printNode(node);
}

int main(){
    struct LinkedList* bucket = createList();
    struct Student* student = createStudent(1, "Fredy", "f@usf.edu");
    insertListNode(bucket, student);
    student = createStudent(3, "Bella", "b@usf.edu");
    insertListNode(bucket, student);
    student = createStudent(5, "Jesus", "j@usf.edu");
    insertListNode(bucket, student);
    printList(bucket);
    removeListNode(bucket, 3);
    printList(bucket);
    removeListNode(bucket, 5);
    printList(bucket);
    removeListNode(bucket, 1);
    printList(bucket);
    destroyList(&bucket);

    return 0;
}