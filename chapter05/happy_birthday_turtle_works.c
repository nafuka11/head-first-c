/**
 * @file happy_birthday_turtle_works.c
 * @brief マートルの誕生祝い
 * @author nafuka11
 * @date 2020-03-28
 */
#include <stdio.h>

typedef struct
{
	const char *name;
	const char *species;
	int age;
} turtle;


void happy_birthday(turtle *t)
{
	t->age = t->age + 1;
	printf("誕生日おめでとう、%s！これで%i才ですね！\n",
		t->name, t->age);
}

int main(void)
{
	turtle myrtle = {"マートル", "オサガメ", 99};
	happy_birthday(&myrtle);
	printf("%sの年齢は%i才です\n", myrtle.name, myrtle.age);
	return 0;
}
