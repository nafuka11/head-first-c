/**
 * @file sort.c
 * @brief 様々なソート
 * @author nafuka11
 * @date 2020-03-30
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_scores(const void *score_a, const void *score_b)
{
	int a = *(int *)score_a;
	int b = *(int *)score_b;
	return a - b;
}

int compare_scores_desc(const void *score_a, const void *score_b)
{
	return -compare_scores(score_a, score_b);
}

typedef struct
{
	int width;
	int height;
} rectangle;

int compare_areas(const void *a, const void *b)
{
	rectangle *rect_a = (rectangle *)a;
	rectangle *rect_b = (rectangle *)b;
	int area_a = rect_a->width * rect_a->height;
	int area_b = rect_b->width * rect_b->height;
	return area_a - area_b;
}

int compare_names(const void *a, const void *b)
{
	char *str_a = *(char **)a;
	char *str_b = *(char **)b;
	return strcmp(str_a, str_b);
}

int compare_areas_desc(const void *a, const void *b)
{
	return -compare_areas(a, b);
}

int compare_names_desc(const void *a, const void *b)
{
	return -compare_names(a, b);
}

void show_scores(int *scores, int len)
{
	int i;

	puts("These are the scores in order:");
	for (i = 0; i < len; i++)
	{
		printf("  score = %i\n", scores[i]);
	}
}

void show_names(char **names, int len)
{
	int i;

	puts("These are the names in order:");
	for (i = 0; i < len; i++)
	{
		printf("  %s\n", names[i]);
	}
}

int main(void)
{
	int scores[] = {543, 323, 32, 554, 11, 3, 112};
	int score_len = 7;
	char *names[] = {"Karen", "Mark", "Brett", "Mokky"};
	int names_len = 4;

	qsort(scores, score_len, sizeof(int), compare_scores_desc);
	qsort(names, names_len, sizeof(char *), compare_names);
	show_scores(scores, score_len);
	show_names(names, names_len);
}
