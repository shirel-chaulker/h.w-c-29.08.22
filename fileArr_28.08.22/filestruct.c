#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
/*
int main()
{
	struct student
	{
		int age;
		char name[100];
		int classLevel;
	};

	struct student s = { 20, "Amos",1 };

	FILE* f = fopen("onestudent.dat", "w");
	if (f == NULL)
	{
		//error
	}
	else
	{
		fwrite(&s, sizeof(struct student), 1, f);
		fclose(f);
		///////////////////////////////////////////////////////////////////////

	}

	//prepare memory

	struct student* List;
	struct student* currentstudent;
	int size = 4;
	List = malloc(sizeof(struct student) * size);
	currentstudent = List;


	currentstudent-> age = 30;
	strcpy(currentstudent->name, "matan");
	currentstudent->classLevel = 2;
	currentstudent++;

	 f = fopen("onestudent.dat", "w");
	 fwrite(List, sizeof(struct student), size, f);
	 fclose(f);
	return 0;
}
*/