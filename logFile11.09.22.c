#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main_1()
{
	FILE* f = fopen("myprog.log", "w");

	fputs("line1\n", f);
	fputs("line1\n", f);
	fputs("line1\n", f);
	fclose(f);

	char str[1000];

	f = fopen("myprog.log", "r");
	while (fgets(str, 1000, f) != NULL);
	{
		printf("%s", str);
	}

}