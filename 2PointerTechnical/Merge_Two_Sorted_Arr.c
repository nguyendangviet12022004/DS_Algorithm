#include<stdio.h>
#include<stdlib.h>

void merge(int*a, int*b, int size1, int size2)
{
    int i = 0,  j = 0 ,  id = 0;
    int *res = (int*)malloc((size1+size2)*sizeof(int));

    while(i < size1 && j < size2)
        if(a[i] < b[j])  res[id++] = a[i++];
        else  res[id++] = b[j++];

    while(i < size1) res[id++] = a[i++];
    while(j < size2) res[id++] = b[j++];

    for(int i =0 ;i < id;i ++) printf("%d ",res[i]);
}

int main()
{
    int a[5] = {1,3,5,8,11};
    int b[5] = {0,2,5,9,12};
    merge(a,b,5,5);
}
