#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	float x = 1.0, y = 2.0, a = 3.0, b = 4.0;
	vector<float> temp;
	vector< vector<float> > v;
	temp.push_back(x);
	temp.push_back(y);
	v.push_back(temp);
	temp.clear();
	temp.push_back(a);
	temp.push_back(b);
	v.push_back(temp);
	for (auto i = v.begin(); i != v.end(); i++) {
		for (auto j = i->begin(); j != i->end(); j++) {
			cout << *j << "\t";
		}
		cout << endl;
	}
	return 0;
}