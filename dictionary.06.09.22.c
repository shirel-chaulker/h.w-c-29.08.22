#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)


struct dictionary {
	int key;
	int val;
	struct dictionary* prev;
	struct dictionary* next;
};

struct dictionary* head = NULL;
struct dictionary* tail = NULL;
struct dictionary* kodem;
struct dictionary* move;

void Add(int key, int val)
{
	move = (struct dictionary*)malloc(sizeof(struct dictionary));
	if (!move)
	{
		exit(1);
	}
	if (head == NULL)
	{
		head = move;
		tail = move;
		move->next = NULL;
		move->prev = NULL;
	}
	else
	{
		move = tail;
		move->prev = kodem;
		move->next = NULL;
		kodem->next = move;
	}
	move->key = key;
	move->val = val;
	kodem = move;

}

struct dictionary* search(int key)
{
	struct dictionary* move = head;
	struct dictionary* searching = NULL;
	

	while (move != NULL)
	{
		searching = move;
		move = move->next;

		if (searching->key == key)
		{
			return searching;
		}

		else
		{
			printf("searching  was not found");
			struct dictionary* ret = NULL;
			return ret;
		}
		
	}
}

void remove(int key_remove)
{
	struct dictionary* release;
	struct dictionary* cur = search(key_remove);

	if (cur == NULL)
	{
		printf("the key wasnt found \n");
	}
	else if (cur == head && cur->next == NULL)
	{
		tail = NULL;
		head = NULL;
		kodem = NULL;
		free(move);
	}
	 
	 else if (cur == head)
	{
		release = cur;
		cur = cur->next;
		cur->prev= NULL;
		head = cur;
		free(release);
	}
	else if (cur==tail)
	{
		release = cur;
		cur = cur->prev;
		cur->next = NULL;
		tail = cur;
		free(release);
	}
	else
	{

		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);

	}

}

int main_1()
{
	int userResponse = 1;
	while (userResponse != 0)
	{
		printf("Press 1 to add two numbers\n Press 2 to see the value \n");
		userResponse = getch();

		switch (userResponse)
		{
		case '1': printf("Enter value key and value val\n");
			int key;
			int val;
			scanf("%d%d", &key, &val);
			Add(key, val);
			break;
		case '2': printf("Enter a key to find if you have a value\n");
			int key_search;
			scanf("%d", &key_search);
			struct dictionary* print = Search(key_search);
			if (!print)
			{
				printf("key doesnt exist\n");
			}
			else
			{
				printf("the value is %d\n", print->val);
			}
			break;

		default:
			printf("error\n");
			break;
		}
	}
	return 0;
}
