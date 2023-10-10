#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 20

typedef struct{
    int data[MAX];
    int count;
}*List;


List initList();
bool isEmpty(List L);
bool isFull(List L);
void insertElem(List *L, int num);
void deleteElem(List *L, int num);
void displayList(List L);

int main(void){

    List L = initList();
    system("cls");
    insertElem(&L, 16);
    insertElem(&L, 4);
    insertElem(&L, 15);
    insertElem(&L, 9);
    deleteElem(&L, 9);

    displayList(L);
}

List initList(){
    List L = malloc(sizeof(*L));
    if(L!=NULL){
        L->count = 0;
        printf("List Initialized\n\n");
    }
    return L; 
}

bool isEmpty(List L){
    return L->count == 0;
}

bool isFull(List L){
    return L->count  == MAX-1;
}

void insertElem(List *L, int num){
    int i;
    if(!isFull(*L)){
        for(i = (*L)->count-1; i >=0 && (*L)->data[i] > num; i--){
            (*L)->data[i+1] = (*L)->data[i];
        }
        (*L)->data[i+1] = num;
        (*L)->count++;
    }
}


void deleteElem(List*L, int num){
    int i,j;
    if(!isEmpty(*L)){
        for(i = (*L)->count-1; i >=0 && (*L)->data[i] != num; i--){}
            for(j = i; j < (*L)->count; j++){
                (*L)->data[j] = (*L)->data[j+1]; 
            }
            (*L)->count--;
    }
}

void displayList(List L){
    int i;
    if(!isEmpty(L)){
        printf("List: \n");
        for(i = 0; i < L->count; i++){
            printf("[%d]\n", L->data[i]);
        }
    }else{
        printf("WAY SUD BADI");
    }
}

