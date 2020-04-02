/**
 * @file guard_log.c
 * @brief ログファイルにタイムスタンプを書き込むプログラム
 * @author nafuka11
 * @date 2020-04-01
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *now(void)
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

int main(void)
{
	char comment[80];
	char cmd[120];

	fgets(comment, 80, stdin);
	sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

	system(cmd);
	return 0;
}