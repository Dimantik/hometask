#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void putElementI(struct HashTable *hashtable);
void printHastableI(struct HashTable *hashtable);
int isNullPointer(void *p);
int hashFunction(int key);
void printEntryList(struct Entry *entry);
void getByKeyI(struct HashTable *hashtable);
void removeByKeyI(struct HashTable *hashtable);
void printStatisticsI(struct HashTable *hashtable);

int main() {

    struct HashTable *hashtable = createHashTable(hashFunction);

    return 1;

}

void removeByKeyI(struct HashTable *hashtable) {

    if (isNullPointer(hashtable)) {

        printf("\nHashtable is null!");

    }

    int key;

    printf("\nInput key: ");
    scanf("%d", &key);

    int result = removeByKey(hashtable, key);

    if (result) {
        printf("\nRemove value by key: key = %d", key);
    } else {
        printf("\nKey match not found: key = %d", key);
    }

}

void getByKeyI(struct HashTable *hashtable) {

    if (isNullPointer(hashtable)) {

        printf("\nHashtable is null!");

    }

    int key;

    printf("\nInput key: ");
    scanf("%d", &key);

    int result = getByKey(hashtable, key);

    printf("\nResult by key = %d value = %d", key, result);
}

void printHastableI(struct HashTable *hashtable) {

    if (isNullPointer(hashtable)) {

        printf("\nHashtable is null!");

    }

    printf("\nHashtable {\n\tsize: %d\n\tloadFactor: %lf\n\tthreshold: %d\n\tEntryTable {\n\t\tcapacity: %d",
        (*hashtable).size,
        (*hashtable).loadFactor, 
        (*hashtable).threshold,
        (*(*hashtable).entryTable).capacity);

    if ((*(*hashtable).entryTable).table == NULL) {
        printf("\n\t\tTable: NULL");
    } else {
        printf("\n\t\tTable {");
        for (int i = 0; i < (*(*hashtable).entryTable).capacity; i++) {
            if (*((*(*hashtable).entryTable).table + i) == NULL) {
                printf("\n\n\t\t\tEntry: NULL");
            } else {
                printEntryList(*((*(*hashtable).entryTable).table + i));
            }
        }
        printf("\n\n\t\t}");
    }
    printf("\n\t}");
    printf("\n}");
}

void printStatisticsI(struct HashTable *hashtable) {

    printStatistics(hashtable);

}

void printEntryList(struct Entry *entry) {

    struct Entry *helpPointer = entry;

    printf("\n\n\t\t\t");
    while (helpPointer != NULL) {

        printf("Entry {\t\t\t");
        helpPointer = (*helpPointer).nextEntry;

    }

    helpPointer = entry;

    printf("\n\t\t\t\t");
    while (helpPointer != NULL) {

        printf("key: %d\t\t\t", (*helpPointer).key);
        helpPointer = (*helpPointer).nextEntry;

    }

    helpPointer = entry;

    printf("\n\t\t\t\t");
    while (helpPointer != NULL) {

        printf("value: %d\t\t", (*helpPointer).value);
        helpPointer = (*helpPointer).nextEntry;

    }

    helpPointer = entry;

    printf("\n\t\t\t");
    while (helpPointer != NULL) {

        printf("}\t\t\t", (*helpPointer).value);
        helpPointer = (*helpPointer).nextEntry;

    }

}

void putElementI(struct HashTable *hashtable) {

    if (isNullPointer(hashtable)) {

        printf("\nHashtable is null!");

    }

    int value, key;

    printf("\nInput value: ");
    scanf("%d", &value);
    printf("Input key: ");
    scanf("%d", &key);

    int result = putElement(hashtable, key, value);

    if (result) {
        printf("\nElement was created and putted.");
    } else {
        printf("\nElement was not created and putted.");
    }

}

int isNullPointer(void *p) {

    if (p == NULL) {

        return 1;

    }

    return 0;

}

int hashFunction(int key) {

    printf("\nHASH FUNC");
    return key;

}