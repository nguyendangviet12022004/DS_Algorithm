#include<iostream>
#include<queue>
using namespace std;


struct node{
	int val;
	node* left;
	node* right;
	node(int val): val(val), left(NULL), right(NULL){
	}
};


void BFS(node* root){
	if(!root) return ;
	queue<node*> qu;
	qu.push(root);
	while(!qu.empty()){
		node* curr = qu.front();
		cout << curr -> val << " ";
		if(curr -> left) qu.push(curr->left);
		if(curr -> right) qu.push(curr->right);
		
		qu.pop();
	}
}

int main(){
	node* root = new node(10);
	root -> left = new node(9);
	root -> right = new node(10);
	root -> left -> left = new node(12);
	root -> left -> right = new node(12);
	BFS(root);
	return 0;
}
