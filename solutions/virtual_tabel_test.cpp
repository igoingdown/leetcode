#include <iostream>
#include <vector>

using namespace std;


class C1{
private:
	int a;
	virtual void f1() {
		cout << "c1" << endl;
	}

	void f2() {
		cout << "f2" << endl;
	}

	void f2() const {
		cout << "f2 const" << endl;
	}
	// 两个f2构成重载是因为隐藏的this指针不同补全之后分别为
	// void f2(C1 *const this)
	// void f2(const C1 *const this)

	void f10(const int* a) {
		cout << "f10" << endl;
	}

	void f10(int *a) {
		cout << "f10 no const" << endl;
	}

	void f5(int &a) {
		cout << "f5" << endl;
	}
	void f5(const int &a) {
		cout << "f5 const" << endl;
	}

	// 同f2,f10和f5也属于正确的重载

};

class C: public C1 {
	void f3() {
		cout << "f3" << endl;
	}
};



int main() {
	C1 c;
	int a = 10;
	cout << sizeof(a) << endl;   // 4
	cout << sizeof(c) << endl;   // 16, 内存以8B对齐，有虚函数表指针vptr(指向vtbl)，
	//  vtbl是类的，不是对象的，因为vptr是类的，不是对象的!
	// 通过对象实例的地址得到虚函数表，是因为 vptr 指针位于对象实例的最前面
	//     这是由编译器决定的，主要是为了保证取到虚函数表有最高的性能——如果有多层继承或是多重继承的情况下
	C c_child;
	cout << "sizeof child: " << sizeof(c_child) << endl;
	return 0;
}