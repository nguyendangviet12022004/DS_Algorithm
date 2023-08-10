#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
int* eratosthenes(int,int*l);
int binSearch(int*,int,int,int);
int countSuperPrime(int*,int,int);
int main()
{
    int n;
    scanf("%d",&n);
    int l = 0;
    int *a = eratosthenes(n,&l);
    printf("%d",countSuperPrime(a,l,n));

}


bool *newArr(int n)
{
    bool* res = (bool*)malloc(n * sizeof(bool));
    ff(i,0,n-1,1) res[i] = false;
    return res;
}

int* eratosthenes(int n,int*l)
{
    bool* b = (bool*)malloc((n+1) * sizeof(bool));
    b[0] = b[1] = false;
    ff(i,2,n-1,1) b[i] = true;
    ff(i,2,sqrt(n),1)
        if(b[i])
            ff(j,i*i,n,i)
                b[j] = false;

    int len = 0;
    ff(i,0,n,1) if(b[i]) len ++;
    int* res = (int*)malloc(len*sizeof(int));
    int j = 0;
    ff(i,0,n,1)if(b[i]) res[j++] = i;
    *l = len;
    return res;
}

int binSearch(int*a,int l, int r, int x)
{
    int ans = -1;
    while(l <= r)
    {
        int m = l + (r-l)/2;
        if(a[m] <= x)
        {
            ans = m;
            l = m + 1;
        }
        else r = m -1;
    }
    return ans;
}

int countSuperPrime(int*a,int l, int n)
{
    int res = 0;
    ff(i,0,l-1,1)
    {
        if(2*a[i] > n) break;
        int r = binSearch(a,i+1,l-1,n-a[i]);
        if(r != -1) res += r - i ;
    }
    return res;
}


