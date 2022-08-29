/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main_1()
{
	int arr[5] = { 23,44,56,100,1009 };
	int arr1[5];
	FILE* f = fopen("array.dat", "w");

	if (f == NULL)
	{
		//error
	}
	else
	{
		//arr= &arr[0]
		int written = fwrite(arr, sizeof(int), 5, f);
		fclose(f);
	}

	FILE* f = fopen("array.dat", "r");
	if (f == NULL)
	{
		//error
	}
	else
	{
		int read = fread(arr1, sizeof(int), 5, f);
		fclose(f);

	}
}
*/
