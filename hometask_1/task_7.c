#include <stdio.h>

int main() {
    
    char input[100];

    printf("Input: ");
    scanf("%s", input);

    int openCounter = 0;
    int closeCounter = 0;

    int isCorrect = 1;

    for (int i = 0; input[i] != '\0'; i++) {

        if (input[i] == '(') {

            openCounter++;

        } else if (input[i] == ')') {

            closeCounter++;

        }

        if (closeCounter > openCounter) {

            isCorrect = 0;
            break;
            
        }
    }

    if (closeCounter != openCounter) {

        isCorrect = 0;

    }

    if (isCorrect) {

        printf("Result: correct");

    } else {

        printf("Result: wrong");

    }

}