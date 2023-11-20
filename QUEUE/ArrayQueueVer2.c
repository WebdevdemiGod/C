#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct QUEUE{
    char elem[MAX];
    int front;
    int rear;
}*QUEUE;

QUEUE initQueue();
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void enqueue(QUEUE *Q, char data);
void dequeue(QUEUE *Q);
void displayQueue(QUEUE Q);


int main(){
    QUEUE queue = initQueue();
    printf("QUEUE: \n\n");
    enqueue(&queue, 'X');
    enqueue(&queue, 'A');
    enqueue(&queue, 'N');
    enqueue(&queue, 'D');
    enqueue(&queue, 'E');
    enqueue(&queue, 'R');
    displayQueue(queue);

    return 0;
}

QUEUE initQueue(){
    QUEUE Q = (QUEUE)malloc(sizeof(QUEUE));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

bool isEmpty(QUEUE Q){
    return Q->front == -1;
}

bool isFull(QUEUE Q){
    return Q->front ==  MAX-1;
}

void enqueue(QUEUE *Q, char data){
    if(!isFull(*Q)){
        if(isEmpty(*Q)){
            (*Q)->front = 0;
        }
        (*Q)->rear++;
        (*Q)->elem[(*Q)->rear] = data;
    }
}

void dequeue(QUEUE* Q){
    if(!isEmpty(*Q)){
        (*Q)->front++;
    }
    if((*Q)->front > (*Q)->rear){
        (*Q)->front = -1;
        (*Q)->rear = -1;
    }
}
void displayQueue(QUEUE Q){
    QUEUE temp = initQueue();

    while (!isEmpty(Q)) {
        char elem = Q->elem[Q->front];
        printf("[%c] \n", elem); 
        enqueue(&temp, elem);
        dequeue(&Q);
    }

    while (!isEmpty(temp)) {
        char elem = temp->elem[temp->front];
        enqueue(&Q, elem);
        dequeue(&temp);
    }
}