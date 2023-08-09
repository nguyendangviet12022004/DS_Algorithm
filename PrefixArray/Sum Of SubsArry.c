
// give a array ,  queries {i,j} = a[i] + s[i+1] +..+s[j]


#include<stdio.h>
#include<stdlib.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)

void solve(int *a, int n,int **q,int m)
{
    // Create Prefix Array-------------------------------
    int* prefix = (int*)malloc(n * sizeof(int));
    prefix[0] = a[0];
    ff(i,1,n-1,1)  prefix[i] = prefix[i-1] + a[i];
    //---------------------------------------------------

    ff(i,0,m-1,1)
    {
        int l = q[i][0];
        int r = q[i][1];
        printf("%d %d: %d\n",l,r,prefix[r]-prefix[l]+a[l]);
    }
    free(a);
    free(q);
    free(prefix);
}
int main()
{
    //Take input from user *********************************
    int n;
    int m;
    scanf("%d%d",&n,&m);
    int *a = (int*)malloc(n * sizeof(int));
    int **q = (int**)malloc(m * sizeof(int*));
    ff(i,0,m-1,1) q[i] = (int*)malloc(2*sizeof(int));

    ff(i,0,n-1,1) scanf("%d",&a[i]);
    ff(i,0,m-1,1) scanf("%d%d",&q[i][0],&q[i][1]);
    //******************************************************


    solve(a,n,q,m);


}
