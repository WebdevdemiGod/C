#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue);
void enqueue(Queue *queue, char datum);
char dequeue(Queue *queue);
bool isEmpty(Queue *queue);
bool isFull(Queue *queue);
void makeNull(Queue *queue);
void displayQueue(Queue queue);

void initQueue(Queue *queue) {
    queue->front = 1;
    queue->rear = 0;
}

void enqueue(Queue *queue, char datum) {
    if (!isFull(queue)) {
        queue->data[(++queue->rear % MAX)] = datum;
    }
}

char dequeue(Queue *queue) {
    char retVal = '\0';

    if (!isEmpty(queue)) {
        retVal = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX;
    }

    return retVal;
}

bool isEmpty(Queue *queue) {
    return queue->front == (queue->rear + 1) % MAX;
}

bool isFull(Queue *queue) {
    return queue->front == (queue->rear + 2) % MAX;
}

void makeNull(Queue *queue) {
    initQueue(queue);
}

void displayQueue(Queue queue) {
    puts("\n[Array]\n");

    while (!isEmpty(&queue)) {
        printf("%c ", queue.data[queue.front]);
        dequeue(&queue);
    }

    printf("\n");
}
