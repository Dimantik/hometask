#include <stdio.h>

void check(char *s, char *s1, int index, int *counter);

int main() {

    char S[100];
    char S1[10];

    int counter = 0;
    
    printf("Input S: ");
    gets(S);

    printf("Input S1: ");
    gets(S1);
    
    printf("\nS = {%s}", S);
    printf("\nS1 = {%s}", S1);

    for (int i = 0; S[i] != '\0'; i++) {
        check(S, S1, i, &counter);
    }

    printf("\nResult: %d", counter);

    return 1;
}

void check(char *s, char *s1, int index, int *counter) {

    int indexS1 = 0;

    for (int i = index; *(s1 + indexS1) != '\0'; i++, indexS1++) {
        if (*(s + i) != *(s1 + indexS1)) {
            return;
        }
    }

    (*counter)++;

}