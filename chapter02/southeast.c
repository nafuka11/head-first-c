#include <stdio.h>

void go_south_east(int *lat, int *lon)
{
	*lat -= 1;
	*lon += 1;
}

int main(void)
{
	int latitude = 32;
	int longitude = -64;

	go_south_east(&latitude, &longitude);
	printf("停止! 現在位置: [%i, %i]\n", latitude, longitude);
	return 0;
}
