#include <stdio.h>
#include "ret_ptr.h"

int main(int argc, const char *argv[])
{
	printf("%s %s\n", get_a_day(0), get_a_day(1));
	
//	printf("%s %s\n", get_a_day(1), get_a_day(0));
	return 0;
}
