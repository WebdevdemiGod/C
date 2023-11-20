#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    char elem[MAX];
    int front;
    int rear;
}QUEUE;

QUEUE initQueue();
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void enqueue(QUEUE *Q, char data);
void dequeue(QUEUE *Q);
void displayQueue(QUEUE Q);


int main(){
    QUEUE Q = initQueue();
    printf("QUEUE: \n\n");
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    enqueue(&Q, 'D');
    

    displayQueue(Q);


    return 0;
}

QUEUE initQueue(){
    QUEUE Q;
    Q.front = -1;
    Q.rear = -1;
    return Q;
}

bool isEmpty(QUEUE Q){
    return Q.front == -1;
}

bool isFull(QUEUE Q){
    return Q.rear == MAX-1;
}

void enqueue(QUEUE *Q, char data){
    if(!isFull(*Q)){
        if(isEmpty(*Q)){
            Q->front = 0;   
        }
        Q->rear++;  //increment rear first
        Q->elem[Q->rear] = data;
        
    }
}

void dequeue(QUEUE *Q){
    if(!isEmpty(*Q)){
        Q->front++;
    }
        if (Q->front > Q->rear) { 
            Q->front = -1;                         
            Q->rear = -1;
        }
}

void displayQueue(QUEUE Q) {
    QUEUE temp = initQueue();

    while (!isEmpty(Q)) {
        char elem = Q.elem[Q.front];
        printf("[%c] \n", elem); 
        enqueue(&temp, elem);
        dequeue(&Q);
    }

    while (!isEmpty(temp)) {
        char elem = temp.elem[temp.front];
        enqueue(&Q, elem);
        dequeue(&temp);
    }
}

