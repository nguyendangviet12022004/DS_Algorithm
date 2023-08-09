#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubleSort(int*a , int n)
{
    for(int i = 0 ;i < n -1; i++)
        for(int j = i + 1;j < n ;j ++)
            if(a[j] < a[i]) swap(&a[i],&a[j]);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0 ;i < n ;i ++) scanf("%d",&a[i]);

    bubleSort(a,n);
    for(int i = 0 ;i < n ;i ++) printf("%d ",a[i]);
}
