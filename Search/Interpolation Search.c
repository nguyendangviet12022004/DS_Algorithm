#include<stdio.h>
#include<stdlib.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)

int interpolationSearch(int*a, int l, int r,int x)
{
    while(l <= r)
    {
        int m = l + (r-l)*(x - a[l])/(a[r]-a[l]);
        if(a[m] == x) return m;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}


int main()
{
    int *a = (int*)malloc(99 * sizeof(int));
    for(int i = 0 ;i < 99;i++) a[i] = i;
    printf("%d ",interpolationSearch(a,0,98,48));
}
