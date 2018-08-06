#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nametype
{
	char fn[10], ln[10];
};

struct student
{
	struct nametype name;
	float gpi;
};

struct employee
{
	struct nametype name;
	int salary;
};

struct employee e[100];
struct student s[100];

int main(){
	if (!strcmp(e.name.fn, s.name.fn) && !strcmp(e.name.ln, s.name.ln))
		if (s.gpi > 3.0)
			e.salary *= 1.10;
}