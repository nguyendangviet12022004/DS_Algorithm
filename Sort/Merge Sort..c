#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)

int* newArr(int );

void in(int*, int);

void out(int*, int);

void merge(int* , int ,int ,int  );

void sort(int* , int, int );

int main()
{
    int n;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    sort(a,0,n-1);
    out(a,n);
}

// ---------------------------------IMPLEMENTATION-------------------------------------------------------------------------------------------------------------

int* newArr(int n)
{
    return (int*)malloc(n * sizeof(int));
}

void in(int* a,int n)
{
    ff(i,0,n-1,1) scanf("%d",a+i);
}

void out(int* a,int n)
{
    ff(i,0,n-1,1) printf("%d ",a[i]);
    printf("\n");
}

void merge(int* a,int l,int m, int r)
{

    int n1 = m - l +1;
    int n2 = r - m ;

    int*a1 = newArr(n1);
    int*a2 = newArr(n2);

    ff(i,0,n1-1,1) a1[i] = a[l+i];
    ff(i,0,n2-1,1) a2[i] = a[m+1+i];

    int i1 = 0, i2 = 0, i = l;

    while(i1 < n1 && i2 < n2)
    {
         if(a1[i1] < a2[i2])
            a[i++] = a1[i1++];
        else
            a[i++] = a2[i2++];
    }


    while(i1 < n1)
        a[i++] = a1[i1++];
    while(i2 < n2)
        a[i++] = a2[i2++];


    free(a1);
    free(a2);

}

void sort(int*a ,int l , int r)
{
    if(l < r)
    {
        int m = (r + l)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
