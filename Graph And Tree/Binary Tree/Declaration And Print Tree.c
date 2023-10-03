#include<stdio.h>
#include<stdlib.h>

#define ff(i, a , b , s) for(int i = a;i <= b;i +=s)
#define fl(i, a , b , s) for(int i = a;i >= b;i -=s)
typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} node;

node* newNode(int val)
{
	node* res = (node*)malloc(sizeof(node));
	res -> val = val ;
	res -> left = NULL;
	res -> right = NULL;
	return res;
}

void printTree(node* root, int level)
{
	if(!root) return ;

	printTree(root -> left, level + 1);
	ff(i , 1 , level , 1) printf("   ");
	printf("%d\n",root->val);
	printTree(root -> right, level + 1);
}

int main()
{
	node* root = newNode(1);
	root -> left = newNode(2);
	root -> right = newNode(3);
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);
	root -> right -> left = newNode(6);
	root -> right -> right = newNode(7);
	printTree(root,0);
}

