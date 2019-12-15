#include <stdlib.h>
#include <stdio.h>

int globalVariable;

void testFunction();

int main () {

    int *dynamicPointer = (int*)malloc(sizeof(int));
    *dynamicPointer = 6;

    int localVariable = 10;

    void (*userFunctionPointer)();
    int (*systemFunctionPointer)(const char *, ...);

    userFunctionPointer = testFunction;
    systemFunctionPointer = printf;

    printf("\nAdress local variable = %x", &localVariable);        //6422288
    printf("\nAdress global variable = %x", &globalVariable);      //4223088
    printf("\nAdress dynamic variable = %x", dynamicPointer);      //11211856
    printf("\nAdress user function = %x", userFunctionPointer);    //4199611
    printf("\nAdress sytem function = %x", systemFunctionPointer); //4209440

    return 1;
}

void testFunction() {

    printf("Test function");

}