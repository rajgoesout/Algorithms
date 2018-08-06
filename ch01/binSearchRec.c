#include<stdio.h>
#define COMPARE(x, y) (((x)<(y))?-1:(((x)==(y))?0:1))

int binSearchRec(int list[], int searchnum, int left, int right){
    int middle;
    if (left <= right){
        middle = (left+right)/2;
        switch(COMPARE(list[middle], searchnum)){
            case -1:return binSearchRec(list, searchnum, middle+1, right);
            case 0:return middle;
            case 1:return binSearchRec(list, searchnum, left, middle-1);
        }
    }
    return -1;
}
int main(){
    int list[]={-19, -7, 0, 23, 37, 105, 111, 234, 485, 1001};
    int val = binSearchRec(list, 1001, 0, 9);
    printf("%d\n", val);
}

