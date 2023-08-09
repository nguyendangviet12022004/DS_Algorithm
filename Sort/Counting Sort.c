#include<stdio.h>
#include<stdlib.h>

#define ff(i,a,b,s) for(int i = a; i <= b; i += s)

int* newArr(int);

void in(int*,int);

void out(int*,int);

int max(int*,int);

void countingSort(int*,int);

int main()
{
    int n;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    countingSort(a,n);
    out(a,n);

}

//---------------------------------------IMPLEMENTATION---------------------------------------------------------------------------
int* newArr(int n)
{
    int* res = (int*)malloc(n * sizeof(int));
    ff(i,0,n-1,1) res[i] = 0;
    return res;
}

void in(int*a,int n)
{
    ff(i,0,n-1,1) scanf("%d",a + i);
}

void out(int*a,int n)
{
    ff(i,0,n-1,1) printf("%d ",a[i]);
}

int max(int*a,int n)
{
    int res = -1;
    ff(i,0,n-1,1) res = (res > a[i]) ? res : a[i];
    return res;
}
//--------------------------------------------------------------------------------------------------------------------------------------







//------------------------------------COUNTING SORT----------------------------------------------------------------------------------------
void countingSort(int*a,int n)
{
    int l = max(a,n);
    int* count = newArr(l+1);
    ff(i,0,n-1,1) count[a[i]] ++;
    int id = 0;
    ff(i, 0, l, 1)
        ff(j, 1, count[i], 1)
            a[id++] = i;
}
