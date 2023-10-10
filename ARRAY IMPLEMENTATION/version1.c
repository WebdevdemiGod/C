#include <stdio.h>
#include <stdbool.h>
#define MAX 20

typedef struct{
    int data[MAX];
    int count;
}List;


List initList();
bool isEmpty();
bool isFull();
void insertElem();
void deleteElem();
void displayList();

int main(void){
    List L = initList();

    insertElem(&L, 93);
    insertElem(&L, 43);
    insertElem(&L, 53);
    insertElem(&L, 63);
    deleteElem(&L, 43);

    displayList(L);
}

List initList(){
    List L;
    L.count = 0;
    return L;
}

bool isEmpty(List L){
    return L.count == 0;
}

bool isFull(List L){
    return L.count == MAX-1;
}

void insertElem(List *L, int num){
    int i;
    if(!isFull(*L) ){
        for(i = L->count-1; i >=0 && L->data[i] > num; i--){
            L->data[i+1] = L->data[i];
        }
        L->data[i+1] = num;
        L->count++; 
    }
}
void deleteElem(List *L, int num){
    int i,j;
    if(!isEmpty(*L)){
        for(i = L->count-1; i >= 0 && L->data[i]!= num; i--){}
            for(j = i; j < L->count; j++){
                L->data[j] = L->data[j+1];
            }
            L->count--;
        
    }
}

void displayList(List L){
    if (!isEmpty(L)) {
        printf("List: \n");
        for (int i = 0; i < L.count; i++) {
            printf("[%d]\n", L.data[i]);
        }
        printf("\n");
    } else {
        printf("List is empty.\n");
    }
}