#include <stdio.h>

int main() {

    int LENGTH;
    int result = 0;

    printf("Input array lenght: ");
    scanf("%d", &LENGTH);

    int array[LENGTH];

    for (int i = 0; i < LENGTH; i++) {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
        if (array[i] == 0) {
            result++;
        }
    }

    printf("Result = %d", result);

}