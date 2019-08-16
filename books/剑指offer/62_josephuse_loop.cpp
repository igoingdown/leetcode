#include <iostream>
#include <list>

using namespace std;


int last_element(int n, int m);
int last_element_double_direction(int n, int l, int r) ;
int last_element_single_direction_efficient(int n, int r);

int main(int argc, char const *argv[])
{
	/* code */
	int n, l, r;
	while (cin >> n >> l >> r) {
		cout << "single direction : " << last_element(n, r) << endl;
		cout << "double direction : " << last_element_double_direction(n, l, r) << endl;
		cout << "recursion res: " << last_element_single_direction_efficient(n, r) << endl; 
	}

	return 0;
}


int last_element(int n, int m) {
	list<int> l;
	for (int i = 0; i < n; i++) l.push_back(i);
	int start = 0;
	while (n > 1) {
		start = (m - 1 + start) % n;
		auto iter = l.begin();
		int index = start;
		while (iter != l.end() && index--) iter++;
		l.erase(iter); 
		--n;
	}
	return *l.begin();
}


int last_element_single_direction_efficient(int n, int r) {
	if (n == 1) return 0;
	return (last_element_single_direction_efficient(n - 1, r) + r) % n;
}

int last_element_double_direction(int n, int l, int r) {
	list<int> a_list;
	for (int i = 0; i < n; i++) a_list.push_back(i);
	bool direction = true; // 1 ->, 0 <-.
	int start = 0; 
	while (n > 1) {
		start = direction ? (r - 1 + start) % n : (n - (l % n) + start) % n;
		int index = start;
		auto iter = a_list.begin();
		while (iter != a_list.end() && index--) iter++;
		a_list.erase(iter); --n; direction = !direction;
	}
	return *a_list.begin();
}








