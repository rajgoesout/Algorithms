#include<stdio.h>
#define COMPARE(x, y) ((x<y)?-1:((x==y)?0:1))

int binSearch(int list[], int searchnum, int left, int right){
    int middle;
    while (left <= right){
        middle = (left+right)/2;
        switch(COMPARE(list[middle], searchnum)){
            case -1:left = middle + 1;
                    break;
            case 0:return middle;
            case 1:right=middle-1;
        }
    }
    return -1;
}
int main(){
    int list[]={-19, -7, 0, 23, 37, 105, 111, 234, 485, 1001};
    int val = binSearch(list, 111, 0, 9);
    printf("%d\n", val);
}
