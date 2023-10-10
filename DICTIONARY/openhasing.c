#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10


typedef struct node{
    int data;
    struct node* link;
}*List;

typedef List Dictionary[MAX];

void initDictionary(Dictionary D);
int Hash(int num);
void insertElem(Dictionary D, int newData);
void deleteElem(Dictionary D, int data);
void displayHash(Dictionary D);
bool isMember(Dictionary D, int num);
void makeNull(Dictionary D);


int main(){
    Dictionary Merriam;

    initDictionary(Merriam);
    insertElem(Merriam, 0);
    insertElem(Merriam, 20);
    insertElem(Merriam, 56);
    // displayHash(Merriam);

    deleteElem(Merriam, 20);

    displayHash(Merriam);

    return 0;
}


void initDictionary(Dictionary D) {
    int x;
    for (x = 0; x < MAX; x++) {
        D[x] = NULL;
    }
}

int Hash(int num){
    return num % 10;
}

bool isMember(Dictionary D, int num){
    List *trav;
    int hashval = Hash(num);

    for(trav = &(D)[hashval]; *trav!=NULL && (*trav)->data!= num; trav = &(*trav)->link){}
	return (*trav == NULL) ? false : true;
}

void insertElem(Dictionary D, int newData){
    int hashval = Hash(newData);
    List trav;
    if (!isMember(D, newData)) {
        List newNode = (List)malloc(sizeof(struct node));
        newNode->data = newData;
        newNode->link = NULL;
        if (D[hashval] == NULL) {
            D[hashval] = newNode;
        } else {
            for (trav = D[hashval]; trav->link != NULL; trav = trav->link) {}
            trav->link = newNode;
        }
    }
}


void deleteElem(Dictionary D, int data){
    int hashval = Hash(data);
    List* trav;
    for (trav = &(D[hashval]); *trav != NULL && ((*trav)->data != data); trav = &(*trav)->link) {}
            List temp = *trav;
            *trav = (*trav)->link;
            free(temp);
}



void displayHash(Dictionary D) {
    List trav;
    int hashval;

    for (hashval = 0; hashval < MAX; hashval++) {
        printf("[%d] => ", hashval);

        for (trav = D[hashval]; trav != NULL; trav = trav->link) {
            printf("%d => ", trav->data);
        }

        printf(" NULL\n");
    }
}



void makeNull(Dictionary D){
    int makenull;
    for(makenull = 0; makenull < MAX; makenull++){
        D[makenull] = NULL;
    }
}




