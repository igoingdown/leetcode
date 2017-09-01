#include <stdio.h>

typedef unsigned char * bytePointer;

void showByte(bytePointer p, size_t s) {
	for (size_t i = 0; i < s; i++) {
		printf("%.2x ", p[i]);
	}
	printf("\n");
}

void showInt(int x) {
	showByte((bytePointer) &x, sizeof(x));
}

void showFloat(float x) {
	showByte((bytePointer) &x, sizeof(x));
}

void showLong(long x) {
	showByte((bytePointer) &x, sizeof(x));
}

void showPointer(void * x) {
	showByte((bytePointer) &x, sizeof(void *));
}

void testShowByte(int x) {
	int y = x;
	showInt(x);
	float z = (float)x;
	showFloat(z);
	int * p = &y;
	showPointer(p);
}


int main() {
	int x = 12345;
	// testShowByte(x);
	showInt(x);
	int mx = -x;
	showInt(mx);
	return 0;
}