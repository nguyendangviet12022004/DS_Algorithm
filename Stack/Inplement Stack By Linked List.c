#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// Using linked List
typedef struct Node
{
    int val;
    struct Node* next;
} node;

node* newNode(int val)
{
    node* res = (node*)malloc(sizeof(node));
    res -> val = val;
    res -> next = NULL;
    return res;
}

bool isEmpty(node* root)
{
    return (!root);
}

void push(node** root, int val)
{
    node* add = newNode(val);
    add -> next = *root;
    *root = add;
}

void pop(node** root)
{
    if(isEmpty(*root)) return;
    node* newRoot = (*root) -> next;
    node* del = (*root);
    free(del);
    *root = newRoot;
}

int top(node* root)
{
    if(!root) return INT_MIN;
    return root -> val;
}

int main()
{

}
