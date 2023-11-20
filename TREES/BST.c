#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} *Tree;

//Important Functions
Tree initTree(int );
void insert(Tree* , int );
void deleteNode(Tree* , int );
int member(Tree , int );
int getParent(Tree, int);
Tree findMin(Tree );
Tree findMax(Tree );


//print functions
void printInorder(Tree );
void printPostorder(Tree );
void printPreorder(Tree );



int main(void) {
    
    Tree Nara = initTree(2);
    insert(&Nara, 1);
    insert(&Nara, 3);
    insert(&Nara, 3);
    insert(&Nara, 6);
    insert(&Nara, 4);
    insert(&Nara, 10);

    printf("Inorder: ");
    printInorder(Nara); printf("\n");
    printf("Preorder: ");
    printPreorder(Nara); printf("\n");
    printf("Postorer: ");
    printPostorder(Nara); printf("\n");
    printf("\n");

    int find = member(Nara, 3);
    printf("FOUND %d on the Narra Tree", find);
    

    return 0;
}

Tree initTree(int parent) {
    Tree T = malloc(sizeof(struct tree));
    if (T != NULL) {
        T->data = parent;
        T->left = NULL;
        T->right = NULL;
    }
    return T;
}

void insert(Tree* T, int num) {
    if(*T == NULL){
       *T = initTree(num);
    }else{
        if(num <= (*T)->data){
            insert(&(*T)->left, num);
        }else if(num > (*T)->data){
            insert(&(*T)->right, num);
        }
    } 
}

void delete(Tree* T, int num) {
    if (*T == NULL) {
        printf("NULL TREE");
    }

    if (num < (*T)->data) {
        delete(&(*T)->left, num);
    } else if (num > (*T)->data) {
        delete(&(*T)->right, num);
    } else {
        Tree temp;
        if ((*T)->left == NULL) {
            temp = *T;
            *T = (*T)->right;
        } else if ((*T)->right == NULL) {
            temp = *T;
            *T = (*T)->left;
        } else {
            Tree successor = (*T)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            (*T)->data = successor->data;
            delete(&(*T)->right, successor->data); 
        }
        free(temp);
    }
}



int member(Tree T, int num){
    if(T==NULL){
        printf("NULL TREE");
    }else{
        if(num < T->data){
            return member(T->left, num);
        }else if(num > T->data){
            return member(T->right, num);
        }else{
            return T->data;
        }
    }
}

// int getParent(Tree root, int num) {
//     if (root == NULL || (root->left == NULL && root->right == NULL)) {
//         // No parent for the root or a tree with only one node
//         return -1;
//     }

//     Tree parent = NULL;
//     Tree current = root;

//     while (current != NULL && current->data != num) {
//         parent = current;
//         if (num < current->data) {
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//     }

//     if (current == NULL) {
//         // Node with the given value not found
//         return -1;
//     }

//     return parent->data;
// }
Tree findMin(Tree T){
    while(T!=NULL && T->left!=NULL){
        T = T->left; 
    }
    return T;
}
Tree findMax(Tree T){
    while(T!=NULL && T->right!=NULL){
        T = T->right;
    }
    return T;
}

void printInorder(Tree root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

void printPostorder(Tree root) {
    if(root!=NULL){
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}
void printPreorder(Tree root){
    if(root!=NULL){
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}













