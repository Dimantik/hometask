#include <stdio.h>

int main(){
    const int LENGTH = 256;
    int N;
    int element;
    int existence[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        existence[i] = -1;
    }

    printf("Input N = ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Input element = ");
        scanf("%d", &element);

        if (existence[element] == -1) {
            existence[element] = i;
        }
    }

    printf("Result = { ");

    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++){
            if (i == existence[j]){
                printf("%d ", j);
            }
        }
    }

    printf("}");

    return 0;
}