#include<iostream>
#include<queue>

struct node{
	int val;
	node* left;
	node* right;
	node(int val): val(val){
	}
};


void rightMostNode(node* root){
	if(!root) return 0;
	queue<node*> qu;
	qu.push(root);
	while(!qu.empty()){
		cout << qu.back() -> val << endl;
		int n = qu.size();
		queue<node*> temp;
		for(int i = 0;i < n;i ++){
			node* curr = qu.front();
			qu.pop();
			if(curr -> left) qu.push(curr -> left);
			if(curr -> right) qu.push(curr -> right);
		} 
	}
}

int main(){
	
}
