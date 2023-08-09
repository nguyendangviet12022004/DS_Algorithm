#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)



int* newArr(int);

void in(int*, int);

void out(int*,int);

void swap(int*, int*);

int partition(int*,int,int);

void quickSort(int*,int,int);


int main()
{
    int n;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    quickSort(a,0,n-1);
    out(a,n);
}




//-----------------------------IMPLEMENTATION-------------------------------------------
int* newArr(int n)
{
    return (int*)malloc(n * sizeof(int));
}

void in(int*a,int n)
{
    ff(i , 0 , n-1 , 1) scanf("%d",&a[i]);
}

void out(int* a, int n)
{
    ff(i , 0 , n-1 , 1) printf("%d ",a[i]);
    printf("\n");
}


void swap(int*a,int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}



//----------------------------------SORT-----------------------------------------------


int partition(int*a, int l, int r)
{
    int id = l;
    int p = a[r];
    ff(i, l , r-1 , 1)
    {
        if(a[i] < p)
        {
            swap(a+i,a+id);
            id ++;
        }
    }
    swap(a + id, a + r);
    return id;
}

void quickSort(int*a ,int l, int r)
{
    if(l < r)
    {
        int m = partition(a,l,r);
        quickSort(a,l,m-1);
        quickSort(a,m+1,r);
    }
}

//----------------------------------------------------------------------------------------
