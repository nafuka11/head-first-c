/**
 * @file tour1.c
 * @brief 島々のツアー
 * @author nafuka11
 * @date 2020-03-29
 */
#include <stdio.h>

typedef struct island
{
	char *name;
	char *opens;
	char *closes;
	struct island *next;
} island;

void display(island *start)
{
	island *i = start;
	for(; i != NULL; i = i->next)
	{
		printf("名前：%s 営業時間：%s-%s\n", i->name, i->opens, i->closes);
	}
}

int main(void)
{
	island amity = {"アミティー", "09:00", "17:00", NULL};
	island craggy = {"クラッギー", "09:00", "17:00", NULL};
	island isla_nublar = {"イスラヌブラル", "09:00", "17:00", NULL};
	island shutter = {"シャッター", "09:00", "17:00", NULL};

	amity.next = &craggy;
	craggy.next = &isla_nublar;
	isla_nublar.next = &shutter;

	island skull = {"スカル", "09:00", "17:00", NULL};
	isla_nublar.next = &skull;
	skull.next = &shutter;

	display(&amity);
	return 0;
}
