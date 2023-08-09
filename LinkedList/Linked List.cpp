#include<iostream>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
using namespace std;

struct Node
{
    int val;
    Node* next ;
    Node(int val) : val(val), next(nullptr){}
};

void print(Node* root)
{
    Node*temp = root;
    while(temp){
        cout << temp -> val <<" ";
        temp = temp -> next;
    }
    cout <<endl;
}




// ------------------------------------------------------ADD VALUE ----------------------------------------------------------
void addNode(Node* root , int n)
{
    Node* add = new Node(n);

    add -> next = root -> next;
    root -> next = add;
}

void pushBack(Node* root, int n)
{
    Node* temp = root;
    while(temp -> next != nullptr) temp = temp -> next;
    addNode(temp,n);
}

void pushFront(Node* root,int n)
{
    int temp = root -> val;
    root -> val = n;
    addNode(root, temp);
}

void insert(Node* root, int id,int n)
{

    if(id == 0) {
        pushFront(root,n);
        return;
    }
    Node* temp = root ;
    ff(i,1,id-1,1) temp = temp -> next;
    addNode(temp,n);
}
// ------------------------------------------------------ADD VALUE ----------------------------------------------------------







//-------------------------------------------DELETE VALUE --------------------------------------------------------------------

void pop_back(Node* root)
{
    Node* temp = root;
    while(temp -> next -> next!= nullptr) temp = temp -> next;
    delete(temp -> next);
    temp -> next = nullptr;
}

void pop_front(Node* root)
{
    root -> val = root -> next -> val;
    Node* temp = root -> next;
    root -> next = temp -> next;
    delete(temp);
}

void pop(Node* root, int id)
{
    if(id == 0) {
        pop_front(root);
        return ;
    }
    Node* temp = root;
    ff(i,1,id-1,1) temp = temp -> next;

    Node* del = temp -> next;
    temp -> next = del -> next;
    delete(del);
}
//-------------------------------------------DELETE VALUE --------------------------------------------------------------------






int main()
{
    Node* root = new Node(0);
    //Node* head = root;
    for(int i = 1;i <= 10;i++) pushBack(root,i);

    print(root);
}
