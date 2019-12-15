#include <stdlib.h>
#include "array_helper.h"

void sortBySelection(int *array, int length);

int main() {

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

    sortBySelection(array, length);

    printArray(array, length);

    return 1;

}

void sortBySelection(int *array, int length) {

    for (int i = 0; i < length - 1; i++) {

        int indexMin = i;

        for (int j = i + 1; j < length; j++) {

            if (*(array + indexMin) > *(array + j)) {
                indexMin = j;
            }

        }

        if (i != indexMin) {
            int value = *(array + i);
            *(array + i) = *(array + indexMin);
            *(array + indexMin) = value;
        }
    }
}