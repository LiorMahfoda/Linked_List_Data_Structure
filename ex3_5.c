#include "Header.h"

Node* BSTfromPreorder(int* pre, int* preIndex, int key, int min, int max, int size) {
	Node* root = NULL;
	// Base case
	if (*preIndex >= size)
		return NULL;

	// If current element of pre[] is in range, then
	// only it is part of current subtree
	if (key > min && key < max){
		// Allocate memory for root of this subtree and increment *preIndex
		root = (Node *) malloc(sizeof(Node));
		root->value = key;
		root->left = root->right = NULL;
		*preIndex +=  1;

		if (*preIndex < size){
			// Contruct the subtree under root
			// All nodes which are in range {min .. key} will go in left
			// subtree, and first such node will be root of left subtree.
			root->left = BSTfromPreorder(pre, preIndex, pre[*preIndex],
				min, key, size);

			// All nodes which are in range {key..max} will go in right
			// subtree, and first such node will be root of right subtree.
			root->right = BSTfromPreorder(pre, preIndex, pre[*preIndex],
				key, max, size);
		}
	}
	return root;
}

Node* BSTfromPreorderandInorder(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int i = 0;

	if (preorderSize == 0) 
		return NULL;
	Node* root = (Node *)malloc(sizeof(Node));
	root->value = *preorder;

	while (inorder[i] != *preorder)
		++i;

	root->left = BSTfromPreorderandInorder(preorder + 1, i, inorder, i);
	root->right = BSTfromPreorderandInorder(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);

	return root;
}

/*
	Main class
*/
int main() {
	int index = 0;
	int preorder[] = {6,2,1,4,5,8,10,9};
	int preorder2[] = {5,20,2,18,6,3,100,4,7,1,0};
	int inorder[] = {18,2,6,20,3,4,100,5,1,7,0};
	
	Node* Bst = BSTfromPreorder(preorder, &index, preorder[0], INT_MIN, INT_MAX, sizeof(preorder) / sizeof(preorder[0]));
	Node* Bst2 = BSTfromPreorderandInorder(preorder2, sizeof(preorder2) / sizeof(preorder2[0]),
		inorder, sizeof(inorder) / sizeof(inorder[0]));
	free(Bst);
	free(Bst2);
	return 0;
}