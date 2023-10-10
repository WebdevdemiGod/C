#include <stdio.h>
#define MAX 10

typedef struct{
    char elem;
    int link;
}node;

typedef struct{
    node nodes[MAX];
    int avail;
}VirtualHeap;


VirtualHeap initVirtualHeap();
int allocSpace(VirtualHeap * VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void insertFirst(VirtualHeap *VH, int *head, char data);
void insertLast(VirtualHeap *VH, int*head, char data);
void deleteElem(VirtualHeap *VH, int *head, char data);
void printList(VirtualHeap VH, int head);
void display(VirtualHeap VH, int head);


int main(){
    VirtualHeap VH = initVirtualHeap();
    int head = -1;
    insertFirst(&VH, &head, 'X');
    insertFirst(&VH, &head, 'A');
    insertLast(&VH, &head, 'N');
    display(VH, head);

}

VirtualHeap initVirtualHeap(){
    int ndx;
    VirtualHeap VH;
    for(ndx = -1; ndx < MAX; ndx++){
        VH.nodes[ndx+1].link = ndx;
    }
    VH.avail = MAX-1;
    return VH;
}

int allocSpace(VirtualHeap *VH){
        
    int retNdx = VH->avail; //the returned index will have the value of avail
    if(retNdx != -1){
        VH->avail = VH->nodes[retNdx].link; //then avail will have the link of the alloced Space 
    }
    return retNdx; 
}

void deallocSpace(VirtualHeap *VH, int ndx){
    if(ndx > -1 && ndx < MAX){
        VH->nodes[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void insertFirst(VirtualHeap *VH, int *head, char data){ //always remember to treat it like a linked list but in an array
    int index = allocSpace(VH);                          //the links are not pointers but integers
    if(index != -1 ){
        VH->nodes[index].elem =data;
        VH->nodes[index].link = *head;
        *head = index;
    }
}

void deleteElem(VirtualHeap *VH, int *head, char data){
    int * trav = head;
    if(*trav != -1){
        for(; *trav!= -1 && VH->nodes[*trav].elem!= data; trav = &VH->nodes[*trav].link){}
        int temp = *trav;
        *trav = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

void insertLast(VirtualHeap *VH, int *head, char data) {
int index = allocSpace(VH);
int trav;

if (index != -1) {
    VH->nodes[index].elem = data;
    VH->nodes[index].link = -1;

    if (*head == -1) {
        *head = index;
    } else {
            
         for (trav = *head; VH->nodes[trav].link != -1; trav = VH->nodes[trav].link) {}
        VH->nodes[trav].link = index;
        }
    }
}

void display(VirtualHeap VH, int head){
    int i;
    for(i = head; i != -1; i = VH.nodes[i].link){
        printf("[%c] === [%d]\n", VH.nodes[i].elem, VH.nodes[i].link);
    }
    printf("\n");
}





