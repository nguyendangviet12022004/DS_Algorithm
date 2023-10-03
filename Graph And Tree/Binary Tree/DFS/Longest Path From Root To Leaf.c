#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
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

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int LongestPath(node* root)
{
	if(!root) return 0;
	return max(LongestPath(root -> left), LongestPath(root -> right)) + 1;
}


int main()
{
	
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> left -> right = newNode(5);
	printf("%d",LongestPath0(root));
	return 0;
}
