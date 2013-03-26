#include <stdio.h>
#include "para_allocator.h"

int main(int argc, const char *argv[])
{
	unit_t *p = NULL;
	
	alloc_unit(p);
	printf("number: %d\nmsg:%s\n", p->number, p->msg);
	free_unit(p);
	p = NULL;
	return 0;
}
