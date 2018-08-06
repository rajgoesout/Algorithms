// #include <stdio.h>
// #define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

// void perm(char *list, int i, int n){
//     int j, temp;
//     if(i==n){
//         for(j=0; j<=n; j++)
//             printf("%c", list[j]);
//         printf("    ");
//     }else{
//         for(j=i; j<=n; j++){
//             SWAP(list[i], list[j], temp);
//             perm(list, i+1, n);
//             SWAP(list[i], list[j], temp);
//         }
//     }
// }
// int main(){
//     char list[]={'a', 'b', 'c'};
//     perm(list, 0, 2);
// }

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y){
    char *temp;
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

void permute(char *a, int l, int r){
    int i, t;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(a+l, a+i);
            permute(a, l+1, r);
            swap(a+l, a+i);
        }
    }
}

int main(){
    char list[] = "abc";
    permute(list, 0, 2);
}