#include<stdio.h>

#define SIZE 5

int qu[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    return (front == rear + 1 || (front == 0 && rear == SIZE -1));
}

int isEmpty()
{
    return (front == -1);
}

void push(int x)
{
    if(isFull()) return ;
    if(front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    qu[rear] = x;
}

void pop()
{
    if(isEmpty()) return ;
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else front = (front + 1) % SIZE;
}

int main()
{
    for(int i = 1;i <= 5;i ++)push(i);
    while(!isEmpty())
    {
        printf("%d ",qu[front]);
        pop();
    }
}

