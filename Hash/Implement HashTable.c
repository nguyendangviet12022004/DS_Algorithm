#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ff(i,a,b,s) for(int i = a;i <= b;i +=s)
#define fl(i,a,b,s) for(int i = a;i >= b;i -=s)

typedef struct Hash{
    int key;
    int data;
}hash;

int MAX = 10000;
int size = 0;

int hash_func(int a)
{
    return a % MAX;
}

int isPrime(int n)
{
    if(n < 2) return 0;
    ff(i,2,sqrt(n),1) if(n % i == 0) return 0;
    return 1;
}

int getPrime(int n)
{
    if(n%2 == 0) n ++;
    while(!isPrime(n)) n += 2;
    return n;
}

hash* createHash()
{
    MAX = getPrime(MAX);
    hash* ans = (hash*)malloc(MAX * sizeof(hash));
    ff(i,0,MAX-1,1)
    {
        ans[i].key = 0;
        ans[i].data = 0;
    }
    return ans;
}

void add(hash* a, int key, int data)
{
    int id = hash_func(key);
    if(a[id].data == 0)
    {
        a[id].key = key;
        a[id].data = data;
        size++;
    }
    else if(a[id].key == key)
    {
        a[id].data = data;
    }
    else {
        printf("Conflict Happening!\n");
    }
}

void del(hash* a, int key, int data)
{
    int id = hash_func(key);
    if(a[id].data = 0)
    {
        printf("NaN\n");
    }
    else {
        a[id].key = 0;
        a[id].data = 0;
        size --;
        printf("Deleted\n");
    }
}

void printHash(hash* a)
{
    ff(i,0,MAX-1,1)
    {
        if(a[i].data == 0)
        {
            continue;
        }
        else {
            printf("key: %d\nValue: %d\n",a[i].key,a[i].data);
        }
    }
}
int main()
{
    hash* a = createHash();
    add(a,100,25);
    printHash(a);

}
