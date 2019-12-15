#include <stdio.h>
#include <stdlib.h>

#define NODE_POINTER_MARKER 1
#define LIST_POINTER_MARKER 2

struct Node {
    int index;
    int value;
    struct Node *nextElement;
};

struct List {
    struct Node *head;
    struct Node *tail;
    int length;
};


int isNullPointer(void *pointer, int pointerMarker);
void incrementIndex(struct Node *node);
void decrementIndex(struct Node *node);
void printNode(struct Node *node);
void clearNode(struct Node *node);


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
        (*node).index = -1;
        (*node).value = value;
        (*node).nextElement = NULL;
    }
    
    return node;

}

int insertToHead(struct List *list, struct Node *node) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {

        return 0;

    }

    (*node).index = 0;

    if ((*list).head == NULL){

        (*list).head = node;
        (*list).tail = node;

    } else {

        (*node).nextElement = (*list).head;
        (*list).head = node;

    }

    (*list).length++;
    incrementIndex((*node).nextElement);

    return 1;
    
}

int insertToTail(struct List *list, struct Node *node) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {
        
        return 0;

    }

    (*node).index = (*list).length;

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

int insertByIndex(struct List *list, struct Node *node, int index) {

    if (isNullPointer(list, LIST_POINTER_MARKER) || isNullPointer(node, NODE_POINTER_MARKER)) {
        
        return 0;

    }

    if (index > (*list).length || index < 0) {
        return 0;
    }

    struct Node *currentNode = (*list).head;

    if (index == 0) {

        insertToHead(list, node);

    } else if (index == (*list).length) {

        insertToTail(list, node);

    } else {

        for (int i = 0; i < (*list).length - 1; i++) {

            if ((*currentNode).index == index - 1) {
                
                (*node).nextElement = (*currentNode).nextElement;
                (*currentNode).nextElement = node;
                (*node).index = (*currentNode).index + 1;
                incrementIndex((*node).nextElement);

                break;

            } else {

                currentNode = (*currentNode).nextElement;

            }

        }

        (*list).length++;


    }

    return 1;
    
}

int deleteNodeByValue(struct List *list, int value) {

    if (isNullPointer(list, LIST_POINTER_MARKER)) {
        
        return 0;

    }

    struct Node *currentNode = (*list).head;
    struct Node *previousNode = NULL;

    for (int i = 0; i < (*list).length; i++) {

        if ((*currentNode).value == value) {

            if ((*currentNode).index == 0) {

                (*list).head = (*currentNode).nextElement;

            } else if ((*currentNode).index == (*list).length - 1) {\

                (*list).tail = previousNode;
                (*previousNode).nextElement = NULL;

            } else {

                (*previousNode).nextElement = (*currentNode).nextElement;

            }

            decrementIndex((*currentNode).nextElement);
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
    clearNode(firstNode);

    return 1;

}

void clearNodes(struct Node *node) {
    
    if (node == NULL){
        return;
    }

    struct Node *nextElement = (*node).nextElement;
    free(node);
    clearNode(nextElement);

}

//Secondary functions

void incrementIndex(struct Node *node) {

    if (node == NULL) {
        return;
    }
    
    (*node).index++;
    incrementIndex((*node).nextElement);

}

void decrementIndex(struct Node *node) {

    if (node == NULL) {
        return;
    }

    (*node).index--;

    decrementIndex((*node).nextElement);

}

void printNode(struct Node *node) {

    printf("Element %d: value = %d\n", (*node).index, (*node).value);

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


