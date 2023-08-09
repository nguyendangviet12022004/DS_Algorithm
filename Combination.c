#include<stdio.h>

int main()
{
    int k,n;
    scanf("%d%d",&k,&n);

    unsigned long long combinaton[k+1][n+1];

    for(int i = 0 ;i <= n; i++) combinaton[0][i] = 1;
    for(int i = 1; i <= k ;i++) combinaton[i][i] = 1;
    for(int i = 1; i <= k; i ++)
        for(int j = i+1; j <= n ;j ++) combinaton[i][j] = combinaton[i-1][j-1] + combinaton[i][j-1];

    printf("%llu",combinaton[k][n]);
// This Program Use Dynamic Programing
}

