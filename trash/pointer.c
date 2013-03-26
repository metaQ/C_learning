#include <stdio.h>
int main(int argc, const char *argv[])
{
	int a = 4;
	int *a1 = &a;
	int b = 5;
	int *b1 = &b;

	b1 = a1;
	printf("a:%d b:%d a1:%d b1:%d *a1:%d *b1:%d\n", a, b, (int)a1, (int)b1, *a1, *b1);
	return 0;
}
