#include <stdio.h>

double binCoeff(int n, int m);
int factRec(int x);
double binCoeffRec(int n, int m);

int main(){
	// double ans = binCoeff(3, 3);
	double ans = binCoeffRec(3, 3);
	printf("%lf\n", ans);
	return 0;
}

double binCoeff(int n, int m){
	int i;
	double nFact=1, mFact=1, nMinusmFact=1;
	int nMinusm=0;
	(n>m)?(nMinusm=(n-m)):(nMinusm=(m-n));
	if (n == m)
		return 1;
	else{
		if (n == 0)
			nFact=1;
		else{
			for(i=1; i<=n; i++){
				nFact*=i;
			}
		}
		if (m == 0)
			mFact=1;
		else{
			for(i=1; i<=m; i++){
				mFact*=i;
			}
		}
		for(i=1; i<=nMinusm; i++){
			nMinusmFact*=i;
		}
		return (nFact/(mFact*nMinusmFact));
	}
}

int factRec(int x){
	if (x == 0)
		return 1;
	return x*factRec(x-1);
}

double binCoeffRec(int n, int m){
	int nMinusm=0;
	(n>m)?(nMinusm=(n-m)):(nMinusm=(m-n));
	if (n == m)
		return 1;
	return factRec(n)/(factRec(m)*factRec(nMinusm));
}