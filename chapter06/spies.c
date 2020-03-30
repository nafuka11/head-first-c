/**
 * @file spies.c
 * @brief SPIESシステム
 * @author nafuka11
 * @date 2020-03-30
 * @details 二分木を使い、個人の特定方法を学習するエキスパートシステム
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *question;
	struct node *no;
	struct node *yes;
} node;

int yes_no(char *question)
{
	char answer[3];
	printf("%s？ (y/n): ", question);
	fgets(answer, 3, stdin);
	return answer[0] == 'y';
}

node *create(char *question)
{
	node *n = (node *)malloc(sizeof(node));
	n->question = strdup(question);
	n->no = NULL;
	n->yes = NULL;
	return n;
}

void release(node *n)
{
	if (n)
	{
		if (n->no)
		{
			release(n->no);
		}
		if (n->yes)
		{
			release(n->yes);
		}
		if (n->question)
		{
			free(n->question);
		}
		free(n);
	}
}

int main(void)
{
	char question[80];
	char suspect[20];

	node *start_node = create("容疑者はひげを生やしているか");
	start_node->no = create("ロレッタ・バーンスワース");
	start_node->yes = create("ベニー・ザ・スプーン");

	node *current;
	do
	{
		current = start_node;
		while (1)
		{
			if (yes_no(current->question))
			{
				if (current->yes)
				{
					current = current->yes;
				}
				else
				{
					printf("容疑者判明\n");
					break;
				}
			}
			else if (current->no)
			{
				current = current->no;
			}
			else
			{
				/* yesノードを新しい容疑者名にする */
				printf("容疑者は誰？");
				fgets(suspect, 20, stdin);
				node *yes_node = create(suspect);
				current->yes = yes_node;

				/* noノードをこの質問のコピーにする */
				node *no_node = create(current->question);
				current->no = no_node;

				/* この質問を新しい質問に置き換える */
				printf("%sに当てはまり、%sには当てはまらない質問は？",
					suspect, current->question);
				fgets(question, 80, stdin);

				/* メモリリーク修正箇所 */
				free(current->question);

				current->question = strdup(question);
				break;
			}
		}
	}
	while (yes_no("再実行しますか"));

	release(start_node);
	return 0;
}
