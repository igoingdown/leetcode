#include <stdio.h>
#include "t.h"


int b, c;

int main();

int main(void) {
	foo();
	printf("main:\n");
	printf("&a: %x\n", &a);
	printf("&b: %x\n", &b);
	printf("&c: %x\n", &c);
	printf("sizeof(b): %d\n", sizeof(b));
	printf("b: %d\n", b);
	printf("c: %d\n", c);

	return 0;
}


