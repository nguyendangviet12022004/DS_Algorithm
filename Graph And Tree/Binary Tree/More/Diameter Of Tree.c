#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} node;

int max(int a, int b){
	return (a > b) ? a : b;
}
node* newNode(int val){
	node* root = (node*)malloc(sizeof(node));
	root -> val = val;
	root -> left = NULL;
	root -> right = NULL;
	return root;
}

int maxVal = 0;

int DFS(node* root){
	if(!root) return 0;
	int left = max(DFS(root -> left), 0);
	int right = max(DFS(root -> right),0);

	
	maxVal = max(maxVal, root -> val + left + right);
	return root -> val + max(left, right);
}

int maxPathSum(node* root){
	DFS(root);
	return maxVal;
}
int main(){
	
}

