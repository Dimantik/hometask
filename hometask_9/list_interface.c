#include <stdio.h>
#include <stdlib.h>
#include "list.h"
 
#define ACTION_1 1
#define ACTION_2 2
#define ACTION_3 3
#define ACTION_4 4
#define ACTION_5 5
#define ACTION_6 6
#define ACTION_7 7
#define ACTION_8 8
#define ACTION_9 9
#define ACTION_10 10

//Interface functions
void createListI(struct List **list);
struct Node* createNodeI();
void insertToHeadI(struct List *list);
void insertToTailI(struct List *head);
void insertAfterValueI(struct List *list);
void deleteNodeByValueI(struct List *list);
void printListI(struct List *list);
void clearListI(struct List *list);
void exitI(struct List *list);
void createCycleI(struct List *list);
void findCycleI(struct List *list);

int inputIntI();
int isListNullI(struct List *list);

int main() {

    struct List *list = NULL;

    int action;

    while(1) {

        printf(
                "\n\nChoose option:\n\t1 - Create list\n\t2 - Add element at the head\n\t3 - Add element at the tail\n\t4 - Add element after value\n\t5 - Delete element by value\n\t6 - Print list\n\t7 - Clear list\n\t8 - Create cycle\n\t9 - Find cycle\n\t10 - Exit\n\n"
        );

        printf("Option - ");
        scanf("%d", &action);

        switch(action) {
            case ACTION_1:
                createListI(&list);
                break;
            case ACTION_2:
                insertToHeadI(list);
                break;
            case ACTION_3:
                insertToTailI(list);
                break;
            case ACTION_4:
                insertAfterValueI(list);
                break;
            case ACTION_5:
                deleteNodeByValueI(list);
                break;
            case ACTION_6:
                printListI(list);
                break;
            case ACTION_7:
                clearListI(list);
                break;
            case ACTION_8:
                createCycleI(list);
                break;
            case ACTION_9:
                findCycleI(list);
                break;
            case ACTION_10:
                exitI(list);
                break;
            default:
                printf("\nUnknown option: %d", action);
                break;

        }
    }

    return 1;
}

void findCycleI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    int result = findCycle(list);

    if (result) {

        printf("\nCycle is exist.");

    } else {

        printf("\nCycle is not exist.");

    }
}
void createCycleI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }
    
    int value;

    printf("\nInput existing value: ");
    scanf("%d", &value);

    int result = createCycle(list, value);

    if (result) {

        printf("Cycle was created.");
        
    } else {

        printf("Cycle was not created. No matching values ​​found.");

    }

}

void createListI(struct List **list) {

    if ((*list) != NULL) {

        printf("\nList alreay was created.");

        return;

    }

    (*list) = createList();

    if (list == NULL) {

        printf("\nList was not created. Memory Allocation Denied.");

    } else {

        printf("\nList was created.");

    }

}

void insertToHeadI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    struct Node *node = createNodeI();

    if (node != NULL) {

        insertToHead(list, node);

        printf("\nElement was created and added to list.");
        
    }

} 

void insertToTailI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    struct Node *node = createNodeI();

    if (node != NULL) {

        insertToTail(list, node);

        printf("\nElement was created and added to list.");

    }

} 

void insertAfterValueI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    struct Node *node = createNodeI();

    int value;
    printf("Input value: ");
    scanf("%d", &value);

    if (node != NULL) {

        int result = insertAfterValue(list, node, value);

        if (result) {

            printf("\nElement was created and added to list.");

        } else {

            printf("\nElement was not added to list. No matching values ​​found.");

        }

    }

}

void deleteNodeByValueI(struct List *list){

    if (isListNullI(list)) {
        return;
    }

    int value;
    printf("\nInput value: ");
    scanf("%d", &value);
    
    int result = deleteNodeByValue(list, value);

    if (result) {

        printf("\nElement was found and deleted.");

    } else {

        printf("\nNo matches found");

    }
}

void exitI(struct List *list) {

    clearListI(list);
    exit(0);

}

struct Node* createNodeI() {

    struct Node *node = createNode(inputIntI());

    if (node == NULL) {

        printf("\nElement was not created. Memory Allocation Denied.");

    }

    return node;
    
}

void clearListI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    clearList(list);

    printf("\nList was cleaned.");

}

int isListNullI(struct List *list){
    
    if (list == NULL) {
        
        printf("\nList is not created.");

        return 1;

    } else {

        return 0;
    }
}
void printListI(struct List *list) {

    printList(list);

}

int inputIntI(){
    
    int input;
    printf("\nInput int number: ");
    scanf("%d", &input);

    return input;

}