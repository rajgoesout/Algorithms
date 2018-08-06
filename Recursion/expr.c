#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXSTRINGSIZE 100

void readstr(char *, int *);
int expr(char *, int, int *);
int term(char *, int, int *);
int getsymb(char str[], int length, int *ppos);
int factor(char *, int, int *);

int main(){
	char str[MAXSTRINGSIZE];
	int length, pos;

	readstr(str, &length);
	// scanf("%s", str);
	// length = strlen(str);
	pos = 0;
	if (expr(str, length, &pos) == TRUE && pos >= length)
		printf("valid\n");
	else
		printf("invalid\n");

	return 0;
}

void readstr(char str[], int *n){
	// int i = 0, c;
	// while ((c = getchar()) != '\n')
	// 	i++;
	// i--;
	// str[i] = '\0';
	// *n = i;
	int i = 0, c;
	while ((c = getchar()) != '\n'){
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	*n = i-1;
}

int getsymb(char str[], int length, int *ppos){
	char c;
	if (*ppos < length)
		c = str[*ppos];
	else
		c = ' ';
	(*ppos)++;
	return c;
}

int expr(char str[], int length, int *ppos){

	// look for a term
	if (term(str, length, ppos) == FALSE)
		return FALSE;
	if (getsymb(str, length, ppos) != '+'){
		(*ppos)--;
		return TRUE;
	}
	return term(str, length, ppos);
}

int term(char str[], int length, int *ppos){
	if (factor(str, length, ppos) == FALSE)
		return FALSE;
	if (getsymb(str, length, ppos) != '*'){
		(*ppos)--;
		return TRUE;
	}
	return factor(str, length, ppos);
}

int factor(char str[], int length, int *ppos){
	int c;

	if ((c = getsymb(str, length, ppos)) != '(')
		return isalpha(c);
	return (expr(str, length, ppos) && getsymb(str, length, ppos) == ')');
}











