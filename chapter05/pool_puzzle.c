/**
 * @file pool_puzzle.c
 * @brief 水族館の魚の情報表示
 * @author nafuka11
 * @date 2020-03-28
 */
#include <stdio.h>

struct exercise
{
	const char *description;
	float duration;
};

struct meal
{
	const char *ingredients;
	float weight;
};

struct preferences
{
	struct meal food;
	struct exercise exercise;
};

struct fish
{
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct preferences care;
};

void catalog(struct fish f)
{
	printf("%sは%sであり、歯は%i本あります。年齢は%i才です\n",
		f.name, f.species, f.teeth, f.age);
}

void label(struct fish f)
{
	printf("名前：%s\n", f.name);
	printf("種類：%s\n", f.species);
	printf("%i本の歯、%i才\n", f.teeth, f.age);
	printf("餌は%2.2fキロの%sを与え、%sを%2.2f時間行わせます\n",
		f.care.food.weight, f.care.food.ingredients,
		f.care.exercise.description, f.care.exercise.duration);
}

int main(void)
{
	struct fish snappy = {"スナッピー", "ピラニア", 69, 4,
	{
		{"肉", 0.1},
		{"ジャグジーでの泳ぎ", 7.5}
	}};
	catalog(snappy);
	label(snappy);
	return 0;
}
