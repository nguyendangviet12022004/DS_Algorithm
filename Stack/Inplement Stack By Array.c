#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
typedef struct Stack
{
    int top;
    unsigned capacity;
    int* arr;
}stack;

stack newStack(int capacity){
    stack st ;
    st.capacity = capacity;
    st.top = -1;
    st. arr = (int*)malloc(capacity * sizeof(int));
    return st;
}

void push(stack* st, int val)
{
    (*st).arr[++(*st).top] = val;

}

void pop(stack* st)
{
    (*st).top --;
}

int isFull(stack st)
{
    return st.top == st.capacity -1;
}

int isEmpty(stack st)
{
    return st.top == -1;
}

int top(stack st)
{
    if(isEmpty(st)) return INT_MIN;
    return st.arr[st.top];
}



int main()
{
    stack st = newStack(100);
    for(int i = 0 ;i < 100;i ++) push(&st,i);
    while(!isEmpty(st))
    {
        printf("%d ",top(st));
        pop(&st);
    }
    return 0;
}

