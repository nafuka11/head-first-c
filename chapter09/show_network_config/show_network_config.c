#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define UNIX_CMD	"/sbin/ifconfig"
#define WIN_CMD		"ipconfig"

int main(void)
{
	if(execl(UNIX_CMD, UNIX_CMD, NULL) == -1)
	{
		if(execlp(WIN_CMD, WIN_CMD, NULL) == -1)
		{
			fprintf(stderr, "Cannot run %s: %s", WIN_CMD, strerror(errno));
			return 1;
		}
	}
	return 0;
}