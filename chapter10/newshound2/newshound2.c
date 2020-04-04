/**
 * @file newshound2.c
 * @brief RSS Gossipの出力をstories.txtに保存するプログラム
 * @author nafuka11
 * @date 2020-04-02
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define PYTHON_CMD		"/usr/bin/python2.7"
#define RSS_GOSSIP_PATH	"./rssgossip.py"

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		puts("Please set an argument");
		return 1;
	}
	char* phrase = argv[1];
	char* vars[] = {"RSS_FEED=https://www.reddit.com/r/worldnews/.rss", NULL};
	FILE* f = fopen("stories.txt", "w");
	if (!f) {
		error("Can't open stories.txt");
	}
	pid_t pid = fork();
	if (pid == -1) {
		error("Can't fork process");
	}
	if (!pid) {
		if (dup2(fileno(f), STDOUT_FILENO) == -1) {
			error("Can't redirect Standard Output");
		}
		if (execle(PYTHON_CMD, PYTHON_CMD, RSS_GOSSIP_PATH, phrase, NULL, vars) == -1) {
			error("Can't run script");
		}
	}
	int pid_status;
	if (waitpid(pid, &pid_status, 0) == -1)
	{
		error("Error waiting for child process");
	}
	return 0;
}
