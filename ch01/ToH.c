#include<stdio.h>
void toh(int n, char from, char to, char aux)
{
    if(n==1){
        printf("Move disc 1 from rod%c to rod%c\n", from, to);
        return;
    }
    toh(n-1, from, aux, to);
    printf("Move disc %d from rod%c to rod%c\n", n, from, to);
    toh(n-1, aux, to, from);
}
int main()
{
    toh(3, 'A', 'B', 'C');
}
