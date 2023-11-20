#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int left;   // Index of the left child in the array
    int right;  // Index of the right child in the array
} TreeNode;

typedef struct {
    TreeNode nodes[MAX_SIZE];
    int root;   // Index of the root node in the array
    int size;   // Current size of the array (number of nodes)
} Tree;

Tree initTree() {
    Tree tree;
    tree.root = -1;  // -1 indicates an empty tree
    tree.size = 0;
    return tree;
}

int createNode(Tree* tree, int data) {
    if (tree->size < MAX_SIZE) {
        int index = tree->size;
        tree->nodes[index].data = data;
        tree->nodes[index].left = -1;  // Initialize left child index to -1 (null)
        tree->nodes[index].right = -1; // Initialize right child index to -1 (null)
        tree->size++;
        return index;
    } else {
        printf("Error: Tree is full.\n");
        return -1;  // Return -1 to indicate an error
    }
}

void insertLeft(Tree* tree, int parentIndex, int data) {
    if (parentIndex != -1 && tree->size < MAX_SIZE) {
        int leftChildIndex = createNode(tree, data);
        tree->nodes[parentIndex].left = leftChildIndex;
    }
}

void insertRight(Tree* tree, int parentIndex, int data) {
    if (parentIndex != -1 && tree->size < MAX_SIZE) {
        int rightChildIndex = createNode(tree, data);
        tree->nodes[parentIndex].right = rightChildIndex;
    }
}

void inorderTraversal(Tree* tree, int index) {
    if (index != -1) {
        inorderTraversal(tree, tree->nodes[index].left);
        printf("%d ", tree->nodes[index].data);
        inorderTraversal(tree, tree->nodes[index].right);
    }
}

int main() {
    Tree myTree = initTree();

    int rootIndex = createNode(&myTree, 1);
    myTree.root = rootIndex;

    insertLeft(&myTree, rootIndex, 2);
    insertRight(&myTree, rootIndex, 3);

    insertLeft(&myTree, myTree.nodes[rootIndex].left, 4);
    insertRight(&myTree, myTree.nodes[rootIndex].left, 5);

    printf("Inorder Traversal: ");
    inorderTraversal(&myTree, myTree.root);
    printf("\n");

    return 0;
}
