#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 32
#define DELETED 'x'
#define EMPTY '-'

typedef struct {
    char data;
    int next;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;
} VirtualHeap;

VirtualHeap initVR();
int Hash(char data);
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap* VH, int ndx);
void insertElem(VirtualHeap* VH, char data);
void deleteElem(VirtualHeap* VH, char data);
bool isMember(VirtualHeap* VH, char data);
void display(VirtualHeap* VH);

int main(void) {
    VirtualHeap VH = initVR();
    insertElem(&VH, 'A');
    insertElem(&VH, 'B');
    insertElem(&VH, 'C');
    // insertElem(&VH, 'D');
    // insertElem(&VH, 'E');
    // deleteElem(&VH, 'F'); // Deleted letter F

    display(&VH);

    return 0;
}

VirtualHeap initVR() {
    VirtualHeap newVH;
    int i;
    for (i = -1; i < MAX; i++) {
        newVH.nodes[i + 1].data = EMPTY;
        newVH.nodes[i + 1].next = i;
    }
    newVH.avail = 0;
    return newVH;
}

int Hash(char data) {
    return (toupper(data) - 'A') % MAX;
}

int allocSpace(VirtualHeap* VH) {
    int retNdx = VH->avail;
    if (retNdx != -1) {
        VH->avail = VH->nodes[retNdx].next;
    }
    return retNdx;
}

void deallocSpace(VirtualHeap* VH, int ndx) {
    if (ndx > -1 && ndx < MAX) {
        VH->nodes[ndx].next = VH->avail;
        VH->avail = ndx;
    }
}

void insertElem(VirtualHeap* VH, char data) {
    int hashValue = Hash(data);
    int newNodeIndex = allocSpace(VH);
    if (newNodeIndex != -1) {
        VH->nodes[newNodeIndex].data = data;
        VH->nodes[newNodeIndex].next = VH->nodes[hashValue + 1].next;
        VH->nodes[hashValue + 1].next = newNodeIndex;
    }
}

void deleteElem(VirtualHeap* VH, char data) {
    int hashValue = Hash(data);
    int current = VH->nodes[hashValue + 1].next;
    int prev = hashValue + 1;

    while (current != -1) {
        if (VH->nodes[current].data == data) {
            VH->nodes[prev].next = VH->nodes[current].next;
            VH->nodes[current].data = DELETED;
            deallocSpace(VH, current);
            break;
        }

        prev = current;
        current = VH->nodes[current].next;
    }
}

bool isMember(VirtualHeap* VH, char data) {
    int hashValue = Hash(data);
    int current = VH->nodes[hashValue + 1].next;
    while (current != -1) {
        if (VH->nodes[current].data == data) {
            return true;
        }
        current = VH->nodes[current].next;
    }
    return false;
}

void display(VirtualHeap* VH) {
    printf("data  link\n");
    for (int i = 0; i < MAX; i++) {
        if (VH->nodes[i].next != -1) {
            printf("[%c\t%2d]\n", VH->nodes[i].data, VH->nodes[i].next);
        } else {
            printf("[%c\t%2d] ", VH->nodes[i].data, VH->nodes[i].next);
            if (VH->nodes[i].data == DELETED) {
                printf("deleted");
            }
            printf("\n");
        }
    }
}
