#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s1 = "hello world";
	string s2 = s1;
	printf("sharing memory:\n");
	printf("s1 address: %x\n", s1.c_str());
	printf("s2 address: %x\n", s2.c_str());

	s1[0] = 'q';
	s2[0] = 'w';
	printf("after copy on write:\n");
	printf("s1 address: %x\n", s1.c_str());
	printf("s2 address: %x\n", s2.c_str());
	return 0;
}