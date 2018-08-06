#include<stdio.h>
int fRec(int i);
void f(int i);
int fibo(int n);
int fiboRec(int n);

int fRec(int i)
{
    if(i==0)
        return 0;
    else if(i==1)
        return 1;
    else
        return (fRec(i-1)+fRec(i-2));
}
void f(int i)
{
    int next, first=0, second=1, j;
    for(j=0; j<i; j++){
        if(j<=1)
            next=j;
        else{
            next=first+second;
            first=second;
            second=next;
        }
        printf("%d\n", next);
    }
}


int fibo(int n){
    int first = 0, second = 1, next = 2;
    if 
    // int f[1000];
    // f[0] = 0;
    // f[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     f[i] = f[i-1] + f[i-2];
    // }
    // return f[n];
}

int fiboRec(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fiboRec(n-1) + fiboRec(n-2));
}

int main()
{
    // f(20);
    // int j;
    // for(j=0; j<20; j++){
    //     printf("%d\n", fRec(j));
    // }
    printf("%d\n", fiboRec(6));

    return 0;
}





























