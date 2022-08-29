#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)


int main()
{
	int arr[10];
	
	

	FILE* f1 = fopen("array1.dat", "w");

	if (f1 == NULL)
	{
		//error
	}
	else
	{
		for (int i = 0;i < 10;i++)
		{
			printf("enter a number");
			scanf("%d", &arr[i]);
		}
		int written = fwrite(arr, sizeof(int), 10, f1);
		fclose(f1);
	}

}