// A binary string, change any 1 bit to have longest substring which is full of 1

#include<stdio.h>
#include<string.h>
#include<math.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)

void solve(char* s, int len)
{
    int curr = 0;
    int res = 0;
    int j = 0;
    ff(i,0,len-1,1)
    {
        if(s[i] == '0') curr ++;

        while(curr > 1)
            if(s[j++] == '0') curr --;

        res = fmax(res,i-j+1);
    }
    printf("%d",res);
}
int main()
{

    solve("10110110111101",14);

}
