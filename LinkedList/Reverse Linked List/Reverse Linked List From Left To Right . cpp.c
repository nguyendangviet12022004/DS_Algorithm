#include<iostream>
#include<sstream>
#define ff(i,a,b,s) for(int i = a ; i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a ; i >= b;i -=s)
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int val) : val(val) , next(nullptr){}
};
void add(Node* root, int val)
{
    root -> next = new Node(val);
}
void get(Node* root)
{
    string s;
    getline(cin,s);
    stringstream input(s);
    int x;
    input >> x;
    root -> val = x;
    Node* temp = root;

    while(input >> x)
    {
        add(temp,x);
        temp = temp -> next;
    }
}


void print(Node* root)
{
    Node* temp = root;
    while(temp -> next)
    {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << temp ->val;
}

// pre1 -> A   .....  B -> next2
// pre1 -> B -> ..............-> A -> next2;
Node* swapNode(Node* root, int left, int right)
{
    if(left == right) return root;

    Node* pre1 = nullptr;
    Node* A = nullptr;
    Node* B = nullptr;
    Node* temp = root;

    bool isHead = (left == 1);

    if(isHead) {
        A = root;
    }
    else
    {
        ff(i,1,left -2,1)
            temp = temp -> next;
        pre1 = temp;
        A = temp -> next; // reach left point

    }

    if(isHead) right --; // special case if left = 1

    ff(i,1,right - left + 1 , 1)
        temp = temp -> next; // reach right point
    B = temp ;
    Node* next2 = B -> next;


    Node* pre = A;
    temp = A -> next;


    while(temp != next2) // reverse
    {
        Node* mark = temp -> next;
        temp -> next = pre;
        pre = temp;
        temp = mark;
    }


    if(!isHead) pre1 -> next = B; // special case
    else root = B;

    A -> next = next2;

    return root;
}


int main()
{
    Node* root = new Node(0);
    get(root);
    int left, right;
    cin >> left >> right;
    print(swapNode(root,left,right));



}

