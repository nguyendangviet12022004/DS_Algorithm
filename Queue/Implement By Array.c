#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    unsigned front, back , size , capacity;
    int * arr;
} queue;

queue newQueue(unsigned int capacity)
{
    queue qu;
    qu.capacity = capacity;
    qu.front = -1;
    qu.back = -1;
    qu.arr = (int*)malloc(capacity * sizeof(int));
    return qu;
}

int isFull(queue qu)
{
    return qu.back == qu.capacity - 1;
}

int isEmpty(queue qu)
{
    return qu.front == -1 || qu.back == -1;
}

void push(queue* qu, int x)
{
    if(isFull(*qu)) return;
    else {
        if((*qu).front == -1) front = 0;
        (*qu).back ++;
        (*qu).arr[back] = x;
    }
}

void pop(queue* qu)
{
    if((*qu).front == -1) return ;
    else
    {
        (*qu).front ++;
        if((*qu).front > (*qu).back)
            (*qu).front = (*qu).back = -1;
    }
}

int main()
{

}
