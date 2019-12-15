#include <stdlib.h>
#include "array_helper.h"

int* merge(int *firstArray, int *secondArray, int firstLength, int secondLength);
int* mergeSort(int *array, int length);

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

    array = mergeSort(array, length);

    printArray(array, length);

    return 1;

}

int* mergeSort(int *array, int length) {
    
    if (length < 2) {

        return array;

    }
    

    int leftLength = length / 2;
    int rightLength = length - leftLength;


    int *leftArray = (int*)malloc(leftLength * sizeof(int));
    int *rigthArray = (int*)malloc(rightLength * sizeof(int));

    for (int i = 0; i < leftLength; i++) {

        *(leftArray + i) = *(array + i);

    }

    int j = 0;

    for (int i = leftLength; i < length; i++) {

        *(rigthArray + j) = *(array + i);
        j++;
    }

    free(array);

    rigthArray = mergeSort(rigthArray, rightLength);
    leftArray = mergeSort(leftArray, leftLength);


    return merge(leftArray, rigthArray, leftLength, rightLength);
}

int* merge(int *firstArray, int *secondArray, int firstLength, int secondLength) {

    int firstIndex = 0, secondIndex = 0;
    
    int *finalArray = (int*)malloc((firstLength + secondLength) * sizeof(int));

    if (finalArray == NULL) {

        printf("\nArray was not created. Memory Allocation Denied.");
        exit(0);

    }

    for (int i = 0; i < firstLength + secondLength; i++) {

        if (firstIndex == firstLength) {

            *(finalArray + i) = *(secondArray + secondIndex);
            secondIndex++;

        } else if (secondIndex == secondLength) {

            *(finalArray + i) = *(firstArray + firstIndex);
            firstIndex++;

        } else if (*(firstArray + firstIndex) < *(secondArray + secondIndex)) {

            *(finalArray + i) = *(firstArray + firstIndex);
            firstIndex++;

        } else {

            *(finalArray + i) = *(secondArray + secondIndex);
            secondIndex++;

        }

    }
    
    free(firstArray);
    free(secondArray);

    return finalArray;

}