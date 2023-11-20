

#include <stdio.h>
#include <stdlib.h>

//structure to represent a node in the priority queue
typedef struct node{
	int data;
	int prio; //the prio number
}Node;

//structure to represent the priority queue
typedef struct queue{
	Node *arr;
	int capacity; // is the max
	int size;//count
}Queue;

Queue *initQueue(int capacity); //function to initialize a prio queue
void swap(Node *a, Node *b); //function to swap 2 nodes
void heapify(Queue *Q, int index); //function to heapify the prio queue
void enqueue(Queue* Q, int data, int priority); // Function to enqueue a new element into the prio queue(insert)
Node deleteMax(Queue* Q);//function to extract the max node with the highest priority(delete min)
void printQueue(Queue * Q);//prints the prio queue

int main(){
	
	Queue *Q = initQueue(10);
	
	enqueue(Q, 12, 4);
    enqueue(Q, 1, 6);
    enqueue(Q, 3, 1);
    enqueue(Q, 6, 6);
	
	printf("Priority Queue: ");
	printQueue(Q);
	
	Node max = deleteMax(Q);
	printf("Max node is: %d, with a priority of %d\n", max.data, max.prio); 
	
	printf("Priority Queue after extracting max: ");
	printQueue(Q);
	
}

Queue *initQueue(int capacity){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->arr = (Node*)malloc(sizeof(Node) * capacity);
	Q->capacity = capacity;
	Q->size = 0;
	return Q;
}

void swap(Node *a, Node *b){
	Node temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(Queue *Q, int index){
	//assigning of values
	int largest = index; //assumes largest is current index
	int leftChild = 2 * index + 1; //find left child
	int rightChild = 2 * index + 2; //find right child
	
	//checks for left child's existence and if its priority is greater than priority of the current largest node, if true update largest to be index of left child.
	if(leftChild < Q->size && Q->arr[leftChild].prio > Q->arr[largest].prio){ 
		largest = leftChild;
	}
	//checks for right child's existence and if its priority is greater than priority of the current largest node, if true update largest to be index of right child.
	if(rightChild < Q->size && Q->arr[rightChild].prio > Q->arr[largest].prio){
		largest = rightChild;
	}
	//if current largest node is not the current node, swap current node with largest, call heapify to ensure heap property is maintained
	if(largest != index){
		swap(&(Q->arr[index]), &(Q->arr[largest]));
		heapify(Q, largest);
	}
	
}
void enqueue(Queue* Q, int data, int priority){
	//Checks if the queue is full
	if(Q->size == Q->capacity){
		printf("The Queue is full\n");
	}else{
		//actual insertion happens here
		Q->size++; //increment size to reflect newly enqueueed node
		int index = Q->size - 1;
		int parent = (index - 1)/2;
		Q->arr[index].data = data;
		Q->arr[index].prio = priority;
		
		//Ensures the max heap property
		while(index != 0 && Q->arr[parent].prio < Q->arr[index].prio){
			swap(&(Q->arr[index]), &(Q->arr[parent]));
			index = parent;
		}
	}
}

Node deleteMax(Queue* Q){
	//Check if queue is empty, if empty return nothing
	if(Q->size <= 0){
		printf("Queue empty");
		Node nothing = {0, 0};
		return nothing;
	}
	//Special case: Check if there is only 1 element in the queue, then simply decrease size to signify the deleteMax then returns the only element
	if(Q->size == 1){
		Q->size--;
		return Q->arr[0];
	}
	//Normal extraction from Max Heap
	Node root = Q->arr[0]; //Store the maximum priority element in variable root
	Q->arr[0] = Q->arr[Q->size - 1]; //replace with last number of array
	Q->size--; //Decrement size to signify the deleteMax
	heapify(Q, 0); //Call heapify to ensure heap property is retained
	return root; 
}

void printQueue(Queue *Q){
	printf("\nDATA:\t\tPRIO: \n");
	for(int i = 0; i < Q->size; i++){
		printf("%d\t\t%d\n", Q->arr[i].data, Q->arr[i].prio);
	}
}

