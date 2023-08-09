#include<iostream>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node():val(0) , next(nullptr){}
    Node(int val) : val(val) , next(nullptr){}
    Node(int val, Node* next) : val(val) , next(next){}
};

Node* add(Node* root, int val)
{
    root -> next = new Node(val);
    return root;
}

void print(Node* root)
{
    Node* temp = root;
    while(temp)
    {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
}

Node* reverseRoot(Node* root)
{
    Node* pre = nullptr;
    Node* curr = root;
    while(curr)
    {
        Node* mark = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = mark;
    }
    return pre;
}


int main()
{
    Node* root = new Node(0);
    Node* temp = root;
    ff(i,1,10,1) {
        temp = add(temp,i);
        temp = temp -> next;
    }

    print(reverseRoot(root));
}
