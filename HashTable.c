#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Data{
	int value;
	struct Data *next;
};

void insert(struct Data **table, int M)
{
	int key;
	printf("Masukan nilai : ");
	scanf("%d", &key);
	
	int idx = key % M;
	
	if(table[idx] == NULL)
	{
		table[idx] = (struct Data*)malloc(sizeof(struct Data));
		table[idx]->value = key;
		table[idx]->next = NULL;
		printf("Insert success!");
	}
	else
	{
		struct Data *ptr;
		ptr = table[idx];
		
		do
		{
			if(ptr->value == key)
				break;
			else if(ptr->next != NULL)
				ptr = ptr->next;
		}while(ptr->next != NULL);
		
		
		if(ptr->value == key)
			printf("Duplicate Data!");
		else
		{
			struct Data *newData;
			newData = (struct Data*)malloc(sizeof(struct Data));
			newData->value = key;
			newData->next = NULL;
			ptr->next = newData;
			printf("Insert success!");
		}
	}
}

void view(struct Data **table, int M)
{
	printf("The Data\n");
	printf(" Idx | Data \n");
	printf("-----+---------\n");
	for(int i=0; i<M; i++)
	{
		printf(" %3d | ", i);
		if(table[i] == NULL)
		{
			printf("NULL\n");
		}
		else
		{
			struct Data *ptr;
			ptr = table[i];
			printf("%d", ptr->value);
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
				printf(" -> %d", ptr->value);
			}
			printf("\n");
		}
	}
}

int main()
{
	int M = 7;
	struct Data *table[M];
	
	for(int i=0; i<M; i++)
		table[i] = NULL;
	
	int pilih;
	do
	{
		system("cls");
		printf("1. Input\n");
		printf("2. View\n");
		printf("3. Exit\n");
		printf("Choose >> ");
		scanf("%d", &pilih);
		
		switch(pilih)
		{
			case 1:{
				insert(table, M);
				getch();
				break;
			}
			case 2:{
				view(table, M);
				getch();
				break;
			}
			case 3:{
				break;
			}
			default:{
				printf("Wrong Input!");
				getch();
				break;
			}
		}
	}while(pilih != 3);
	return 0;
}
