#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)
int* newArr(int n)
{
    int* res = (int*)malloc(n * sizeof(int));
    ff(i,0,n-1,1) res[i] = 0;
    return res;
}

void copy(int*res,int*a,int n)
{
    ff(i,0,n-1,1) res[i] = a[i];
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

int max(int*a,int n)
{
    int res = -1;
    ff(i,0,n-1,1) res = (res < a[i]) ? a[i] : res;
    return res;
}









//-------------------------------------------------------------------------------------------

void countSort(int*a,int n,int unit)
{
    int* count = newArr(10);
    int* res = newArr(n);

    ff(i,0,n-1,1) count[(a[i]/unit)% 10] ++;

    ff(i,1,9,1) count[i] += count[i-1] ; // note : this line of code to mark order

    fl(i,n-1,0,1)
    {
        int x = (a[i]/unit) % 10;
        res[count[x]-1] = a[i]; // renember have to minus 1
        count[x]--;
    }
    copy(a,res,n);
}

void radixSort(int*a,int n)
{
    int maxEle = max(a,n);

    int unit = 1;
    while(maxEle / unit > 0)
    {
        countSort(a,n,unit);
        unit *= 10;
    }
}
//----------------------------------------------------------------------------------------
















int main()
{
    int n ;
    scanf("%d",&n);
    int* a = newArr(n);
    in(a,n);
    radixSort(a,n);
    out(a,n);
}
