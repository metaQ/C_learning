#include <stdio.h>
#include "qsort.h"

int a[7] = {11,2,5,6,3,88,1};
int compare (const void *a, const void *b)
{
		if (*(int *)a > *(int *)b) {
			return 1;
		}
		else if (*(int *)a == *(int *)b) {
			return 0;
		}
		else {
			return -1;
		}
}

int main(int argc, const char *argv[])
{
	int i = 0;
	for (i = 0; i < 7; i++) {
		printf("%d \n", a[i]);
	}
	printf("\n");
	meta_qsort(a, 7, sizeof(int), compare);
	for (i = 0; i < 7; i++) {
		printf("%d \n", a[i]);
	}
	printf("\n");
	return 0;
}
