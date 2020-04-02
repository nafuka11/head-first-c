#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define PYTHON_CMD		"/usr/bin/python2.7"
#define RSS_GOSSIP_PATH	"./rssgossip.py"

int main(int argc, char *argv[])
{

	char *feeds[] = {
		"http://feeds.bbci.co.uk/news/world/rss.xml",
		"https://www.nytimes.com/svc/collections/v1/publish/https://www.nytimes.com/section/world/rss.xml",
		"https://www.buzzfeed.com/world.xml"
	};
	int feed_count = 3;
	char *phrase = argv[1];
	int i;

	for(i = 0; i < feed_count; i++)
	{
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = {var, NULL};

		pid_t pid = fork();

		if (pid == -1)
		{
			fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
			return 1;
		}
		if (!pid)
		{
			if (execle(PYTHON_CMD, PYTHON_CMD, RSS_GOSSIP_PATH, phrase, NULL, vars) == -1)
			{
				fprintf(stderr, "Can't run script: %s\n", strerror(errno));
				return 1;
			}
		}
	}

	return 0;
}
