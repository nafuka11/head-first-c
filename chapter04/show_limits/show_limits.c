#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("INT_MAXの値は %i\n", INT_MAX);
	printf("INT_MINの値は %i\n", INT_MIN);
	printf("intは %zuバイトを占めます\n", sizeof(int));

	printf("FLT_MAXの値は %f\n", FLT_MAX);
	printf("FLT_MINの値は %.50f\n", FLT_MIN);
	printf("floatは %zuバイトを占めます\n", sizeof(float));

	return 0;
}
