#include<iostream>
#include<queue>
#define MIN -1000000000
struct node{
	int val;
	node* left;
	node* right;
	node(int val): val(val){}
};

void biggestNodeEachLevel(node* root){
	if(!root) return ;
	queue<node*>qu;
	qu.push(root);
	while(!qu.empty()){
		int n = qu.size();
		int max = MIN;
		for(int i = 0;i < n;i ++){
			node* curr = qu.front();
			qu.pop();
			max = max(curr->val,max);
			if(curr -> left) qu.push(curr -> left);
			if(curr -> right) qu.push(curr -> right);
			
		}
	}
}
