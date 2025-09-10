#include <iostream>
#include <exception>
#include <limits.h>

using namespace std;


class MyVector {
private:
	int* arr;
	int c, l;
public:
	MyVector() {
		c = 32;
		l = 0;
		try {
			arr = new int[c];
			for (int i = 0; i < 32; i++) *(arr + i) = 0;
		} catch (exception e) {
			throw "bad alloc";
		}
	}
	MyVector(int n) {
		c = 32;
		while (c < n && c < 0x40000000) c << 1;
		if (c < n || c == 0x40000000) c = INT_MAX;
		try {
			arr = new int[c];
			for (int i = 0; i < n; i++) *(arr + i) = 0;
		} catch (exception e) {
			throw "bad alloc";
		}
		l = n;
	}
	MyVector(int n, int elem) {
		c = 32;
		while (c < n && c < 0x40000000) c << 1;
		if (c < n || c == 0x40000000) c = INT_MAX;
		try {
			arr = new int[c];
			for (int i = 0; i < n; i++) *(arr + i) = elem;
		} catch (exception e) {
			throw "bad alloc";
		}
		l = n;
	}
	void push_back(int elem) {
		if (l == c) {
			if (c == INT_MAX) throw "no more memory";
			else c *= 2;
			int* tmp = new int[c];
			for (int i = 0; i < l; i++) tmp[i] = arr[i];
			tmp[l] = elem;
			delete [] arr;
			l++;
			arr = tmp;
		} else {
			arr[l] = elem;
			l++;
		}
	}

	int operator[] (int index) {
		if (index >= l) throw "index overflow";
		return arr[index];
	}

	unsigned size() {
		return l;
	}
};

int main() {
	MyVector v(10);
	for (int i = 10; i < 40; i++) v.push_back(i);
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl; 
	return 0;
}