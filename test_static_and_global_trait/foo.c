#include <stdio.h>
#include "t.h"

struct
{
	char a;
	int b;
	long long d;
} b = {10, 68, 20};
char d = 'a';

int main();

void foo(void) {
	printf("foo:\n");
	printf("&a: %x\n", &a);
	printf("&b: %x\n", &b);
	printf("sizeof(b): %d\n", sizeof(b));
	printf("b.a: %d\n", b.a);
	printf("b.b: %d\n", b.b);
	printf("&d: %x\n", &d);
	printf("d: %d\n", d);
	printf("b.d: %d\n", b.d);
	printf("main: %x\n", main);
}


