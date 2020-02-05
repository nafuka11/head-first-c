/**
 * カードカウントを計算するプログラム
 * このコードはベガスパブリックライセンスの下で公開されています。
 * (c)2014 カレッジブラックジャックチーム
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 標準入力からカード名を読み取る
 * @return int 1-11=card 0=不正値 -1=終了
 */
int input_card(void)
{
	char card_name[3];
	puts("カード名を入力してください：");
	scanf("%2s%*[^\n]", card_name);
	int val = 0;
	switch (card_name[0])
	{
	case 'K':
	case 'Q':
	case 'J':
		val = 10;
		break;
	case 'A':
		val = 11;
		break;
	case 'X':
		val = -1;
		break;
	default:
		val = atoi(card_name);
		if (!(1 <= val && val <= 10))
		{
			val = 0;
		}
	}
	return val;
}

/**
 * @brief メイン関数
 * @return int 終了コード
 */
int main(void)
{
	int val = 0;
	int count = 0;
	while (val >= 0)
	{
		val = input_card();
		if (val == 0)
		{
			printf("有効なカード名を入力してください\n");
			continue;
		}
		if (val == -1)
		{
			continue;
		}
		if (3 <= val && val <= 6)
		{
			count++;
		}
		if (val == 10)
		{
			count--;
		}
		printf("現在のカウント：%i\n", count);
	}
	return 0;
}
