/**
 * @file margarita.c
 * @brief マルガリータのレシピ表示
 * @author nafuka11
 * @date 2020-03-29
 */
#include <stdio.h>

typedef union
{
	float lemon;
	int lime_pieces;
} lemon_lime;

typedef struct
{
	float tequila;
	float cointreau;
	lemon_lime citrus;
} margarita;

void show_boundary(void)
{
	printf("----------------------\n");
}

void show_recipe_lemon(margarita *m)
{
	show_boundary();
	printf("%2.1f単位のテキーラ\n%2.1f単位のコアントロー\n%2.1f単位のジュース\n",
		m->tequila, m->cointreau, m->citrus.lemon);
}

void show_recipe_lime_pieces(margarita *m)
{
	show_boundary();
	printf("%2.1f単位のテキーラ\n%2.1f単位のコアントロー\n%i切れのライム\n",
		m->tequila, m->cointreau, m->citrus.lime_pieces);
}

int main(void)
{
	margarita m1 = {2.0, 1.0, .citrus.lemon=2};
	show_recipe_lemon(&m1);

	margarita m2 = {2.0, 1.0, {0.5}};
	show_recipe_lemon(&m2);

	margarita m3 = {2.0, 1.0, {.lime_pieces=1}};
	show_recipe_lime_pieces(&m3);

	return 0;
}