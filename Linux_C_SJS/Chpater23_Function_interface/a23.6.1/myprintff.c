#include <stdio.h>
#include <stdarg.h>
void putf(double x)
{
	double a = x * 1000000;
	char q;
	int byte = (int)a;
/*	if (byte > 10000000000) {
		q = byte / 10000000000 % 10;
		putchar(q+48);
	}
*/	
	if (byte > 1000000000) {
		q = byte / 1000000000 % 10;
		putchar(q+48);
	}
	if (byte > 100000000) {
		q = byte / 100000000 % 10;
		putchar(q+48);
	}
	if (byte > 10000000) {
		q = byte / 10000000 % 10;
		putchar(q+48);
	}
	if (byte > 1000000) {
		q = byte / 1000000 % 10;
		putchar(q+48);
		putchar('.');
	}
	if (byte > 100000) {
		q = byte / 100000 % 10;
		putchar(q+48);
	}
	if (byte > 10000) {
		q = byte / 10000 % 10;
		putchar(q+48);
	}
	if (byte > 1000) {
		q = byte / 1000 % 10;
		putchar(q+48);
	}
	if (byte > 100) {
		q = byte / 100 % 10;
		putchar(q+48);
	}
	if (byte > 10) {
		q = byte / 10 % 10;
		putchar(q+48);
	}
	q = byte % 10;
	putchar(q+48);

}

void putx(int x)
{
	int byte = x;
	putchar('0');
	putchar('x');
	if (x > 0xfffffff) {
		byte = x;
		byte &= 0xf0000000;
		byte = byte >> 28;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xffffff) {
		byte = x;
		byte &= 0x0f000000;
		byte = byte >> 24;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xfffff) {
		byte = x;
		byte &= 0x00f00000;
		byte = byte >> 20;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xffff) {
		byte = x;
		byte &= 0x000f0000;
		byte = byte >> 16;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xfff) {
		byte = x;
		byte &= 0x0000f000;
		byte = byte >> 12;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xff) {
		byte = x;
		byte &= 0x00000f00;
		byte = byte >> 8;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}	
	if (x > 0xf) {
		byte = x;
		byte &= 0x000000f0;
		byte = byte >> 4;
		if(byte < 10)
			putchar(byte+48);
		else
			putchar(byte+55);
	}

	byte = x;
	byte &= 0xf;
	if(byte < 10)
		putchar(byte+48);
	else
		putchar(byte+55);
}
void myprintf(const char *format, ...)
{
		va_list ap;
		char c;
		//size_t ch;
		va_start(ap, format);
		while (c = *format++) {
			if(c != '%') {
					putchar(c);
			}
			else {
				c = *format++;
				switch (c) {
						case 'c': {
								char ch = va_arg(ap, int);
								putchar(ch);
								break;
						}
						case 's': {
								char *ch = va_arg(ap, char *);
								puts(ch);
								break;
						}
						case 'x': {
								int ch = va_arg(ap, int);
								putx(ch);
								break;
						}
						case 'f': {
								double ch = va_arg(ap, double);
								putf(ch);
								break;
						default:
								return;
						}
				}
		}
	}
}

int main(int argc, const char *argv[])
{
	int a = 0xe123abc;
	double b = 1234.23;
	myprintf("metaQ%x\n%f\n", a, b);
	return 0;
}

