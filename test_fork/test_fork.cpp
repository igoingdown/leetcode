#include <stdio.h>
#include <unistd.h>　
#include <sys/types.h>

int main() {
	pid_t pid;
	int x = 1;
	pid = fork();
	if (pid == 0) {
		printf("child: %d\n", ++x);
		printf("child: %x\n", &x);
	} else {
		printf("parent: %d\n", --x);
		printf("parent: %x\n", &x);
	}
	return 0;
}