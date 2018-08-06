#include<stdio.h>
int ackerman(int m, int n)
{
    if(m==0)
        return (n+1);
    else if(n==0)
        ackerman(m-1, 1);
    else
        ackerman(m-1, ackerman(m, n-1));
}
int main()
{
    int x = ackerman(2, 0);
    printf("%d", x);
}
