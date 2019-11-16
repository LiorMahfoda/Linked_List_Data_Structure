#include "Header.h"

Node* Insert(Node* r, int data){
	if (r == NULL) {
		r = (Node*) malloc(sizeof(Node)); // create a new node
		r->value = data;  // insert data to new node
						  // make left and right childs empty
		r->left = NULL;
		r->right = NULL;
	}
	// if the data is less than node value then we must put this in left sub-tree
	else if (data < r->value)
		r->left = Insert(r->left, data);
	// else this will be in the right subtree
	else 
		r->right = Insert(r->right, data);
	return r;
}

Node* Delete(Node *node, int data)
{
	Node *temp;
	if (node == NULL)
		printf("Element Not Found");

	else if (data < node->value)
		node->left = Delete(node->left, data);
	else if (data > node->value)
		node->right = Delete(node->right, data);
	else
	{
		/* Now We can delete this node and replace with either minimum element
		in the right sub tree or maximum element in the left subtree */
		if (node->right && node->left)
		{
			/* Here we will replace with minimum element in the right sub tree */
			temp = Min(node->right);
			node->value = temp->value;
			/* As we replaced it with some other node, we have to delete that node */
			node->right = Delete(node->right, temp->value);
		}
		else
		{
			/* If there is only one or zero children then we can directly
			remove it from the tree and connect its parent to its child */
			temp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			free(temp); /* temp is longer required */
		}
	}
	return node;
}

int Search(Node* leaf, int key){
	if (leaf){
		if (leaf->value == key)
			return leaf->value;
		else if (key < leaf->value)
			return Search(leaf->left,key);
		else
			return Search(leaf->right, key);
	}
	return NULL; // if key doesnt exist
}

int Min(Node *node)
{
	if (node == NULL){
		/* There is no element in the tree */
		return -1;
	}
	if (node->left) /* Go to the left sub tree to find the min element */
		return Min(node->left);
	else
		return node->value;
}
int Max(Node *node)
{
	if (node == NULL){
		/* There is no element in the tree */
		return -1;
	}
	if (node->right) /* Go to the right sub tree to find the max element */
		return Max(node->right);
	else
		return node->value;
}

/*
	Main class
*/
int main()
{
	Node* root = NULL;

	int find = 0;
	root = Insert(root, 5);
	root = Insert(root, 3);
	root = Insert(root, 6);
	root = Insert(root, 10);
	root = Insert(root, 2);
	root = Delete(root, 3); // deletes node
	root = Delete(root, 4); // node doesnt exists
	find = Search(root, 5); // search return 5
	printf("\n %d \n", find);
	find = Search(root, 8); // search return 0
	printf(" %d \n", find);
	printf(" %d \n", Min(root));
	printf(" %d \n", Max(root));
	free(root);
	return 0;
}
