/*what will happen when use string as lvalue and rvalue?*/
#include <stdio.h>
int main(int argc, const char *argv[])
{
//	char i = "1234";
	char q = 'c';
	char *msg = "hello world!";
	msg = "metaQ";
	printf("%d\n", q);
	printf("%s\n", msg);
	return 0;
}
