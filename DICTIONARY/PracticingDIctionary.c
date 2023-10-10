#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXWORD 45
#define MAXSIZE 26


typedef struct node{
    char word[MAXWORD];
    struct node* link;
}*List;

typedef List Dictionary[MAXSIZE];

void initDictionary(Dictionary D);
int Hash(char* word);
void insertWord(Dictionary D, char* elem);
void deleteWord(Dictionary D, char elem);
void display(Dictionary D);
bool isMember(Dictionary D, char* word);
void makeNull(Dictionary D);



int main(void){




}

void initDictionary(Dictionary D){
    int val;
    for(val = 0; val < MAXSIZE; val++){
        D[val] = NULL;
    }
}
int Hash(char* word){
    char letter = word[0];
    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 'a' + 'A';
    }
    return letter - 'A';
}

void insertWord(Dictionary D, char* elem) {
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

    for(trav = &D[hashval]; *trav!=NULL; trav = &(*trav)->link){}

    List newNode = (List)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("MALLOC FAILED\n");
        return;
    }
    strcpy(newNode->word, upperWord);
    newNode->link = NULL;
    *trav = newNode;
}

bool isMember(Dictionary D, char* word){
    List trav;
    int hashval = Hash(word);
    for(trav = D[hashval]; trav!=NULL && strcmp(trav->word, word)!=0; trav =  trav->link){}
    return (trav==NULL) ? false: true;
}

void makeNull(Dictionary D){
    int null;
    for(null = 0; null < MAXSIZE; null++){
        D[null] = NULL;
    }
}