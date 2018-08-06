#include <stdio.h>

int binSearch(int a[], int x, int low, int high){
	if (low > high)
		return -1;
	int mid = (low + high)/2;
	if (x == a[mid])
		return mid;
	else if (x < a[mid])
		return binSearch(a, x, low, mid-1);
	else
		return binSearch(a, x, mid+1, high);
}

int binSearchIter(int a[], int x, int low, int high){
	while (low <= high){
		int mid = (low + high)/2;

		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

int main(){
	int a[] = {1, 3, 7, 15, 21, 22, 36, 78, 95, 106};
	int x = 3;
	int l = 0;
	int h = sizeof(a)/sizeof(a[0]) - 1;
	int index = binSearchIter(a, x, l, h);
	if (index < 0)
		printf("%d is not present in this array\n", x);
	else
		printf("%d is present at index %d\n", x, index);
	return 0;
}