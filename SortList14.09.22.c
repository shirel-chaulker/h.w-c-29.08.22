#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)


struct Itemnum {
	int num;
	struct Itemnum* next;
	struct Itemnum* prev;
};

struct Itemnum* head = NULL;
struct Itemnum* tail = NULL;


void log(char message[10000])
{
	FILE* f = fopen("projectFile.log", "a");
	if (!f)
	{
		exit(1);
	}
	time_t t;
	time(&t);

	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str[10000];

	sprintf(str, "%d.%d.%d:%d:%d:%d -%s", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
	fputs("\n", f);
	fputs(str, f);
	fclose(f);


}
void logEvent(char message[10000])
{
	char str[100];
	sprintf(str, "Event - %s", message);
	log(str);
}
void logError(char message[10000])
{
	char str[100];
	sprintf(str, "Error - %s", message);
	log(str);
}

void LogEventVal(char msg[10000], int val)
{
	char str[100];
	sprintf(str, "Item val %d : %s", val, msg);
	log(str);
}
void add(int num)
{
	LogEventVal("the num enter to the function\n", num);
	struct Itemnum* std = (struct Itemnum*)malloc(sizeof(struct Itemnum));
	if (!std)
	{
		logError("alloction didnt succeded\n");
		exit(1);
	}
	std->num = num;
	LogEventVal("the number enter to the struct\n",num);
	if (head == NULL)
	{
		logEvent("struct succeded\n");
		head = std;
		tail = std;
		std->next = NULL;
		std->prev = NULL;
	}
	else
	{
		logEvent("new struct is created\n");
		std->prev = head;
		head->next = std;
		std->next = NULL;
		tail = std;
	}

	logEvent("function add is finish\n");

}
void printlist()
{
	logEvent("print list is starting\n");
	struct Itemnum* curr = head;
	struct Itemnum* newitem = head;


	while (newitem != NULL)
	{
		newitem = newitem->next;
		printf(" the number is %d\n", curr->num);
		curr = newitem;
	}

	logEvent("the list is printed\n");
}

void Replace(struct Itemnum* item)
{
	logEvent("the system is get into replace");
	struct Itemnum* swapitem;
	swapitem = item;
	if (swapitem == NULL)
	{
		LogEventVal("there is no struct", swapitem->num);
		return;
	}

	else if (swapitem->next == NULL)
	{
		LogEventVal("if we have 1 file", swapitem->num);
		return;
	}
	else if (swapitem == head && swapitem->next == tail)
	{
		LogEventVal("got two numbers", swapitem->num);
		swapitem->prev = tail;
		swapitem->next = NULL;
		tail->prev = NULL;
		tail->next = swapitem;
		head = tail;
		tail = swapitem;
	}
	else if (swapitem == head)
	{
		LogEventVal("there is more than two numbers", swapitem->num);
		swapitem->prev = swapitem->next;
		swapitem->next = swapitem->next->next;
		swapitem->prev->next = swapitem;
		swapitem->prev->prev = NULL;
		swapitem->next->prev = swapitem;

		head = swapitem->prev;

	}
	else if (swapitem->next == tail)
	{
		LogEventVal("before the last item", swapitem->num);
		swapitem->prev->next = swapitem->next;
		swapitem->next->prev = swapitem->prev;
		swapitem->next->next = swapitem;
		swapitem->prev = swapitem->next;
		swapitem->next = NULL;

		tail = swapitem;
	}
	else
	{
		LogEventVal("mid list", swapitem->num);
		swapitem->prev->next = swapitem->next;
		swapitem->next->prev = swapitem->prev;
		swapitem->next->next->prev = swapitem;
		swapitem->prev = swapitem->next;
		swapitem->next = swapitem->next->next;
		swapitem->prev->next = swapitem;
	}

	logEvent("bubble sort is complate");
}
void Sort()
{
	logEvent("start to sort");
	struct Itemnum* curr = head;

	if (!curr) 
	{
		logError("The List is empty");
		return;
	}
	char change = 1;

	while (change != 0)
	{
		change = 0;
		while (curr != NULL)
		{
			if (curr->next != NULL && curr->num > curr->next->num)
			{
				Replace(curr);
				change++;
			}
			curr = curr->next;
		}
		curr = head;
	}
	logEvent("the sorting process has ended");
	printlist();
}


int main()
{
	;logEvent("start of log");
	time_t t;
	time(&t);
	struct tm* timeinfo;
	timeinfo = localtime(&t);
	char str_time[10000];
	int time_hs = timeinfo->tm_hour;
	int time_ms = timeinfo->tm_min;
	int time_cs = timeinfo->tm_sec;

	int num1;
	for (int j = 0; j <= 10; j++)
	{
		scanf("%d", &num1);
		printf("%d\n", num1);
	}

	Sort();

	logEvent("strat of log and run \n");
	time_t i = time(NULL);
	srand(i);
	int numRand;
	for (int i = 1; i <= 500;i++)
	{
		numRand = rand();
		add(numRand);
	}

	time_t t_e;
	time(&t_e);
	struct tm* timeinfo_e;
	timeinfo_e = localtime(&t_e);
	int sum_he = timeinfo_e->tm_hour - time_hs;
	int sum_me = timeinfo_e->tm_min - time_ms;
	int sum_ce = timeinfo_e->tm_sec - time_cs;
	sprintf(str_time, "The time that passed from the start of the process to its end is   %d  :  %d  :  %d\n", sum_he, sum_me, sum_ce);
	logEvent(str_time);
	logEvent("End of log And run\n\n\n\n\n");

	return 0;
}