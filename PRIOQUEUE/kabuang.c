/*
Author: Xander Jacob Labide
PARTIALLY ORDERED TREE(POT)
Characteristics of a POT:
- it is a Binary Tree
- Balanced Tree in which the height is the is a minimum for the num of nodes
- all mising leaves must be in the left
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define leftChild 2 * index + 1 //formula(lc are placed on an odd index)
#define rightChild 2* index + 2 //formula(rc are placed on an even index)
#define parentformula (index -1)/2 //formula to get the parent
#define empty Node nothing = {0,0};

typedef struct{
   int data; //the data ofc
   int prio; // this will be the priority number (lets say the ndx number)
}Node;


//structure definition to define the prioqueue
typedef struct{
    Node *arr; //pointer to a dynamic Node
    int capacity; //the MAX
    int size;//or the count
}Queue;

//functions:

Queue* initPrioQueue(int ); //initialize the prioqueue
void swap(Node*, Node* ); //swap the elemets
void enqueue(Queue *, int , int); //(basically insert) enqueue a new element in the Prioqueue
bool isFull(Queue );//checks the prioQueue if its full returns true
bool isEmpty(Queue );//checks the prioQueue if its empty returns true
Node dequeue(Queue *);//(aka deletemin)delete then return the node with the highest priority number
void minheapify(Queue *, int );//heapify's the prioqueue

void printPrioQueue(Queue *);//prints the prio queue


int main(){
    Queue* Q = initPrioQueue(10);
    enqueue(Q, 12, 4);
    enqueue(Q, 45, 6);
    enqueue(Q, 3, 1);
    enqueue(Q, 6, 5);
    
    printPrioQueue(Q);
    dequeue(Q); 
    
    printPrioQueue(Q);
    return 0;
}


Queue* initPrioQueue(int capacity){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->arr = (Node*)malloc(sizeof(Node)*capacity);
    Q->capacity = capacity;
    Q->size = 0;
    return Q;
}


void swap(Node *a, Node *b){
    Node temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

bool isFull(Queue Q){
    return Q.size == Q.capacity;
}

bool isEmpty(Queue Q){
    return Q.size == 0; 
}


void enqueue(Queue *Q, int data, int priority){  // or rename it inserrt
    if(!isFull(*Q)){
        Q->size++;
        int index = Q->size - 1;
        int parent = parentformula;
        Q->arr[index].data = data;
        Q->arr[index].prio = priority;
        minheapify(Q, index); //min or max ur choice
    }else{
        printf("QUEUE IS FULL ATM");
    }
}


void minheapify(Queue *Q, int index) { //basically arranges least to greatest
    int smallest = index;
    int lc = leftChild;
    int rc = rightChild;

    // Check if left child exists and has a priority smaller than the current smallest
    if (lc < Q->size && Q->arr[lc].prio < Q->arr[smallest].prio) {
        smallest = lc;
    }

    // Check if right child exists and has a priority smaller than the current smallest
    if (rc < Q->size && Q->arr[rc].prio < Q->arr[smallest].prio) {
        smallest = rc;
    }

    // If the smallest node is not the current node, swap them and recursively call minHeapify
    if (smallest != index) {
        swap(&(Q->arr[index]), &(Q->arr[smallest]));
        minheapify(Q, smallest);
    }
}

Node dequeue(Queue* pq){
   // Check if queue is empty, if empty return nothing
    if(pq->size <= 0){
        printf("Queue empty");
        Node nothing = {0, 0};
        return nothing;
    }
   // Special case: Check if there is only 1 element in the queue, then simply decrease size to signify the dequeue then returns the only element
    if(pq->size == 1){
       pq->size--;
       return pq->arr[0];
   }
   // Normal extraction from Min Heap
   Node root = pq->arr[0]; // Store the smallest priority element in variable root
   pq->arr[0] = pq->arr[pq->size - 1]; // Replace with last number of array
   pq->size--; // Decrement size to signify the dequeue
   minheapify(pq, 0); // Call minheapify to ensure heap property is retained
   return root; 
}




void printPrioQueue(Queue *Q) {
    int i;
    printf("PRIO QUEUE: \n");
    printf("DATA\t\tPRIO\n");
    for (i = 0; i < Q->size; i++) {
        printf("%d\t\t%d\n", Q->arr[i].data, Q->arr[i].prio);
    }
}


