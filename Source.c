#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

char message;
int num;
char snum[100];

void log(char message[1000])
{
	FILE* f = fopen("secondfile.log", "a");
	if (!f)
	{
		LogError("file not open");
		
	}
	else
	{

		
		time_t t;
		time(&t);

		struct tm* timeinfo;
		timeinfo = localtime(&t);
		char str[100];

		sprintf(str, "%d.%d.%d:%d:%d:%d -%s", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min,timeinfo->tm_sec, message);
		fputs("\n", f);
		fputs(str, f);
		fclose(f);
	}

}

 LogError(char message[100])
{

	char newmessage[100];
	sprintf(newmessage, "error - %s", message);
	log(newmessage);

	
}
void LogEvent(char message[100])
{
	char events[100];
	sprintf(events, "event - %s", message);
	log(events);
}


int main()
{
	log("start of log");
	LogEvent("system is starting");


	printf("please enter a number");
	scanf("%d", &num);
	sprintf(snum, "%d\n", num);
	LogEvent("the system get value from the user");
	log(snum);
	
	FILE* f1 = fopen("numbers.txt", "w");

	if (!f1)
	{
		LogError("error f1 didnt open");
	}
	else
	{
		LogEvent("the file open");
		char arr[100];
		for (int i = 1;i < num;i++)
		{
			sprintf(arr, "%d\n", i);
			fputs(arr, f1);
		}
	}
	fclose(f1);

	LogEvent("end of log");
	LogEvent("system is finish");
}