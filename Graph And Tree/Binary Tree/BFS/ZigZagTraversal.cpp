#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int val;
	node* left;
	node* right;
	node(int val): val(val), left(NULL),right(NULL){};
};

void zigZagTraversal(node* root){
	if(!root) return;
	queue<node*> qu;
	qu.push(root);
	int direct = 1;
	while(!qu.empty()){
		int l = qu.size();
		vector<int> temp;
		for(int i = 0;i < l;i ++) {
			node* curr = qu.front();
			temp.push_back(curr->val);
			qu.pop();
			if(curr -> left) qu.push(curr->left);
			if(curr -> right) qu.push(curr->right);
		}
		if(direct == 1) {
			for(int i = 0;i < l;i ++) cout << temp[i] << " ";
		}
		else {
			for(int i = l-1;i >= 0;i--) cout << temp[i] << " ";
		}
		cout << endl;
		direct *= -1;
		
	}
}
int main(){
	node* root = new node(0);
	root -> left = new node(1);
	root -> right = new node(2);
	root -> left-> left = new node(3);
	root -> left -> right = new node(4);
	root -> right -> left = new node(5);
	root -> right -> right = new node(6);
	zigZagTraversal(root);
	return 0;
}
