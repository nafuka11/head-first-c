/**
 * @file test_flight.c
 * @brief 島々のツアー
 * @author nafuka11
 * @date 2020-03-29
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct island
{
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

island *create(char *name)
{
	island *i = (island *)malloc(sizeof(island));
	i->name = strdup(name);
	i->opens = "09:00";
	i->closes = "17:00";
	i->next = NULL;
	return i;
}

island *create_from_input(void)
{
	char name[80];

	printf("島名を入力してください：");
	fgets(name, 80, stdin);
	island *p_island = create(name);
	return p_island;
}

void display(island *start)
{
	island *i = start;
	for(; i != NULL; i = i->next)
	{
		printf("名前：%s営業時間：%s-%s\n", i->name, i->opens, i->closes);
	}
}

int main(void)
{
	island *p_island0 = create_from_input();
	island *p_island1 = create_from_input();
	p_island0->next = p_island1;

	display(p_island0);

	// TODO: free islands
	return 0;
}
