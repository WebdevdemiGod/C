#include "pseudo_heap.h"
#include <stdio.h>

typedef int Stack;

void push(Stack *, char);
void pop(Stack *);
char peek(Stack);
void displayStack(Stack);

PseudoHeap g_heap;

int main(void) {
    Stack top = -1;
    char ch;

    initPseudoHeap(&g_heap);

    for (ch = 'A'; ch <= 'Z'; ch++) {
        push(&top, ch);
    }

    displayStack(top);
    return 0;
}

void push(Stack *top, char data) {
    int node = allocSpace(&g_heap);

    if (node != -1 && data != '\0') {
        g_heap.nodes[node].elem = data;
        g_heap.nodes[node].link = *top;
        *top = node;
    }
}

void pop(Stack *top) {
    if (*top != -1) {
        int temp = *top;
        *top = g_heap.nodes[temp].link;
        deallocSpace(&g_heap, temp);
    }
}

char peek(Stack top) { return (top == -1) ? '\0' : g_heap.nodes[top].elem; }

void displayStack(Stack top) {
    Stack temp = -1;

    while (top != -1) {
        push(&temp, peek(top));
        pop(&top);
        printf("%3d[ %c | %3d ]\n", temp, peek(temp), g_heap.nodes[temp].link);
    }

    while (temp != -1) {
        push(&top, peek(temp));
        pop(&temp);
    }
}