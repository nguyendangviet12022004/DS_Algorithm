#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i+=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
typedef long long ll;
typedef struct Node{
	int val;
	struct Node* left;
	struct Node* right;
} node;

int* array(int n){
	return (int*)malloc(sizeof(int)*n);
}

void print(int*a, int n){
	ff(i,0,n-1,1) printf("%d ",a[i]);
	printf("\n");
}

int min(int*a, int n){
	int res = a[0];
	ff(i,1,n-1,1) res = (res > a[i]) ? a[i] : res;
	return res;
}

int max(int*a, int n){
	int res = a[0];
	ff(i,1,n-1,1) res = (res < a[i]) ? a[i] : res;
	return res;
}
node* newNode(int val){
	node* root = malloc(sizeof(node));
	root -> val = val;
	root -> left = NULL;
	root -> right = NULL;
	return root;
}

void convertTreeToArray(node*root, int*a, int* n){
	if(!root) return;
	a[*n] = root -> val;
	(*n) ++;
	convertTreeToArray(root-> left, a, n);
	convertTreeToArray(root -> right, a, n);
}


int main(){
	node* root = newNode(0);
	root -> left = newNode(9);
	root -> right = newNode(20);
	root -> right -> left = newNode(15);
	root -> right -> right = newNode(7);
	int*a = array(100);
	int n = 0;
	convertTreeToArray(root, a, &n);

	printf("%d",max(a,n)-min(a,n));
	return 0;
}

