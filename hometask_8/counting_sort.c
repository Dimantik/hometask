#include <stdio.h>

#include "array_helper.h"

void countingSort(int *array, int length, int maxValue);
void printArray(int *array, int length);

int main () {

    int length, maxValue, randomArgument;
    
    printf("\nInput array length: ");
    scanf("%d", &length);
    printf("\nInput max value: ");
    scanf("%d", &maxValue);
    printf("\nInput random argument: ");
    scanf("%d", &randomArgument);

    int *array = (int*)malloc(length * sizeof(int));

    fillArray(array, length, randomArgument, maxValue);

    printArray(array, length);

    printf("\nSort array ...");

    countingSort(array, length, maxValue);

    printArray(array, length);

    return 1;

}

void countingSort(int *array, int length, int maxValue) {

    int counter[maxValue + 1];

    for (int i = 0; i < maxValue + 1; i++) {

        counter[i] = 0;

    }

    for (int i = 0; i < length; i++) {
        
        counter[*(array + i)]++;

    }
    
    int index = 0;
    
    for (int i = 0; i < maxValue + 1; i++) {

        for (int j = 0; j < counter[i]; j++) {

            *(array + index) = i;
            index++;

        }

    }

}