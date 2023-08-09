#include<iostream>
#define ff(i,a,b,s) for(int i = a;i <= b;i+=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int val) : val(val) , next(nullptr) {}
};

void add(Node* root, int val)
{
    root -> next = new Node(val);
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
// pre -> A -> B -> next ;
Node* swapPair(Node* root)
{
    if(!root || !root -> next) return root;

    Node* result = root -> next;

    Node* pre = nullptr;
    Node* A = root;

    while(A && A -> next)
    {
        Node* B = A -> next;
        Node* next = B -> next;

        if(pre) pre -> next = B;
        B -> next = A ;
        A -> next = next;


        pre = A;  // cautious
        A = next;
    }

    return result;
}

int main()
{
    Node* root = new Node(0);
    Node* temp = root;
    ff(i,1,10,1)
    {
        add(temp,i);
        temp = temp -> next;
    }
    print(swapPair(root));
}
