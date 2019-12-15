#include <stdio.h>

void shiftByOneIndex(int *array, int length);

int main() {

    int m, n, length;

    printf("Input m: ");
    scanf("%d", &m);
    printf("Input n: ");
    scanf("%d", &n);

    length = m + n;
    int array[length];

    for (int i = 0; i < length; i++) {

        printf("array[%d} = ", i);
        scanf("%d", &array[i]);

    }

    for (int i = 0; i < length; i++) {

        printf("\narray[%d} = %d", i, array[i]);

    }

    printf("\nReverse");

    for (int i = 0; i < n; i++) {

        shiftByOneIndex(array, length);

    }

    for (int i = 0; i < length; i++) {

        printf("\narray[%d} = %d", i, array[i]);

    }

    return 1;
}

void shiftByOneIndex(int *array, int length) {

    int helpVal, previousElement;

    for (int i = 0; i < length; i++) {

        helpVal = *(array + i);

        if (i == 0) {

            previousElement = helpVal;
            continue;

        }

        *(array + i) = previousElement;
        previousElement = helpVal;
        
        if (i == length - 1) {

            *(array) = previousElement;

        }
    }
}