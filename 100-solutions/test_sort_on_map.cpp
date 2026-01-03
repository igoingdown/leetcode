#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	unordered_map<int, int> v;
	v[1] = 10;
	v[3] = 20;
	v[-1] = 20;
	sort(v.begin(), v.end());
	for (auto p: v) {
		cout << p.first << endl;
	}
	return 0;
}