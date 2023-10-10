#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 20

typedef struct node{
    int *elemptr; //poiner to the array
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
    insertElem(&L, 90);
    insertElem(&L, 100);
    insertElem(&L, 80);
    insertElem(&L, 1);


    displayList(L);

}

List initList(){
    List L = (List)malloc(sizeof(struct node));
    if(L==NULL){
        printf("MALLOC FAILED");
    }
    L->count = 0;
    L->elemptr = (int*)malloc(sizeof(int)*MAX);
    if(L->elemptr==NULL){
        printf("MALLOC FAILED");
    }
    return L;
}

bool isFull(List L){
    return L->count == MAX-1;
}

bool isEmpty(List L){
    return L->count == 0;
}

void insertElem(List *L, int num){
    int i;
    if(!isFull(*L)){
        for(i=(*L)->count-1; i >=0 && (*L)->elemptr[i] > num; i--){
            (*L)->elemptr[i+1] = (*L)->elemptr[i];
        }
        (*L)->elemptr[i+1] = num;
        (*L)->count++;
    }
}

void deleteElem(List *L, int num){
    int i,j;
    if(!isEmpty(*L)){
        for(i = (*L)->count; i >=0 && (*L)->elemptr[i] != num;i--){}
        for(j = i; j < (*L)->count; j++){
            (*L)->elemptr[j] = (*L)->elemptr[j+1];
        }
        (*L)->count--;
    }
}
void displayList(List L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("[%d]\n", L->elemptr[i]);
    }
}

