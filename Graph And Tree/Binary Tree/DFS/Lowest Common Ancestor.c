#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
#define MAX 1000000001

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} node;

node* newNode(int val)
{
	node* root = (node*)malloc(sizeof(root));
	root -> val = val;
	root -> left = NULL;
	root -> right = NULL;
}

node* lowestCommonAncestor(node* root, node* p, node* q)
{
	if(!root) return NULL;
	if(root == p || root == q) return root;
	
	node* left = lowestCommonAncestor(root-> left, p, q);
	node* right = lowestCommonAncestor(root -> right, p, q);
	
	if(left && right) return root;
	if(left) return left;
	return right;
}
