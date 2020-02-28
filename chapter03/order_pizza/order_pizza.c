#include <stdio.h>
#include <unistd.h>

/**
 * @brief コマンドラインオプションからthick, deliveryを取得。argc, argvを更新する
 * @param thick ピザの厚みフラグ
 * @param delivery 届ける時間
 * @param argc コマンドライン引数個数のポインタ
 * @param argv コマンドライン文字列のポインタ
 * @return int 1=正常 0=異常
 */
int parse_options(int *thick, char **delivery, int *argc, char **argv[])
{
	char ch;
	while ((ch = getopt(*argc, *argv, "d:t")) != EOF)
	{
		switch (ch)
		{
		case 'd':
			*delivery = optarg;
			break;
		case 't':
			*thick = 1;
			break;
		default:
			return 0;
		}
	}
	*argc -= optind;
	*argv += optind;
	return 1;
}

/**
 * @brief ピザのオーダー内容を表示する
 * @param thick ピザの厚みフラグ
 * @param delivery 届ける時間
 * @param argc コマンドライン引数の個数
 * @param argv コマンドライン文字列（具材）
 */
void print_delivery_info(int thick, char *delivery, int argc, char *argv[])
{
	int count = 0;

	if (thick)
	{
		puts("Thick crust.");
	}
	if (delivery[0])
	{
		printf("To be delivered %s.\n", delivery);
	}
	puts("Ingredients:");
	for (count = 0; count < argc; count++)
	{
		puts(argv[count]);
	}
}

int main(int argc, char *argv[])
{
	char *delivery = "";
	int thick = 0;

	if (!parse_options(&thick, &delivery, &argc, &argv))
	{
		fprintf(stderr, "Unknown option: %s\n", optarg);
		return 1;
	}
	print_delivery_info(thick, delivery, argc, argv);
	return 0;
}
