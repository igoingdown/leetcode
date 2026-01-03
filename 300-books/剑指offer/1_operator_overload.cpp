#include <iostream>
#include <cstring>

using namespace std;


class MyString {
public:
	MyString(const char * const p) {
		str = new char[strlen(p) + 1];
		strcpy(str, p);
	}

	MyString() {
		str = nullptr;
	}

	MyString(const MyString& s) {
		str = new char[strlen(s.str) + 1];
		strcpy(str, s.str);
	}
	~MyString() {
		if (str != nullptr) delete []str;
		str = nullptr;
	}

	// 这种实现可以避免使用strcpy，避免出现新的对象构造不成功，而旧的对象已经改变的情况。
	MyString & operator= (const MyString& s) {
		if (this != &s) { // 比较时应该使用指针而不应该使用对象来比较
			MyString tmp(s);
			char *p = this->str;
			this->str = tmp.str;
			tmp.str = p;   
			// 相当于用swap来实现，避免临时对象销毁之后this的str也被销毁。
			// 应该使用swap，让tmp被销毁时顺带销毁this之前指向的对象。
		}
		return *this;
	}
	void print_str() {
		cout << str << endl;
	}



	// // 采用这种方式时，如果分配空间不成功，this指向的对象被删除，不可逆！
	// MyString& operator= (const MyString& s) {
	// 	if (this == &s) return *this;  
	// 	if (str != nullptr) delete []str;
	// 	str = nullptr;
	// 	str = new char[strlen(s.str) + 1];
	// 	strcpy(str, s.str);
	// 	return *this;
	// }


private:
	char *str;
};


int main(int argc, char const *argv[])
{
	/* code */
	MyString s("aaaaa");
	MyString b = s;
	b.print_str();
	s.print_str();
	return 0;
}










