#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;


void reverse_cstr(char *str);

int main() {
	char *s;
	gets(s);
	reverse_cstr(s);
	return 0;
}


void reverse_cstr(char *str) {
	if (str == NULL) return;
	int len = strlen(str);
	int left = 0, right = len - 1;
	while (left < right) swap(str[left++], str[right--]);
	cout << str << endl;
}