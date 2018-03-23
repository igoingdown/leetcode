#include <iostream>
#include <vector>

using namespace std;

class C1
{
public:
	C1(){
		sum += ++num;
	}
	static int get_sum() {
		return sum;
	}

	static void reset() {
		num = 0; sum = 0;
	}
private:
	static int num;
	static int sum;
};

int bar(int n);
int foo(int n);

int C1:: num = 0;
int C1:: sum = 0;


typedef int (*func) (int n);

int main(int argc, char const *argv[])
{
	int n = 0; cin >> n;
	C1::reset();
	C1 *tmp = new C1[n];
	cout << C1::get_sum() << endl;
	delete []tmp;
	cout << bar(n) << endl;
	return 0;
}


int foo(int n) {
	return 0;
}

int bar(int n) {
	static func f[2] = {&foo, &bar};
	return n + f[!!n](n - 1);
}