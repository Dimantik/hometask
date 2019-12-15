#include <stdio.h>
#include <string.h>
#include <math.h>

int table[64] = {

    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/',

};

char encode(char *br);
void addBinaryRepresentation(char *dst, char c);
int createBinary_6_Block(char *binaryCode, char *binaryBlock, int *currentIndex);

int main () {

    char input[100];
    char binaryCode[800]; 
    binaryCode[0] = '\0';
    char output[60];

    printf("Input: ");
    gets(input);

    for (int i = 0; input[i] != '\0'; i++) {

        addBinaryRepresentation(binaryCode, input[i]);

    }

    int currentIndex = 0;
    int outputIndex = 0;
    
    char binaryBlock[7];
    binaryBlock[6] = '\0';

    while (1) {

        int isEnd = createBinary_6_Block(binaryCode, binaryBlock, &currentIndex);

        if (isEnd == 1) {

            break;

        } else if (isEnd == 0) {

            output[outputIndex] = encode(binaryBlock);
            outputIndex++;

        } else if (isEnd == -1) {

            output[outputIndex] = encode(binaryBlock);
            outputIndex++;
            break;

        }
    }

    output[outputIndex] = '\0';

    printf("Output: %s", output);

    return 1;
}

void addBinaryRepresentation(char *dst, char c) {

    int currentVal = (int)c;

    char binaryRepresentation[] = "00000000\0";
    
    int index = 7;

    while (1) {

        int helpVal = currentVal/2;

        if (currentVal - helpVal * 2 == 0) {

            binaryRepresentation[index] = '0';

        } else {

            binaryRepresentation[index] = '1';

        }

        index--;

        currentVal = helpVal;

        if (currentVal == 1) {

            binaryRepresentation[index] = '1';
            break;

        }
    }

    strcat(dst, binaryRepresentation);

}

int createBinary_6_Block(char *binaryCode, char *binaryBlock, int *currentIndex) {

    int isEnd = 0;

    for (int i = 0; i < 6; i++) {
        if (*(binaryCode + *currentIndex + i) == '\0') {
            if (i == 0) {
                isEnd = 1;
                return isEnd;
            } else {
                isEnd = -1;
            }
        }

        if (isEnd == -1) {
            *(binaryBlock + i) = '0';
        } else {
            *(binaryBlock + i) = *(binaryCode + *currentIndex + i);
        }

    }
    
    *currentIndex += 6;

    return isEnd;
    
}

char encode(char *br) {

    int result = 0;

    for (int i = 0; i < 6; i++) {

        int val = br[i] - 48;
        int add = val * pow(2, 6 - i - 1);
        result += add;

    }

    return table[result];
}