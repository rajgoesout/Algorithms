#include <stdio.h>
int main()
{
    int t, sum=0;
    int n=1000;
    for(t=1; t<n; t++){
        if(n%t==0)
            sum+=t;
    }
    if(n==sum)
        printf("Yes, %d is equal to the sum of its divisors", n);
    else
        printf("No, %d is not equal to the sum of its divisors", n);
}
