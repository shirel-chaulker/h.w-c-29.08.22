#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)


int main()
{
	int arr1[4];
	int arr2[8];
	int sum = 0;
	int sum2 = 0;
	int m;
	FILE* f2 = fopen("array3.dat", "w");


	if (f2 == NULL)
	{
		//error
	}
	else
	{
		for (int i = 0;i < 4;i++)
		{

			printf("enter a number");
			scanf("%d", &arr1[i]);
			sum = sum + arr1[i];
			
		}
		for (int i = 0;i < 8;i++)
		{
			printf("enter a number");
			scanf("%d", &arr2[i]);
			sum2 = sum2 + arr2[i];

		}

		if (sum > sum2)
		{
			m = sum;
		}
		else {
			m = sum2;
		}
		fwrite(m, sizeof(int), 8, f2);

		
		fclose(f2);
	}
}