#include "hashmap.h"
#include "hashmap_open.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char* argv[]){
    struct HashMap* dataBase = NULL;

    int userOption; 
    printf("User Option: ");
    scanf("%d", &userOption);
    
    while (userOption != 5){
        if (userOption == 0){
            int dataBaseSize; 
            printf("Enter size of database: ");
            scanf("%d", &dataBaseSize);
            dataBase = initHashMap(OPEN, dataBaseSize);
        }
        else if (userOption == 1){
            int insertKey;
            printf("Enter Student Id: ");
            scanf("%d", &insertKey);

            char insertName[18];
            printf("Enter Student Name: ");
            scanf("%s", insertName);
                
            char insertEmail[18];
            printf("Enter Student Email: ");
            scanf("%s", insertEmail);
            dataBase->insertStudent(dataBase, insertKey, insertName, insertEmail);
        }
        else if (userOption == 2){
            int searchKey;
            printf("Enter Student Id to search: ");
            scanf("%d", &searchKey);
            dataBase->printStudent(dataBase, searchKey);
        }
        else if (userOption == 3){
            int removeKey;
            printf("Enter Student Id to delete: ");
            scanf("%d", &removeKey);
            dataBase->removeStudent(dataBase, removeKey);
        }
        else if (userOption == 4) dataBase->printHashMap(dataBase);
            
        printf("User Option: ");
        scanf("%d", &userOption);
    }

    destroyHashMap(&dataBase);
    printf("Have a Great Day!\n");
    return 0;
}