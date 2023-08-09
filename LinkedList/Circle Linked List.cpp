#include<iostream>
#define ff(i,a,b,s) for(int i = a;i <=b ;i +=s)
#define fl(i,a,b,s) for(int i = a;i >=b ;i -=s)
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val) : val(val) , next(this){}
};

Node* add(Node* root,int val)
{
    Node* temp = root;
    Node* add = new Node(val);

    while(temp -> next != root){
        temp = temp -> next;
    }

    temp -> next = add;
    add -> next = root;
    return root;
}

void print(Node* root, int k)
{
    Node* temp = root;
    ff(i,1,k,1) temp = temp -> next;
    Node* mark = temp;
    while(temp  !=  root)
    {
        cout << temp -> val<<" ";
        temp = temp -> next;
    }
    while(temp != mark)
    {
        cout << temp -> val <<" ";
        temp = temp -> next;
    }

}

int main()
{
    int n,k,x;
    cin >> n >> x;
    Node* root = new Node(x);
    ff(i,2,n,1)
    {
        cin >> x;
        root = add(root,x);
    }
    cin >> k;
    print(root,k);
}

