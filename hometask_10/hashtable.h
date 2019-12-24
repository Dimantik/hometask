#define MEMMORY_ALOCATED_ERROR 1
#define HASH_TABLE_IS_NULL 2

const int DEFAULT_CAPACITY = 6;
const double DEFAULT_LOAD_FACTOR = 0.75;

struct HashTable {

    int size;
    double loadFactor;
    int threshold;
    int (*hashFunction)(int);
    struct EntryTable *entryTable;

};

struct EntryTable {
    
    int capacity;
    struct Entry **table;

};

struct Entry {

    int key;
    int value;
    struct Entry *nextEntry;

};

struct HashTable* createHashTable(int (*hashFunction)(int));
struct HashTable* createHashTableByCapacity(int (*hashFunction)(int), int capacity);
struct HashTable* createHashTableByCapacityByLoadFactor(int (*hashFunction)(int), int capacity, double loadFactor);
int putElement(struct HashTable *hashTable, int key, int value);
int indexFor(int hashCode, int length);

int isMemmoryAlocatedP(void *p);
int isMemmoryAlocatedPP(void **p);
void printError(int errorMarker);
void resetPointersForEntryTable(struct Entry **pp, int capacity);
int isHashTableNull(struct HashTable *hashTable);
struct Entry* createEntry(int value, int key);


struct HashTable* createHashTable(int (*hashFunction)(int)) {
    return createHashTableByCapacity(hashFunction, DEFAULT_CAPACITY);
}

struct HashTable* createHashTableByCapacity(int (*hashFunction)(int), int capacity) {
    return createHashTableByCapacityByLoadFactor(hashFunction, capacity, DEFAULT_LOAD_FACTOR);
}

struct HashTable* createHashTableByCapacityByLoadFactor(int (*hashFunction)(int), int capacity, double loadFactor) {

    //create entryTable
    struct EntryTable *entryTable = (struct EntryTable*)malloc(sizeof(struct EntryTable));
    if (!isMemmoryAlocatedP(entryTable)) {

        return NULL;

    }

    (*entryTable).capacity = capacity;
    (*entryTable).table = (struct Entry**)malloc(sizeof(struct Entry*) * capacity);

    printf("\nAddress one table = %x\t&table = %x", (*entryTable).table, &(*entryTable).table);
    resetPointersForEntryTable((*entryTable).table, capacity);

    //create hashTable
    struct HashTable *hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (!isMemmoryAlocatedP(hashTable)) {

        free(entryTable);
        return NULL;
        
    }

    (*hashTable).size = 0;
    (*hashTable).loadFactor = loadFactor;
    (*hashTable).threshold = (int)(loadFactor * capacity);
    (*hashTable).entryTable = entryTable;
    (*hashTable).hashFunction = hashFunction;

    return hashTable;

}

int putElement(struct HashTable *hashTable, int key, int value) {
    
    printf("\nHERE 1");

    if (isHashTableNull(hashTable)) {

        return 0;

    }

    printf("\nHERE 2");
    int hashCode = ((*hashTable).hashFunction)(key);
    printf("\nHERE 2.1");
    int index = indexFor(hashCode, (*(*hashTable).entryTable).capacity);
    printf("\nHERE 2.2");

    printf("\nHERE 3");
    
    struct Entry **firstEntry = (*(*hashTable).entryTable).table + index;
    printf("\nTEST\t currentEntry = %x", firstEntry);

    printf("\nHERE 3.1");
    if (*firstEntry == NULL) {
        printf("\nHERE 3.2");
        *firstEntry = createEntry(value, key);
    } else {

        int isPut = 0;

        struct Entry *currentEntry = *firstEntry;

        printf("\nHERE 4");

        while(!isPut) {

            printf("\nHERE 5");

            if (hashCode == (*hashTable).hashFunction((*currentEntry).key) & key == (*currentEntry).key) {

                printf("\nHERE 5.1");
                (*currentEntry).value = value;
                isPut = 1;
                break;

            }

            printf("\nHERE 5.2");

            if ((*currentEntry).nextEntry == NULL) {
                printf("\nHERE 5.3");
                break;
            }

            printf("\nHERE 5.4");
            currentEntry = (*currentEntry).nextEntry;
            printf("\nHERE 5.5");

        }

        if (!isPut) {

            printf("\nHERE 7");

            (*currentEntry).nextEntry = createEntry(value, key);

            if ((*currentEntry).nextEntry == NULL) {

                return 0;

            }

        }

    }


    printf("\nHERE 6");

    printf("\nHERE 8");

    (*hashTable).size++;

    return 1;
}

int getByKey(struct HashTable *hashTable, int key) {

    int index = indexFor(key, (*(*hashTable).entryTable).capacity);

    struct Entry **firstEntry = (*(*hashTable).entryTable).table + index;

    if (*firstEntry == NULL) {
        return 0;
    }

    struct Entry *currentEntry = *firstEntry;

    while (currentEntry != NULL) {

        if ((*currentEntry).key == key) {
            return (*currentEntry).value;
        }

        currentEntry = (*currentEntry).nextEntry;

    }

    return 0;

}

int removeByKey(struct HashTable *hashTable, int key) {

    int index = indexFor(key, (*(*hashTable).entryTable).capacity);

    struct Entry **firstEntry = (*(*hashTable).entryTable).table + index;

    int isRemove = 0;

    if (*firstEntry == NULL) {
        return 0;
    }

    if ((**firstEntry).key == key) {

        printf("\nHERE REMOVE");
        struct Entry *helpPointer = *firstEntry;
        *firstEntry = (**firstEntry).nextEntry;
        free(helpPointer);
        isRemove = 1;

    } else {

        struct Entry *previousEntry = *firstEntry;
        struct Entry *currentEntry = (*previousEntry).nextEntry;

        while (currentEntry != NULL) {

            if ((*currentEntry).key == key) {

                (*previousEntry).nextEntry = (*currentEntry).nextEntry;
                free(currentEntry);
                isRemove = 1;

                break;

            }

            currentEntry = (*currentEntry).nextEntry;
            previousEntry = (*previousEntry).nextEntry;

        }

    }

    if (isRemove) {

        (*hashTable).size--;
        return 1;

    } else {

        return 0;

    }

}

struct Entry* createEntry(int value, int key) {

    struct Entry *entry = (struct Entry*)malloc(sizeof(struct Entry));

    if (!isMemmoryAlocatedP(entry)) {

        return NULL;

    }

    (*entry).value = value;
    (*entry).key = key;
    (*entry).nextEntry = NULL;

    return entry;

}

int isHashTableNull(struct HashTable *hashTable) {

    if (hashTable == NULL) {

        printError(HASH_TABLE_IS_NULL);
        return 1;

    }

    return 0;
}

int indexFor(int hashCode, int length) {

    printf("\nHash = %d, length = %d", hashCode, length);
    int result = hashCode % length;
    printf("\nHERE RES");
    return result;

}

//secondary functions
int isMemmoryAlocatedP(void *p) {

    if (p == NULL) {

        printError(MEMMORY_ALOCATED_ERROR);
        return 0;

    }

    return 1;

}

int isMemmoryAlocatedPP(void **p) {

    if (p == NULL) {

        printError(MEMMORY_ALOCATED_ERROR);
        return 0;

    }

    return 1;

}

void printError(int errorMarker) { 

    switch (errorMarker) {
        case MEMMORY_ALOCATED_ERROR:
            printf("\nError! Memmory was not allocated.");
            break;
        case HASH_TABLE_IS_NULL:
            printf("\nError! HashTable is NUll.");
            break;
    }
}

void resetPointersForEntryTable(struct Entry **pp, int capacity) {

    printf("\nAddress two table = %x\t&table = %x", pp, &pp);
    //struct Entry *entry;
    for (int i = 0; i < capacity; i++) {
        // entry = (struct Entry*)malloc(sizeof(struct Entry));
        // (*entry).value = i;
        // (*entry).key = i;
        // (*entry).nextEntry = NULL;
        // *(pp + i) = entry;
        *(pp + i) = NULL;

    }

}

