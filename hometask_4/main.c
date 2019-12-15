#include <stdio.h>

int strlenM(char *str);
char* strcpyM(char* dst, char* src);
char* strcatM(char *des, char *src);
int strcmpM(char* s1, char* s2);

int main() {

    char str1[] = {"1234"};
    char str2[] = {"Hello world!"};
    char str3[] = {"09999"};

    char str4[strlenM(str2) + 1];
    char str5[strlenM(str1) + 1];
    char str6[100] = {"Firt str"};

    strcpyM(str5, str1);
    strcpyM(str4, str2);
    strcatM(str6, str1);

    printf("\nStr1 length = %s\t\t\t length = %d", str1, strlenM(str1));
    printf("\nStr2 length = %s\t\t length = %d", str2, strlenM(str2));
    printf("\nStr3 length = %s\t\t\t length = %d", str3, strlenM(str3));
    printf("\nStr4 length = %s\t\t length = %d", str4, strlenM(str4));
    printf("\nStr5 length = %s\t\t\t length = %d", str5, strlenM(str5));
    printf("\nStr6 length = %s\t\t length = %d", str6, strlenM(str6));
    printf("\nStr1 == Str2 = %d", strcmpM(str1, str2));
    printf("\nStr1 == Str3 = %d", strcmpM(str1, str3));
    printf("\nStr1 == Str5 = %d", strcmpM(str1, str5));

    return 1;

}

int strlenM(char *str) {
    
    if (str == NULL) {

        printf("\nNull pointer exception.");

        return -1;

    }

    int currentIndex = 0;

    while (1) {
        if (*(str + currentIndex) == '\0') {
            break;
        } else {
            currentIndex++;
        }
    }

    return currentIndex;

}

char* strcpyM(char* dst, char* src) {

    if (dst == NULL || src == NULL) {

        printf("\nNull pointer exception.");

        return NULL;

    }
    
    int currentIndex = 0;

    while (1) {

        *(dst + currentIndex) = *(src + currentIndex);

        if (*(src + currentIndex) == '\0') {

            break;

        }

        currentIndex++;

    }

    return dst;

}

char* strcatM(char *des, char *src) {

    int startLength = strlenM(des);
    int srcLength = strlenM(src);

    for (int i = startLength; i < startLength + srcLength; i++) {

        *(des + i) = *(src + i - startLength);

        if (i + 1 == startLength + srcLength) {
            *(des + i + 1) = '\0';
        }

    }

    return des;

}

int strcmpM(char* s1, char* s2) {

    int result = 1;
    int currentIndex = 0;

    while (1) {

        if (*(s1 + currentIndex) > *(s2 + currentIndex)) {

            result = 1;
            break;

        } else if (*(s1 + currentIndex) < *(s2 + currentIndex)) {

            result = -1;
            break;

        } else {
            
            if ((*(s1 + currentIndex) == *(s2 + currentIndex)) && (*(s1 + currentIndex) == '\0')) {
            
                result = 0;
                break;

            } else {

                currentIndex++;
                continue;

            }

        }

    }

    return result;

}