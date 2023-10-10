#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int elem;
    struct node* link;
} List_t, *List_p;


void insertFirst(List_p *L, int num);
void insertLast(List_p *L, int num);
void insertAt(List_p*L, int pos,int num);
void displayList(List_p L);

int main(){
    List_p L = NULL;

    insertFirst(&L, 9);
    insertLast(&L, 10);
    displayList(L);

}

void insertFirst(List_p *L, int num){
    List_p new = (List_p)malloc(sizeof(List_t));
    new->elem = num;
    new->link = *L;
    *L = new;
}

void insertLast(List_p *L, int num) {
    List_p new = (List_p)malloc(sizeof(List_t));
    new->elem = num;
    new->link = NULL;
    List_p *current = L;  
    while (*current != NULL) {
        current = &(*current)->link;  
    }
    *current = new;
}


void insertAt(List_p* L, int num, int position) {
    if (position < 0) {
        printf("Invalid position\n");
    }

    List_p new = (List_p)malloc(sizeof(List_t));
    new->elem = num;
    new->link  = NULL;

    if (position == 0) {
        new->link = *L;
        *L = new;
    } else {
        List_p current = *L;
        int i = 0;

        while (current != NULL && i < position - 1) {
            current = current->link;
            i++;
        }
        new->link = current->link;
        current->link = new;
    }
}
void displayList(List_p L){
    while(L!=NULL){
        printf("[%d]->", L->elem);
        L = L->link;
    }
}



