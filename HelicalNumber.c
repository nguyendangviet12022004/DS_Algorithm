#include<stdio.h>
#include<stdlib.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i += s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -= s)

int main()
{
    int n;
    scanf("%d",&n);

    int** a= (int**)malloc(n * sizeof(int*));
    ff(i,0,n,1) a[i] = (int*)malloc(n * sizeof(int));

    int k = 1;
    int l = 0;
    int r = n -1 ;

    while(k <= n * n )
    {
        if(k <= n * n) ff(j,l,r,1) a[l][j] = k ++;

        if(k <= n * n) ff(i,l+1,r,1) a[i][r] = k++;

        if(k <= n * n) fl(j,r-1,l,1) a[r][j] = k ++;

        if(k <= n * n) fl(i,r-1,l+1,1) a[i][l] = k ++;

        l ++;
        r --;
    }

    ff(i,0,n-1,1)
    {
        ff(j,0,n-1,1) printf("%d ",a[i][j]);
        printf("\n");
    }

}
