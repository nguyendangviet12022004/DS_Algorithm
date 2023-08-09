#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
} node;

typedef struct Queue
{
    node* front;
    node* back;
} queue;


node* newNode(int val)
{
    node* res = (node*)malloc(sizeof(node));
    res -> val = val;
    res -> next = NULL;
    return res;
}

queue* newQueue()
{
    queue* qu = (queue*)malloc(sizeof(queue));
    qu -> front = NULL;
    qu -> back = NULL;
    return qu;
}

int isEmpty(queue* qu)
{
    return !qu -> front;
}
void push(queue* qu, int x)
{
    node* add = newNode(x);
    if(isEmpty(qu))
    {
        qu -> front = add;
        qu -> back = add;
    }
    else
    {
        qu -> back -> next = add;
        qu -> back = add;
    }
}

void pop(queue* qu)
{
    if(isEmpty(qu)) return;
    node* del = qu -> front;
    qu -> front = del -> next;
    free(del);
    if(!qu -> front) qu -> back = NULL;
}
int main()
{
    queue* qu = newQueue();

}
