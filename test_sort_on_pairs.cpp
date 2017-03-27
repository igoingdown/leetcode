#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	std::vector<pair<int, int> > v;
	v.push_back(make_pair(1, 10));
	v.push_back(make_pair(2, 10));
	v.push_back(make_pair(-2, 10));
	sort(v.begin(), v.end());
	for (auto p: v) {
		cout << p.first << endl;
	}
	return 0;
}