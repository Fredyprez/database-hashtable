#ifndef STUDENT_H

#define STUDENT_H
struct Student {
    int key;
    char* name;
    char* email; 
};

struct Student* createStudent(int addKey, char* addName, char* addEmail);
void destroyStudent(struct Student** student);
void printStudent(struct Student* student);
#endif