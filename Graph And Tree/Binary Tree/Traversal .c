 #include<stdio.h>
 #include<stdlib.h>
 
 #define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
 #define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
 
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

void preOrderTraversal(node* root)
{
	if(!root) return;
	printf("%d ",root -> val);
	preOrderTraversal(root -> left);
	preOrderTraversal(root -> right);
}

void inOrderTraversal(node* root)
{
	if(!root) return;
	inOrderTraversal(root -> left);
	printf("%d ",root -> val);
	inOrderTraversal(root -> right);
}

void postOrderTraversal(node* root)
{
	if(!root) return;
	postOrderTraversal(root -> left);
	postOrderTraversal(root -> right);
	printf("%d ", root -> val);
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
}
