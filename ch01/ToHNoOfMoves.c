#include<stdio.h>

int toh(int n)
{
    int i, p=2;
    for(i=1; i<n; i++)
        p*=2;
    return (p-1);
}

int main()
{
    int moves=toh(3);
    printf("%d", moves);
}
