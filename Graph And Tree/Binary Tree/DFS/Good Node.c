#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}
typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
} node;

node* newNode(int val)
{
	node* root = (node*)malloc(sizeof(node));
	root -> val = val;
	root -> left = NULL;
	root -> right = NULL;
	return root;
}

// Good Node is node that there is no other node greater than on the path from root to that node
int NumberOfGoodNodes(node* root,int maxVal)
{
	if(!root) return 0;
	return NumberOfGoodNodes(root -> left, max(maxVal, root -> val)) + NumberOfGoodNodes(root -> right, max(maxVal, root -> val)) + (root -> val >= maxVal);
}

int main()
{
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(2);
	root -> left -> right = newNode(1);
	root -> left -> left = newNode(3);
	root -> right -> left = newNode(2);
	printf("%d",NumberOfGoodNodes(root, root -> val));
	return 0;
}
