#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    char elem[MAX];
    int front;
    int rear;
    // this version has a no count sacrificing 1 index
}QUEUE;


QUEUE initQueue();
bool isEmpty(QUEUE Q);
bool isFull(QUEUE Q);
void enqueue(QUEUE *Q, char data);
void dequeque(QUEUE *Q);
void printQueue(QUEUE Q);

int main(void){

}