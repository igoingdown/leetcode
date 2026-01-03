#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<pair<int, int>> v = {{1, 6}, {2, 5}, {3, 4}};
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
	for (auto p: v) cout << p.first << endl;
	return 0;
}