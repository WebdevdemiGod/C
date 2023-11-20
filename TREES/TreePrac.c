#include <stdio.h>
#include <stdlib.h>
#define MAX_Name 20
#define MAX_Course 7
#define MAX 10

typedef struct{
    char fname[MAX_Name];
    char MidI;
    char lname[MAX_Name];
}Name;

typedef struct{
    int ID;
    Name name;
    int age;
    char course [MAX_Course]; 
}StudInfo[MAX];

typedef struct tree {
    StudInfo student;
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


//printing Functions
void printInorder(Tree );
void printPostorder(Tree );
void printPreorder(Tree );



int main(void) {
    
    
    return 0;
}

Tree initTree(int root);
    


void insert(Tree *Nara, int num);
    

















