#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Interface functions
void createListI(struct List **list);
struct Node* createNodeI();
void insertToHeadI(struct List *list);
void insertToTailI(struct List *head);
void insertByIndexI(struct List *list);
void deleteNodeByValueI(struct List *list);
void printListI(struct List *list);
void clearListI(struct List *list);

int inputIntI();
int isListNullI(struct List *list);

const int ACTION_1 = 1;
const int ACTION_2 = 2;
const int ACTION_3 = 3;
const int ACTION_4 = 4;
const int ACTION_5 = 5;
const int ACTION_6 = 6;
const int ACTION_7 = 7;
const int ACTION_8 = 8;

int main() {

    struct List *list = NULL;

    int action;

    while(1) {

        printf(
                "\n\nChoose option:\n\t1 - Create list\n\t2 - Add element at the head\n\t3 - Add element at the tail\n\t4 - Add element by index\n\t5 - Delete element by value\n\t6 - Print list\n\t7 - Clear list\n\t8 - Exit\n\n"
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
                insertByIndexI(list);
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
                clearListI(list);
                exit(0);
                break;
            default:
                printf("\nUnknown option: %d", action);
                break;

        }
    }

    return 1;
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

void insertByIndexI(struct List *list) {

    if (isListNullI(list)) {
        return;
    }

    struct Node *node = createNodeI();

    int index;
    printf("Input index: ");
    scanf("%d", &index);

    if (node != NULL) {

        insertByIndex(list, node, index);

        printf("\nElement was created and added to list.");

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