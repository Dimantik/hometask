#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int ARRAY_LENGTH;
    char ticket[7];
    int count = 0;

    printf("Input array legth: ");
    scanf("%d", &ARRAY_LENGTH);

    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("Input ticket: ");
        scanf("%s", ticket);

        if (ticket[0] + ticket[1] + ticket[2] == 
            ticket[3] + ticket[4] + ticket[5]) {
                count++;
        }
    }

    printf("Result: %d", count);

    return 1;

}