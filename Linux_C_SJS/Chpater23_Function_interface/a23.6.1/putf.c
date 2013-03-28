#include <stdio.h>

void putf(double x)
{
		int byte = (int)(x * 1000000);
		printf("%d\n", byte);
}

int main(int argc, const char *argv[])
{
	double a = 1235.24;
	putf(a);
	return 0;
}
