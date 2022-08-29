#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main()
{
	struct people
	{
		int val;
		char name[100];
		short answer;
	};

	struct people arr[3];

	for (int i = 0; i < 3;i++)
	{

		
			int val;
			char name[100];
			short answer;
			printf("\n enter val");
			scanf("%d", &val);

			printf("\n enter a name");
			scanf("%s", name);

			arr[i].val = val;
			strcpy(arr[i].name, name);
			answer = (strlen(name) > 5 && val > 10) ? 1 : 0;
			arr[i].answer = answer;
	}
	
	
		FILE* f = fopen("h.w.data", "w");
		if(f==NULL)
		{
			//ERROR
		}
		else
		{
			int written = fwrite(arr, sizeof(struct people), 3, f);
		}
		fclose(f);
		return 0;
		
}

