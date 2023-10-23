#include<iostream>
#include<queue>
using namespace std;


struct node{
	int val;
	node* left;
	node* right;
	node(int val):val(val){}
};

int sumOfDepestLevel(node* root){
	if(!root) return 0;
	queue<node*> qu;
	qu.push(root);
	int s = 0;
	
	while(!qu.empty()){
		int l = qu.size();
		s = 0;
		for(int i = 0;i < l;i ++){
			node* curr = qu.front();
			qu.pop();
			s += curr -> val;
			if(curr -> left) qu.push(curr -> left);
			if(curr -> right) qu.push(curr -> right);
		}
	}
	return s;
}
int main(){
	node* root = new node(1);
	root -> left = new node(2);
	root -> left = new node(3);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> right -> right = new node(6);
	cout << sumOfDepestLevel(root);
}

