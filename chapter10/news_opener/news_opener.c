/**
 * @file news_opener.c
 * @brief 検索文字列に一致したfeedをWebブラウザで開く
 * @author nafuka11
 * @date 2020-04-03
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PYTHON_CMD		"/usr/bin/python2.7"
#define RSS_GOSSIP_PATH	"./rssgossip.py"

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int execvp_cmd(char *cmd[])
{
	pid_t pid = fork();
	if (pid == -1)
	{
		error("Can't fork process");
	}
	if (!pid)
	{
		if (execvp(cmd[0], cmd) == -1)
		{
			return -1;
		}
	}
	return 0;
}

void open_url(char *url)
{
	char *win_cmd[] = {
		"cmd", "/c", "start", url, NULL
	};
	char *linux_cmd[] = {
		"x-www-browser", url, NULL
	};
	char *mac_cmd[] = {
		"open", url, NULL
	};
	if (!execvp_cmd(win_cmd))
	{
		return;
	}
	if (!execvp_cmd(linux_cmd))
	{
		return;
	}
	execvp_cmd(mac_cmd);
}

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		puts("Please set an argument");
		return 1;
	}
	char *phrase = argv[1];
	char *vars[] = {
		"RSS_FEED=https://www.nytimes.com/svc/collections/v1/publish/https://www.nytimes.com/section/world/rss.xml", NULL
	};
	char *cmd[] = {
		PYTHON_CMD, RSS_GOSSIP_PATH, "-u", phrase, NULL
	};
	int fd[2];

	if (pipe(fd) == -1)
	{
		error("Can't create the pipe");
	}
	pid_t pid = fork();
	if (pid == -1)
	{
		error("Can't fork process");
	}
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(cmd[0], cmd, vars) == -1)
		{
			error("Can't run script");
		}
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);

	char line[255];
	while (fgets(line, 255, stdin))
	{
		if (line[0] == '\t')
		{
			open_url(line + 1);
		}
	}
	return 0;
}
