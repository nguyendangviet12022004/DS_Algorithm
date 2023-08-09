#include<stdio.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define f(i,n) for(int i = 0 ;i < n;i ++)

void windowSliding(int *a, int size, int k)
{
    int res = 0;
    int l = 0;
    int r = 0;
    int curr = 0;
    int j = 0;

    f(i,size){
        curr += a[i];
        while(curr > k) curr -= a[j++];
        if(i - j + 1 > res)
        {
            res = i - j + 1;
            l = j;
            r = i;
        }
    }
    ff(i,l,r,1) printf("%d ",a[i]);
}
int main()
{
    int a[] = {1,1,4,9,3,6,6,8};
    int k = 10;
    windowSliding(a,8,10);
}
