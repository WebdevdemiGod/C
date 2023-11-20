#ifndef PSEUDO_HEAP_H
#define PSEUDO_HEAP_H

#define MAX_SIZE 128

typedef struct {
    struct {
        int elem;
        int link;
    } nodes[MAX_SIZE];
    int avail;
} PseudoHeap;

void initPseudoHeap(PseudoHeap *heap) {
    int index;

    for (index = 0; index < MAX_SIZE; index++) {
        heap->nodes[index].link = index - 1;
    }

    heap->avail = MAX_SIZE - 1;
}

int allocSpace(PseudoHeap *heap) {
    int index = heap->avail;

    if (index != -1) {
        heap->avail = heap->nodes[index].link;
    }

    return index;
}

void deallocSpace(PseudoHeap *heap, int index) {
    if (index > -1 && index < MAX_SIZE) {
        heap->nodes[index].link = heap->avail;
        heap->avail = index;
    }
}

#endif // PSEUDO_HEAP_H