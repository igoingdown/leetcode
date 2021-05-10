#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> a, b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	b.push_back(8);
	b.push_back(9);
	
	
	a.insert(a.begin(), b.begin(), b.end());

	for (auto i: a) {
		cout << i << endl;
	}
	return 0;
}
