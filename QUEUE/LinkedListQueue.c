#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char data;
    struct node* link;
}Node;

typedef struct{
    Node* front;
    Node* rear;
}QUEUE;

QUEUE initQueue();
bool isEmpty(QUEUE Q);
void enqueue(QUEUE *Q, char data);
void dequeue(QUEUE *Q);
void displayQueue(QUEUE Q);

int main(){
    QUEUE Q = initQueue();
    enqueue(&Q, 'X');enqueue(&Q, 'A');enqueue(&Q, 'N');enqueue(&Q, 'D');enqueue(&Q, 'E');enqueue(&Q, 'R');
    // dequeue(&Q); dequeue(&Q); dequeue(&Q); dequeue(&Q); dequeue(&Q); dequeue(&Q); dequeue(&Q);
    displayQueue(Q);
}

QUEUE initQueue(){
    QUEUE Q;
    Q.front = NULL;
    Q.rear = NULL;
    return Q;
}

bool isEmpty(QUEUE Q){
    return Q.front == NULL && Q.rear == NULL;
}
 
void enqueue(QUEUE *Q, char data){
    Node *newNode = (Node*)malloc(sizeof(struct node));
    if(newNode== NULL){
        fprintf(stderr,"MALLOC FAILED");
    }
    newNode->data = data;
    newNode->link = NULL;
    
    if(isEmpty(*Q)){
        Q->front = newNode;
        Q->rear = newNode;
    }else{
        Q->rear->link = newNode;
        Q->rear = newNode;
    }
}

void dequeue(QUEUE *Q){
    if(!isEmpty(*Q)){
        Node* temp = Q->front;
        Q->front = Q->front->link;
        if (Q->front == NULL) {
        Q->rear = NULL;
        }
        free(temp);
    }else{
        printf("QUEUE IS NOW EMPTY CALM DOWN DOG!");
    }
}

void displayQueue(QUEUE Q) {
   
}


