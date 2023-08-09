// A sorted Array, are there any 2 number have sum equal to target

#include<stdio.h>
#include<stdlib.h>

void checkForTarget(int* a, int size, int target)
{
    int l = 0;
    int r = size - 1;
    int result[2] = {-1,-1};

    while(l < r)
    {
        if(a[l] + a[r] == target) {
            result[0] = l;
            result[1] = r;
            break;
        }
        else if(a[l] + a[r] > target) r --;
        else l ++;
    }
    printf("%d %d",result[0],result[1]);
}

int main()
{
    int a[5] = {1,2,3,4,5};
    checkForTarget(a,5,5);
}
