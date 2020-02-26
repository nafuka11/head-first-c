#include <stdio.h>
#include <string.h>

#define TRACK_LEN 80

const char TRACKS[][TRACK_LEN] = {
	"I left my heart in Harvard Med School",
	"Newark, Newark - a wonderful town",
	"Dancing with a Dork",
	"From here to maternity",
	"The girl from Iwo Jima"
};

void find_track(char search_for[])
{
	for (int i = 0; i < 5; i++)
	{
		if (strstr(TRACKS[i], search_for))
		{
			printf("曲番号%i: '%s'\n", i, TRACKS[i]);
		}
	}
}

int main(void)
{
	char search_for[TRACK_LEN];

	printf("検索語: ");
	fgets(search_for, TRACK_LEN, stdin);
	search_for[strlen(search_for) - 1] = '\0';

	find_track(search_for);
	return 0;
}
