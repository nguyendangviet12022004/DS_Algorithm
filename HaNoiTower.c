#include<stdio.h>


void HaNoiTower(int n, char a , char b , char c)
{
    if(n)
    {
        HaNoiTower(n-1,a,c,b);
        printf("Move Disk %d From %c to %c\n",n,a,c);
        HaNoiTower(n-1,b,a,c);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    HaNoiTower(3,'A','B','C');
}
