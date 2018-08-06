#include<stdio.h>
int main()
{
    int x=1, y=22, z=2;
    if(x>y){
        if(y>z)
            printf("%d\t%d\t%d", z, y, x);
        else if(x>z)
            printf("%d\t%d\t%d", y, z, x);
        else
            printf("%d\t%d\t%d", y, x, z);
    } else {
        if(x>z)
            printf("%d\t%d\t%d", z, x, y);
        else if(y>z)
            printf("%d\t%d\t%d", x, z, y);
        else
            printf("%d\t%d\t%d", x, y, z);
    }
}
