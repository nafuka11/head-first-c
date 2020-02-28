#include <stdio.h>

int main(void)
{
	float latitude;
	float longtitude;
	char info[80];
	while (scanf("%f,%f,%79[^\n]", &latitude, &longtitude, info) == 3)
	{
		if (26 < latitude && latitude < 34)
		{
			if (-76 < longtitude && longtitude < -64)
			{
				printf("%f,%f,%s\n", latitude, longtitude, info);
			}
		}
	}
	return 0;
}
