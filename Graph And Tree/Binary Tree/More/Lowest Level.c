#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} node;


int min(int a,int b){
	return (a < b) ? b : a;
}
node* newNode(int val){
	node* root = malloc(sizeof(node));
	root -> val = val;
	root -> left = NULL;
	root -> right = NULL;
	return root;	
}

int minLevel(node* root){
	if(!root) return 0;
	if(!root -> left && !root -> right) return 1;
	if(!root -> left) return minLevel(root -> right) + 1;
	if(!root -> right) return minLevel(root -> left) + 1;
	return min(minLevel(root -> right),minLevel(root -> left)) + 1;
}

int main(){
	node* root = newNode(0);
	root -> left = newNode(9);
	root -> right = newNode(20);
	root -> right -> left = newNode(15);
	root -> right -> right = newNode(7);
	printf("%d",minLevel(root));
	return 0;
}
