#include <stdio.h>

int main(void) {
	unsigned i = 10;
	printf("%d\n", i);
	unsigned j = 0x01;
	printf("j: %x\n", j);
	j |= j >> 1;
	printf("j |= j >> 1: %x\n", j);
	j |= j >> 2;
	printf("j |= j >> 2: %x\n", j);
	j |= j >> 4;
	printf("j |= j >> 4: %x\n", j);
	j |= j >> 8;
	printf("j |= j >> 8: %x\n", j);
	j |= j >> 16;
	printf("j |= j >> 16: %x\n", j);
	printf("j + 1: %x\n", ++j);
	for (int i = 0; i < 10; ++i)
	{
		printf("i: %d\n", i);
	}
	return 0;
}