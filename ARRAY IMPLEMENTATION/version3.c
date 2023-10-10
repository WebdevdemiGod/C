#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    int *elemptr; //poiner to the array(heap)
    int count;
}List;

List initList();
bool isEmpty(List L);
bool isFull(List L);
void insertElem(List *L, int num);
void deleteElem(List *L, int num);
void displayList(List L);

int main(void){
    List L = initList();

    insertElem(&L, 9);

}

List initList(){
    List L;
    L.elemptr = (int*)malloc(sizeof(int)*MAX);
    if(L.elemptr!=NULL){
        L.count = 0; 
    }  
    return L; 
}

bool isEmpty(List L){
    return L.count  == 0;
}

bool isFull(List L){
    return L.count == MAX-1;
}

void insertElem(List *L, int num) {
    int i;
    if (!isFull(*L)) {
        for (i = L->count - 1; i >= 0 && L->elemptr[i] > num; i--) {
            L->elemptr[i + 1] = L->elemptr[i];
        }
        L->elemptr[i + 1] = num;
        L->count++;
    } 
}


void deleteElem(List *L, int num){
    int i,j;
    if(!isEmpty(*L)){
        for(i = L->count-1; i >=0 && L->elemptr[i] > num; i--){}
        for(j = i; j < L->count; j++){
            L->elemptr[j] = L->elemptr[j+1];
        }
        L->count--;
    }
}

void displayList(List L){
    int i;
    for(i = 0; i < L.count; i++){
        printf("[%d]", L.elemptr[i]);
    }
}

    

