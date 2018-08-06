#include <stdio.h>

void towers(int, char, char, char);

int main(){
	int n;
	scanf("%d", &n);

	// Move n disks from 'A' to 'C' using 'B' as auxiliary.
	towers(n, 'A', 'C', 'B');
	return 0;
}

void towers(int n, char frompeg, char topeg, char auxpeg){

	// If only one disk, make the move and return.
	if (n == 1){
		printf("%s%c%s%c\n", "move disk 1 from peg ", frompeg, " to peg ", topeg);
		return;
	}

	// Move top n-1 disks from A to B, using C as auxiliary.
	towers(n-1, frompeg, auxpeg, topeg);

	// Move remaining disks from A to C.
	printf("%s%d%s%c%s%c\n", "move disk ", n, " from peg ", frompeg, " to peg ", topeg);

	// Move n-1 disks from B to C, using A as auxiliary.
	towers(n-1, auxpeg, topeg, frompeg);
}

void toh(int n, char frompeg, char topeg, char auxpeg){
	if (n==1){
		printf("move disk 1 from peg %c to peg %c\n", frompeg, topeg);
		return;
	}
	towers(n-1, frompeg, auxpeg, topeg);
	printf("move disk %d from peg %c to peg %c\n", n, frompeg, topeg);
	towers(n-1, auxpeg, topeg, frompeg);
}
































