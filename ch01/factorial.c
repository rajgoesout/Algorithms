#include<stdio.h>
int factRec(int);
int fact(int);
int main()
{
    int factorial = factRec(5);//fact(5)
    printf("%d", factorial);
}
int factRec(int n)
{
    if(n<=1)
        return 1;
    else
        return n*factRec(n-1);
}
int fact(int n)
{
    if(n<=1)
        return 1;
    else {
        int i, f=1;
        for(i=1; i<=n; i++)
            f=f*i;
        return f;
    }
}
