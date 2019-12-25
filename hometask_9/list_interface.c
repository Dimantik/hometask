#include <stdio.h>
#include <stdlib.h>
#include "list.h"
 
#define OP_CREATE_LIST      1
#define OP_ADD_EL_TO_HEAD   2
#define OP_ADD_EL_TO_TAIL   3
#define OP_ADD_EL_AFTER_VAL 4
#define OP_DELETE_EL_BY_VAL 5
#define OP_PRINT_LIST       6
#define OP_CLEAR_LIST       7
#define OP_CREATE_CYCLE     8
#define OP_FIND_CYCLE       9
#define OP_EXIT             10

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
            case OP_CREATE_LIST:
                createListI(&list);
                break;
            case OP_ADD_EL_TO_HEAD:
                insertToHeadI(list);
                break;
            case OP_ADD_EL_TO_TAIL:
                insertToTailI(list);
                break;
            case OP_ADD_EL_AFTER_VAL:
                insertAfterValueI(list);
                break;
            case OP_DELETE_EL_BY_VAL:
                deleteNodeByValueI(list);
                break;
            case OP_PRINT_LIST:
                printListI(list);
                break;
            case OP_CLEAR_LIST:
                clearListI(list);
                break;
            case OP_CREATE_CYCLE:
                createCycleI(list);
                break;
            case OP_FIND_CYCLE:
                findCycleI(list);
                break;
            case OP_EXIT:
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