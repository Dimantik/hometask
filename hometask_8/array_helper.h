#include <stdlib.h>
#include <stdio.h>

void fillArray(int *p, int length, int randArg, int maxValue) {
    
    srand(randArg);

    for (int i = 0; i < length; i++) {

        *(p + i) = rand() % (maxValue + 1);

    }

}

void printArray(int *array, int length) {

    printf("\n----------------------------------------");
    printf("\nArray: size = %d", length);

    for (int i = 0; i < length; i++) {
        printf("\nIndex = %d value = %d", i, *(array+i));
    }

    printf("\n----------------------------------------");

}