#include <stdio.h>
#include <stdlib.h>

void generateSquare(int n){

	if (!(n % 2))
	{
		fprintf(stderr, "Error! n is even\n");
		exit(1);
	}

	int magicSquare[n][n];

	int i, j, num;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			magicSquare[i][j] = 0;
		}
	}
	i = n/2;
	j = n-1;

	for (num = 1; num <= n*n; )
	{
		if (i == -1 && j == n)
		{
			j = n-2;
			i = 0;
		}
		else
		{
			if (j == n)
			{
				j = 0;
			}
			if (i < 0)
			{
				i = n-1;
			}
		}
		if (magicSquare[i][j])
		{
			j -= 2;
			i++;
			continue;
		}
		else
		{
			magicSquare[i][j] = num++;
		}
		j++;
		i--;
	}
	
	printf("The Magic Square for n=%d:\nSum of "
       "each row or column %d:\n\n",  n, n*(n*n+1)/2);
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main(){
	int n = 7;
	generateSquare(n);
}