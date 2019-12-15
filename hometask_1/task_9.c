#include <stdio.h>

int main() {

    int input;
    int result = 0;

    printf("Input number: ");
    scanf("%d", &input);

    printf("\nSimple number = 2");
    
    for (int i = 3; i < input; i++) {
        int isSimple = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isSimple = 0;
                break;
            }
        }
        if (isSimple) {
            printf("\nSimple number = %d", i);
        }
    }


    return 1;
}