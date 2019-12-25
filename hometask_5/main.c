#include <stdlib.h>
#include <stdio.h>

int globalVariable;

void testFunction();

int main () {

    int *dynamicPointer = (int*)malloc(sizeof(int));

    if (dynamicPointer == NULL) {

        printf("Memmory was not allocated.");
        return 0;

    }

    *dynamicPointer = 6;

    int localVariable = 10;

    void (*userFunctionPointer)();
    int (*systemFunctionPointer)(const char *, ...);

    userFunctionPointer = testFunction;
    systemFunctionPointer = printf;

    printf("\nAdress local variable = %x", &localVariable);        
    printf("\nAdress global variable = %x", &globalVariable);     
    printf("\nAdress dynamic variable = %x", dynamicPointer);      
    printf("\nAdress user function = %x", userFunctionPointer);    
    printf("\nAdress sytem function = %x", systemFunctionPointer); 

    return 1;
}

void testFunction() {

    printf("Test function");

}