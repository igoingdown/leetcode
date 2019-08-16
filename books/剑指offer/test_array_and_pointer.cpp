#include <iostream>
#include <cstring>

using namespace std;

void foo();
int main() {
	foo();
	return 0;
}

// C++将常量存放在单独的内存区

void foo() {
	char str1[] = "hello world";  // 初始化数组时要分配内存，并把常量复制一份到数组中
	char str2[] = "hello world";
	char *str3 = "hello"; // 初始化指针不需要分配内存，直接将指针指向常量即可
	char *str4 = "hello";
	cout << "1 and 2: ";
	if (str2 == str1) cout << "Y" << endl;
	else cout << "N" << endl;
	cout << "3 and 4: ";
	if (str4 == str3) cout << "Y" << endl; 
	else cout << "N" << endl;
}