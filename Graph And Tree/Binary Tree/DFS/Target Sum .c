#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
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

int targetSum(node* root, int target)
{
	if(target == 0) return 1;
	if(!root) return 0;
	
	int left = targetSum(root -> left, target - root -> val);
	if(left) return 1;
	
	return targetSum(root -> right, target - root -> val);
}

int main()
{
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(5);
	root -> left -> left = newNode(3);
	root -> left -> right = newNode(101);
	printf("%d",targetSum(root, 6));
}


