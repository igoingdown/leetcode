#include <stdio.h>
#include "t.h"

struct
{
	char a;
	int b;
} b = {10, 68};

int main();

void foo(void) {
	printf("foo:\n");
	printf("&a: %x\n", &a);
	printf("&b: %x\n", &b);
	printf("sizeof(b): %d\n", sizeof(b));
	printf("b.a: %d\n", b.a);
	printf("b.b: %d\n", b.b);
	printf("main: %x\n", main);
}


