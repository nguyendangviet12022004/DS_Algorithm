#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)

int* newArr(int );

void in(int*,int);

void out(int*,int);

void swap(int*,int*);

void ShellSort(int*,int);

int main()
{
    int n;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    ShellSort(a,n);
    out(a,n);
}


int* newArr(int n)
{
    return (int*)malloc(n * sizeof(int));
}

void in(int*a,int n)
{
    ff(i,0,n-1,1) scanf("%d",a+i);
}

void out(int*a,int n)
{
    ff(i,0,n-1,1) printf("%d ",a[i]);
    printf("\n");
}

void swap(int* a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


//----------------------Sort---------------------------------------------------
void ShellSort(int*a,int n)
{
    for(int d = n / 2; d >= 1; d /= 2)
        ff(i,d,n-1,1)
        {
            int temp = a[i];
            int j = i;
            while(j >= d && a[j-d] > temp) {
                a[j] = a[j-d];
                j -= d;
            }
            a[j] = temp;
        }
}
//--------------------------------------------------------------------------------
