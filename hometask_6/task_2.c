#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double parseNumber(char *number);

int main() {

    char number[101];

    printf("Input number (max length = 100): ");
    gets(number);

    printf("String = %s", number);

    double result = parseNumber(number);

    printf("\nReult = %lf", result);

    return 1;

}

double parseNumber(char *number) {

    double result = 0;
    int isNegativeNumber = 0;


    int intLength = 0, doubleLength = 0;
    int isWholeRanks = 1;

    for (int i = 0; *(number + i) != '\0'; i++) {

        if (*(number + i) == '-') {
            isNegativeNumber = 1;
            continue;
        }

        if (*(number + i) == '.') {
            isWholeRanks = 0;
            continue;
        }

        if (isWholeRanks) {
            intLength++;
        } else {
            doubleLength++;
        }
    }

    int doubleLI = -1;
    isWholeRanks = 1;

    for (int i = 0; *(number + i) != '\0'; i++) {

        if (*(number + i) == '-') {
            continue;
        }

        if (*(number + i) == '.') {

            isWholeRanks = 0;
            continue;

        }

        int c = (int) *(number + i);
        c -= 48;

        if (isWholeRanks) {
        
            double add;

            if (isNegativeNumber) {

                add = c * pow(10, (intLength - i));

            } else {

                add = c * pow(10, (intLength - 1 - i));

            }

            result += add;

        } else {

            double add = c * pow(10, doubleLI);
            result += add;
            doubleLI--;

        }

    }

    if (isNegativeNumber) {

        result = -result;

    }

    return result;

}