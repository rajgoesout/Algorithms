#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLENGTH 20

void substr(char s1[], int i, int j, char s2[]){
	int k, m;
	for (k=i, m=0; m<j; s2[m++]=s1[k++])
		;
	s2[m] = '\0';
}

int find(char str[]){
	char temp[MAXLENGTH];
	int length;
	int i, j, m, n;

	if ((length = strlen(str)) ==  0)
		return 0;
	if (isalpha(str[0]) != 0)
		return 1;
	if (strlen(str) < 2)
		return 0;
	substr(str, 1, length-1, temp);
	m = find(temp);
	if (m == 0 || strlen(str) == m)
		return 0;
	substr(str, m+1, length-m-1, temp);
	n = find(temp);
	if (n == 0)
		return 0;
	return m+n+1;
}

void convert(char prefix[], char postfix[]){
	char opnd1[MAXLENGTH], opnd2[MAXLENGTH];
	char post1[MAXLENGTH], post2[MAXLENGTH];
	char temp[MAXLENGTH];
	char op[2];
	int length;
	int i, j, m, n;

	if ((length = strlen(prefix)) == 1){
		if (isalpha(prefix[0])){
			postfix[0] = prefix[0];
			postfix[1] = '\0';
			return;
		}
		printf("Illegal prefix string\n");
		exit(1);
	}
	op[0] = prefix[0];
	op[1] = '\0';
	substr(prefix, 1, length-1, temp);
	m = find(temp);
	substr(prefix, m+1, length-m-1, temp);
	n = find(temp);
	if ((op[0]!='+' && op[0]!='-' && op[0]!='*' && op[0]!='/')|| (m==0)||(n==0)||(m+n+1 != length)){
		printf("illegal prefix string\n");
		exit(1);
	}
	substr(prefix, 1, m, opnd1);
	substr(prefix, m+1, n, opnd2);
	convert(opnd1, post1);
	convert(opnd2, post2);
	strcat(post1, post2);
	strcat(post1, op);
	substr(post1, 0, length, postfix);
}

int main(){
	// printf("hello, world!\n");
	char s1[20], s2[20];
	printf("Enter prefix expression: ");
	scanf("%s", s1);
	convert(s1, s2);
	printf("%s\n", s2);
	return 0;
}
