#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 45
#define MAXSIZE 26

typedef struct node {
    char word[MAXWORD];
    struct node* link;
} *List;

typedef List Dictionary[MAXSIZE];

void initDictionary(Dictionary D);
int Hash(char* word);
void insertElem(Dictionary D, char* elem);
void deleteElem(Dictionary D, char* word);
void displayHash(Dictionary D);
bool isMember(Dictionary D, char* word);
void makeNull(Dictionary D);

int main() {
    Dictionary Merriam;

    initDictionary(Merriam);
    insertElem(Merriam, "Apple");
    insertElem(Merriam, "Apple");
    insertElem(Merriam, "Axe");
    insertElem(Merriam, "Boy");
    insertElem(Merriam, "Bat");

    displayHash(Merriam);

    return 0;
}

void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAXSIZE; x++) {
        D[x] = NULL;
    }
}

int Hash(char* word) {
    char firstChar = word[0];
    if (firstChar >= 'a' && firstChar <= 'z') {
        firstChar = firstChar - 'a' + 'A';
    }
    return firstChar - 'A';
}


bool isMember(Dictionary D, char* word) {
    List* trav;
    int hashval = Hash(word);

    for (trav = &(D)[hashval]; *trav != NULL && strcmp((*trav)->word, word) != 0; trav = &(*trav)->link) {}
    return (*trav == NULL) ? false : true;
}

void insertElem(Dictionary D, char* elem) {
    char upperWord[MAXWORD];
    int i;
    for (i = 0; elem[i]; i++) {
        upperWord[i] = toupper(elem[i]);
    }
    upperWord[i] = '\0';

    List* trav;
    int hashval = Hash(upperWord);

    if (isMember(D, upperWord)) {
        printf("Word already exists in the dictionary: %s\n", upperWord);
    }

    List newNode = (List)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("MALLOC FAILED\n");
    }
    strcpy(newNode->word, upperWord);
    newNode->link = NULL;
    
    trav = &D[hashval];

    
    if (*trav == NULL || strcmp(upperWord, (*trav)->word) < 0) {
        newNode->link = *trav;
        *trav = newNode;
    } else {
        
        while ((*trav)->link != NULL && strcmp(upperWord, (*trav)->link->word) > 0) {
            trav = &(*trav)->link;
        }
        newNode->link = (*trav)->link;
        (*trav)->link = newNode;
    }
}

void deleteElem(Dictionary D, char* word) {
    int hashval = Hash(word);
    List* trav;
    for (trav = &(D[hashval]); *trav != NULL && strcmp((*trav)->word, word) != 0; trav = &(*trav)->link) {}
    List temp = *trav;
    *trav = (*trav)->link;
    free(temp);
}
void displayHash(Dictionary D) {
    List trav;
    char key = 'A';
    for (int hashval = 0; hashval < MAXSIZE; hashval++) {
        printf("[%c]=> ", key);

        if (D[hashval] != NULL) {
            for (trav = D[hashval]; trav != NULL; trav = trav->link) {
                printf("[%s] => ", trav->word);
            }
        }
        printf(" \n");
        key++;
    }
}
void makeNull(Dictionary D) {
    int makenull;
    for (makenull = 0; makenull < MAXSIZE; makenull++) {
        D[makenull] = NULL;
    }
}
