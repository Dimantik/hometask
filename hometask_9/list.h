#include <stdio.h>
#include <stdlib.h>

#define NODE_POINTER_MARKER 1
#define LIST_POINTER_MARKER 2

struct Node {
    int value;
    struct Node *nextElement;
};

struct List {
    struct Node *head;
    struct Node *tail;
    int length;
};


int isNullPointer(void *pointer, int pointerMarker);
void printNode(struct Node *node);
void clearNodes(struct Node *node);


//Main functions

struct List* createList() {
    
    struct List *list = (struct List*)malloc(sizeof(struct List));

    if (!isNullPointer(list, LIST_POINTER_MARKER)){
        
        (*list).head = NULL;
        (*list).tail = NULL;
        (*list).length = 0;

    }
    
    return list;

}

struct Node* createNode(int value) {

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    if (node != NULL) {
        (*node).value = value;
        (*node).nextElement = NULL;
    }
    
    return node;

}

int insertToHead(struct List *list, struct Node *node) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {

        return 0;

    }

    if ((*list).head == NULL){

        (*list).head = node;
        (*list).tail = node;

    } else {

        (*node).nextElement = (*list).head;
        (*list).head = node;

    }

    (*list).length++;

    return 1;
    
}

int insertToTail(struct List *list, struct Node *node) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {
        
        return 0;

    }

    if ((*list).tail == NULL) {

        (*list).head = node;
        (*list).tail = node;

    } else {

        (*(*list).tail).nextElement = node;
        (*list).tail = node;

    }

    (*list).length++;

    return 1;

}

int insertAfterValue(struct List *list, struct Node *node, int value) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {
        
        printf("THERE 1");
        return 0;

    }

    struct Node *currentNode = (*list).head;
    
    int isFindValue = 0;

    if ((*(*list).tail).value == value) {

        insertToTail(list, node);
         
        printf("THERE 2");

        return 1;

    }

    for (int i = 0; i < (*list).length - 1; i++) {

        printf("\nEl = %d, val = %d", (*currentNode).value, value);
        if ((*currentNode).value == value) {

            isFindValue = 1;

            (*node).nextElement = (*currentNode).nextElement;
            (*currentNode).nextElement = node;

            break;

        }

        currentNode = (*currentNode).nextElement;

    }

    if (isFindValue) {

        (*list).length++;

        printf("THERE 3");
        return 1;

    } else {

        printf("THERE 4");

        return 0;

    }
    
}

int deleteNodeByValue(struct List *list, int value) {

    if (isNullPointer(list, LIST_POINTER_MARKER)) {
        
        return 0;

    }

    struct Node *currentNode = (*list).head;
    struct Node *previousNode = NULL;

    for (int i = 0; i < (*list).length; i++) {

        if ((*currentNode).value == value) {

            if (currentNode == (*list).head) {

                (*list).head = (*currentNode).nextElement;

            } else if (currentNode == (*list).tail) {

                (*list).tail = previousNode;
                (*previousNode).nextElement = NULL;

            } else {

                (*previousNode).nextElement = (*currentNode).nextElement;

            }

            free(currentNode);
            (*list).length--;
            
            return 1;

        } else {

            previousNode = currentNode;
            currentNode = (*currentNode).nextElement;

        }

    }

    return 0;


}

int printList(struct List *list) {
    
    if (isNullPointer(list, LIST_POINTER_MARKER)) {
        
        return 0;

    }

    struct Node *node = (*list).head;

    printf("\nList: size = %d", (*list).length);

    if ((*list).length != 0) {

        printf("\n");

    }

    for (int i = 0; i < (*list).length; i++) {

        printNode(node);
        node = (*node).nextElement;

    }

    return 1;

}

int clearList(struct List *list) {

    if (isNullPointer(list, LIST_POINTER_MARKER)) {
        
        return 0;

    }

    struct Node *firstNode = (*list).head;
    (*list).head = NULL;
    (*list).tail = NULL;
    (*list).length = 0;
    clearNodes(firstNode);

    return 1;

}

void clearNodes(struct Node *node) {
    
    if (node == NULL){
        return;
    }

    struct Node *nextElement = (*node).nextElement;
    free(node);
    clearNodes(nextElement);

}

int createCycle(struct List *list, int value) {

    struct Node *currentNode = (*list).head;

    int isFind = 0;

    for (int i = 0; i < (*list).length; i++) {

        if ((*currentNode).value == value) {

            isFind = 1;
            break;

        }

        currentNode = (*currentNode).nextElement;

    }

    if (isFind) {

        struct Node *p = (*currentNode).nextElement;
        insertToTail(list, currentNode);
        if ((*list).tail != NULL) {
            printf("\nHERE1 %d", (*(*(*list).tail).nextElement).value);
        } else {
            printf("\nHERE2 %d");
        }
        (*currentNode).nextElement = p;
        return 1;

    } else {

        return 0;

    }

}

int findCycle(struct List *list) {

    struct Node *pointOne = (*list).head;
    struct Node *pointTwo = (*pointOne).nextElement;
    
    int isHaveCycle = 0;

    while(1) {

        if (pointOne == NULL || pointTwo == NULL) {
            break;
        }

        if (pointOne == pointTwo) {
            isHaveCycle = 1;
            break;
        }

        pointOne = (*pointOne).nextElement;
        pointTwo = (*pointTwo).nextElement;

        if (pointTwo == NULL) {
            break;
        }

        pointTwo = (*pointTwo).nextElement;

    }

    return isHaveCycle;
}

//Secondary functions

void printNode(struct Node *node) {

    printf("%d -> ", (*node).value);

}

int isNullPointer(void *pointer, int pointerMarker) {

    if (pointer == NULL) {

        if (pointerMarker == NODE_POINTER_MARKER) {

            printf("\nNull pointer exception. Node pointer is NULL!");

        } else if (pointerMarker == LIST_POINTER_MARKER) {

            printf("\nNull pointer exception. List pointer is NULL!");

        }

        return 1;

    } else {

        return 0;

    }

}


