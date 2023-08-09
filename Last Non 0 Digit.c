#include<stdio.h>

int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

int lastNon0Digit1(int n){
    // Using fomular : D(n) = k * D(floor(n/5)) * D(n  % 10 )
    // K = 4 if(n / 10 % 10 odd )
    // K = 6 ................even
    if(n < 10) return dig[n];

    if((n/10)%10 & 1) return (4 * lastNon0Digit1(n / 5) * dig[n % 10]) % 10 ;
    else return (6 * lastNon0Digit1(n / 5) * dig[n % 10])  %10 ;
}

//********************************************************************************

int lastNon0Digit2(int n){
    if(n == 1) return 1;

    int res = 1;
    int sumOf5 = 0 ;

    for(int i = n;i >= 2;i --)
    {
        int num = i;
        while(num  % 5 == 0){
            num /= 5;
            sumOf5 ++;
        }
        while (num % 2 == 0 && sumOf5 > 0){
            num /= 2;
            sumOf5 --;
        }

        res = (res *(num  % 10) ) % 10;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",lastNon0Digit2(n));
}
