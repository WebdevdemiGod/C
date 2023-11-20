#include <stdio.h>
#define MAX 10


typedef struct{
	int elems[MAX];
	int last;
}Heap;

Heap initHeap();
void insertMin(Heap *H, int data);
Heap deleteMin(Heap *H);
void Heapify(Heap H, int index);
void HeapSort(Heap *H);
void printHeap(Heap H);


int main(){


    return 0;
}

Heap initHeap(){
    Heap H;
    H.last = -1;
    return H;
}

void insertmin(Heap* H, int data){
    
}

