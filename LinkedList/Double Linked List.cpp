#include<iostream>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
using namespace std;

struct Node
{
    int val;
    Node* pre;
    Node* next;
    Node(int val): val(val), pre(nullptr), next(nullptr){}
};
struct List
{
    Node* head;
    Node* tail;
};

List* newList(int n)
{
    Node* temp = new Node(n);
    List* res = new List ;
    res -> head = temp;
    res -> tail = temp;
    return res;
}

void print(List* l)
{
    for(Node* i = l -> head; i ; i = i -> next)
        cout << i -> val <<" ";

    cout << endl;
}


//---ADD VAL---------------------------------------------------------
List* pushBack(List* l , int x)
{
    Node* add = new Node(x);
    Node* endList = l -> tail;
    endList -> next = add;
    add -> pre = endList;
    l -> tail = add;
    return l;
}

List* pushFront(List* l ,int x)
{
    Node* add = new Node(x);
    Node* beginList = l -> head;
    beginList -> pre = add;
    add -> next = beginList;
    l -> head = add;
    return l;
}

List* insert(List* l , int id , int x)
{
    if(id == 0) return pushFront(l,x);

    Node* add = new Node(x);
    Node* temp = l -> head;
    ff(i,1,id-1,1)
        temp = temp -> next;

    if(!temp -> next) return pushBack(l,x);
    Node* temp2 = temp -> next;

    temp -> next = add;
    add -> pre = temp ;
    add -> next = temp2;
    temp2 -> pre = add;
    return l;
}
//---ADD VAL---------------------------------------------------------






//---DEL VAL---------------------------------------------------------

List *popFront(List* l)
{
    Node* oldHead = l -> head;
    l -> head = oldHead -> next;
    l -> head -> pre = nullptr;

    delete(oldHead);
    return l;
}

List *popBack(List* l)
{
    Node* oldTail = l -> tail;
    l -> tail = oldTail -> pre;
    l -> tail -> next = nullptr;

    delete(oldTail);
    return l;
}
List *pop(List* l, int id)
{
    if(id == 0) return popFront(l);

    Node* temp = l -> head;
    ff(i,1,id,1) temp = temp -> next;
    if(!temp -> next) return popBack(l);

    Node* before = temp -> pre;
    Node* after = temp -> next;

    after -> pre = before;
    before -> next = after;
    delete(temp);
    return l;
}
//---DEL VAL---------------------------------------------------------










int main()
{
    List* l = newList(0);
    ff(i,1,10,1) l = pushBack(l,i);
    l = pop(l,5);
    print(l);
}
