#include "hashmap.h"
#include "hashmap_open.h"
#include "hashmap_chain.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define BUFFER_SIZE 18

enum Options {
    INIT, INSERT, SEARCH, REMOVE, PRINT, QUIT
};

int main(int argc, char* argv[]){

    struct HashMap* dataBase = NULL;

    while (1){
        enum Options userOption;
        printf("User Option: ");
        scanf("%d", &userOption);

        if (userOption == INIT && dataBase == NULL){
            int size;
            printf("Enter database size: ");
            if (scanf("%d", &size) != 1 || size <= 0) {
                printf("Invalid database size.\n");
                continue;
            }
            enum implementationType impl; 
            printf("Enter database implementation (0 for Open Addressing, 1 for Chaining): ");
            scanf("%d%*c", &impl);
            dataBase = initHashMap(impl, size);
            if (dataBase == NULL) {
                printf("Failed to initialize database.\n");
            }
            continue;
        }

        if (dataBase == NULL){
            printf("Database not initialized. Please create one first.\n");
            continue;
        }

        switch (userOption){
            case INIT: 
                printf("Database already initialized.\n");
                break;
            case INSERT: {
                int insertKey;
                printf("Enter Student Id: ");
                scanf("%d%*c", &insertKey);

                char* insertName = (char*)malloc(BUFFER_SIZE*sizeof(char));
                printf("Enter Student Name: ");
                fgets(insertName, BUFFER_SIZE, stdin);
                insertName[strcspn(insertName, "\n")] = '\0';

                char* insertEmail = (char*)malloc(BUFFER_SIZE*sizeof(char));
                printf("Enter Student Email: ");
                fgets(insertEmail, BUFFER_SIZE, stdin);
                insertEmail[strcspn(insertEmail, "\n")] = '\0';

                dataBase->insertStudent(dataBase, insertKey, insertName, insertEmail);

                free(insertName);
                free(insertEmail);
                break;
            }
            case SEARCH: {
                int searchKey;
                printf("Enter Student Id to search: ");
                scanf("%d", &searchKey);
                dataBase->printStudent(dataBase, searchKey);
                break;
            }
            case REMOVE: {
                int removeKey;
                printf("Enter Student Id to delete: ");
                scanf("%d", &removeKey);
                dataBase->removeStudent(dataBase, removeKey);
                break;
            }
            case PRINT:
                dataBase->printHashMap(dataBase);
                break;
            case QUIT:
                destroyHashMap(&dataBase);
                printf("Have a Great Day!\n");
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}