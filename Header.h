#define CRT_SECTURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
	Definitions
*/
typedef struct node{
	int value;
	struct node* left;
	struct node* right;
} Node;

/*Section B*/
Node* Insert(Node* r, int data);
Node* Delete(Node *node, int data);
int Search(Node* leaf, int key);
int Min(Node *node);
int Max(Node *node);

/*Section D*/
Node* BSTfromPreorder(int* pre, int* preIndex, int key, int min, int max, int size);
Node* BSTfromPreorderandInorder(int* preorder, int preorderSize, int* inorder, int inorderSize);