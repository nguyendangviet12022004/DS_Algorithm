#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ff(i,a,b,s) for(int i = a;i <= b;i += s)


void takeArr(int **a){
    FILE* fptr;
    fptr = fopen("INPUT.txt","r");
    char c;
    ff(i,0,8,1){
        ff(j,0,8,1){
            do {
                fscanf(fptr,"%c",&c);

            }while (c == ' ' || c == '\n');
            if(c == '.') a[i][j] = 0;
            else a[i][j] = (int)(c - '0');

        }


    }
    fclose(fptr);
}

void printArr(int **a){
    ff(i,0,8,1){
        ff(j,0,8,1){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}


bool checkBlock3(int**a, int x1,int y1){
    bool check[10] = {false};
    ff(i,x1,x1+2,1)
    {
        ff(j,y1,y1+2,1)
        {

            if(a[i][j] == 0) continue;
            if(!check[a[i][j]]) check[a[i][j]] = true;
            else {

                return false;
            }
        }
    }
    return true;
}

bool checkRow(int **a,int i){
    bool check[10] = {false};
    ff(i,0,8,1)check[i] = false;
    ff(j,0,8,1)
    {
        if(a[i][j] == 0) continue;
        if(!check[a[i][j]]) check[a[i][j]] = true;
        else {
            return false;
        }
    }
    return true;
}

bool checkCol(int**a,int j)
{
    bool check[10] = {false};
    ff(i,0,8,1)
    {
        if(a[i][j] == 0) continue;
        if(!check[a[i][j]]) check[a[i][j]] = true;
        else return false;
    }
    return true;
}

bool checkTotal(int **a){
    ff(i,0,8,1) {
        if(!checkRow(a,i) ) {
            return false;
        }
    }
    ff(j,0,1,1){
        if(!checkCol(a,j)) {
            return false;
        }
    }

    ff(i,0,8,3)
    {
        ff(j,0,8,3)
        {
            if(!checkBlock3(a,i,j)) {
                printf("%d %d ",i,j);
                return false;
            }
        }
    }

    return true;
}
int main(){
    int ** a= (int**)malloc(9 * sizeof(int*));
    ff(i,0,8,1) a[i] = (int*)malloc(9 * sizeof(int));

    takeArr(a);
    if(checkTotal(a)){
        printf("TRUE");
    }
    else printf("FALSE");
}
