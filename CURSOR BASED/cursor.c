#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    char elem;
    int link;
} Node_t, *Node_p;

typedef struct
{
    Node_t nodes[MAX];
    int avail;
} VirtualHeap_t, *VirtualHeap_p;



VirtualHeap_t init();
int allocSpace(VirtualHeap_p VH);
void deallocSpace(VirtualHeap_p VH, int ndx);
void displayList(VirtualHeap_p VH, int head);
void insertFirst(VirtualHeap_p VH, char data, int *head);
void deleteElem(VirtualHeap_p VH, int *head, char data);
void insertLast(VirtualHeap_p VH, int *head, char data);
void deleteLast(VirtualHeap_p VH, int *head);

int main(){
VirtualHeap_t vheap = init(); 
int head = -1;

insertFirst(&vheap,'X',&head);
insertLast(&vheap,'A',&head);
// insertFirst(&vheap,'A',&head);
// insertFirst(&vheap,'N',&head);
// insertFirst(&vheap,'D',&head);
// insertFirst(&vheap,'E',&head);
// deleteElem(&vheap, &head, 'X');
insertFirst(&vheap,'R',&head);
displayList(&vheap, head);

    return 0;
}



VirtualHeap_t init(){
    VirtualHeap_t newVH;
    int i;
    for(i = -1; i < MAX; i++){
        newVH.nodes[i+1].link = i;
    }
    newVH.avail = MAX-1;
    return newVH;
}

int allocSpace(VirtualHeap_p VH) {
    int retNdx = -1; 
    if (VH->avail != -1) {
        retNdx = VH->avail;
        VH->avail = VH->nodes[retNdx].link;
    }
    return retNdx;
}


void deallocSpace(VirtualHeap_p VH, int ndx){ //ndx is the index that i want to deallocate Space 
    if(ndx > -1 && ndx < MAX){
        VH->nodes[ndx].link = VH->avail; //sets link to the current 
        VH->avail = ndx; // gets the ndx to display the new available index is
    }
}   


void displayList(VirtualHeap_p VH, int head) {
    int current = head;

    while (current != -1) {
        printf("%c ", VH->nodes[current].elem);
        current = VH->nodes[current].link;
    }

    printf("\n");
}


void insertFirst(VirtualHeap_p VH, char data, int *head) {
    int newNdx = allocSpace(VH);

    if (newNdx != -1) {
        VH->nodes[newNdx].elem = data;
        VH->nodes[newNdx].link = *head;
        *head = newNdx;
    }
}


void deleteElem(VirtualHeap_p VH, int *head, char data){
    int* trav = head;
    while(*trav!=-1 && VH->nodes[*trav].elem!=data){
        trav = &VH->nodes[*trav].link;
    }
    if(*trav!=-1){
        int temp  =*trav;
        *trav = VH->nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

    void insertLast(VirtualHeap_p VH, int *head, char data) {
        int newNdx = allocSpace(VH);
        if (newNdx != -1) { 
            VH->nodes[newNdx].elem = data;
            VH->nodes[newNdx].link = -1;  // Set the link of the new node to -1, as it will be the last node
            if (*head == -1) {
                *head = newNdx;  // If the list is empty, make the new node the head
            } else {
                int trav = *head;
                while (VH->nodes[trav].link != -1) {
                    trav = VH->nodes[trav].link;  // Traverse to the last node
                }
                VH->nodes[trav].link = newNdx;  // Update the link of the last node to point to the new node
            }
        }
    }

    void deleteLast(VirtualHeap_p VH, int *head) {
        if (*head != -1) {
            if (VH->nodes[*head].link == -1) {
                deallocSpace(VH, *head);  // If there is only one node, deallocate it
                *head = -1;
            } else {
                int trav = *head;
                while (VH->nodes[VH->nodes[trav].link].link != -1) {
                    trav = VH->nodes[trav].link;  // Traverse to the second-to-last node
                }
                int lastNode = VH->nodes[trav].link;
                deallocSpace(VH, lastNode);  // Deallocate the last node
                VH->nodes[trav].link = -1;  // Update the link of the second-to-last node to -1
            }
        }
    }
