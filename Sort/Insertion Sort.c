#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)


void in(int* , int );

void out(int* ,int );

void sort(int* , int n);

int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int*) malloc(n * sizeof(int));
    in(a,n);
    sort(a,n);
    out(a,n);
}
void in(int*a, int n)
{
    ff(i,0,n-1,1) scanf("%d",a+i);
}

void out(int*a, int n)
{
    ff(i,0,n-1,1) printf("%d ",a[i]);
    printf("\n");
}

void sort(int*a ,int n)
{
    ff(i,1,n-1,1)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j --;
        }
        a[j+1] = key;
    }
}
