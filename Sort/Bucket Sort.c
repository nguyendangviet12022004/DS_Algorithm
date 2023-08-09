#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define INTERVAL 10
typedef struct Node
{
    int val;
    struct Node* next;
}node;

node* newNode(int );

int* newArr(int );

void in(int* , int );

void out(int*,int );

int max(int*,int);

node** createBucket(int*,int,int);

void printList(node*);

node* sortEachBucket(node*);

void bucketSort(int*,int);


int main()
{
    int n;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    bucketSort(a,n);
    out(a,n);
}


node*newNode(int n)
{
    node* res = (node*)malloc(sizeof(node));
    res -> val = n;
    res -> next = NULL;
    return res;
}

int* newArr(int n)
{
    int* res = (int*)malloc(n * sizeof(int));
    ff(i,0,n-1,1) res[i] = 0;
    return res;
}

void in(int* a,int n)
{
    ff(i,0,n-1,1) scanf("%d",&a[i]);
}

void out(int*a,int n)
{
    ff(i,0,n-1,1) printf("%d ",a[i]);
    if(n) printf("\n");
}

void printList(node*root)
{
    node* temp = root;
    while(temp)
    {
        printf("%d ",temp -> val);
        temp = temp -> next;
    }
    printf("\n");
}

int max(int*a,int n)
{
    int res = -1;
    ff(i,0,n-1,1) res = (res < a[i]) ? a[i] : res;
    return res;
}























//--------------------------------------SORT-------------------------------------------------------------------------------------------

node** createBucket(int* a,int n, int l)
{

    node** res = (node**)malloc(l * sizeof(node*));
    ff(i, 0, l -1 , 1) res[i]= NULL;
    ff(i, 0, n -1 , 1)
    {
        int pos = a[i] / INTERVAL;
        node* curr = newNode(a[i]);
        curr -> next = res[pos];
        res[pos] = curr;

    }

    return res;
}

node* sortEachBucket(node* root)
{
    if(!root || !root -> next) return root;
    for(node* i = root ; i -> next!= NULL; i = i -> next)
    {
        for(node* j = i -> next;j != NULL; j = j -> next)
        {
            if(j -> val < i -> val)
            {

                int t = i -> val;
                i -> val = j -> val;
                j -> val = t;
            }
        }
    }
    return root;
}


void bucketSort(int*a,int n)
{
    int l = max(a,n)/INTERVAL + 1;
    node** list = createBucket(a,n,l);
    for(int i = 0;i < l;i ++) list[i] = sortEachBucket(list[i]);
    int id = 0;
    for(int i = 0 ;i < l ; i ++)
    {
        node* temp = list[i];
        while(temp)
        {
            a[id++]  = temp -> val;
            temp = temp -> next;
        }
    }
}


