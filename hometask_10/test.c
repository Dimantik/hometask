#include <stdio.h>

void fucn(int **pp) {
    printf("\n&pp = %x", &pp);
}

int main() {
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("&x = %x\tp = %x,\tpp = %x\t*pp = %x\t&pp = %x\t&p = %x\t**pp = %d", &x, p, pp, *pp, &pp, &p, **pp);
    
    fucn(pp);
}