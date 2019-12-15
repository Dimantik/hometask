#include <stdio.h>

int main(){
    int N;
    int x = 0, y = 1, z;

    printf("Input N = ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        if (i == 0){
            z = x;
        } else if (i == 1){
            z = y;
        } else {
            z = x+y;
            x = y;
            y = z;
        }
    }

    printf("\nF(%d) = %d", N, z);

    return 0;
}