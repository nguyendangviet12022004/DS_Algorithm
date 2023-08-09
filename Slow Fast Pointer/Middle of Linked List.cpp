#include<iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int val): val(val), next(nullptr){};
};

Node* add(Node* root, int x)
{
    Node* add = new Node(x);
    root -> next = add;
    return root;
}

Node* middleNode(Node* root)
{
    Node* fast = root;
    Node* slow = root;
    while(fast && fast -> next)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}


int main()
{
    Node* root = new Node(1);
    Node* temp = root;
    for(int i = 2;i <= 5;i ++)
    {
        temp = add(temp,i);
        temp = temp -> next;
    }


    cout << middleNode(root) -> val;
}
