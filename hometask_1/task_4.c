#include <stdio.h>

int main() {

    int a, b;

    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    
    int remainder = a;
    int result = 0;

    while (remainder >= b) {
        result++;
        remainder -= b;
    }

    printf("Result: %d", result);

    return 1;

}