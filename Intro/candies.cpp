#include <iostream>
using namespace std;

void merge(long long arr[], long long l, long long m, long long r)
{
    long long i, j, k;
    long long n1 = m - l + 1;
    long long n2 =  r - m;
 
    /* create temp arrays */
    long long L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back long longo arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long long arr[], long long l, long long r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long long m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
	int t;
	cin >> t;
	long long n, o, d, x1, x2, a, b, c, m, l;
	for (int i=1;i<=t; i++){
		cin >> n >> o >> d;
		long long x[n], s[n], odd=0;
		cin >> x[1] >> x[2] >> a >> b >> c >> m >> l;
		for (long long j=3; j<=n; j++){
			x[j] = (a*x[j-1] + b*x[j-2] +c)%m;
		}
		for (long long j=1; j<=n; j++){
			s[j] = x[j] + l;
			// if (s[j]%2!=0)
			// 	odd++;
		}
		// if (odd > o)
		// 	cout << "Case #"<<i<<": "<<"IMPOSSIBLE"<<endl;
			long long y=0;
			mergeSort(s, 1, n);
			for (long long j=n; j>=1; j--){
				if (s[j]%2==0)
					y += s[j];
				else{
					odd++;
					if (odd<=o){
						y += s[j];
					}
				}
				if (y > d){
					y -= s[j+1];
					break;
				}
			}
			if (y > d)
				cout << "Case #"<<i<<": IMPOSSIBLE"<<endl;
			else
				cout << "Case #"<<i<<": "<<y<<endl;
	}
}