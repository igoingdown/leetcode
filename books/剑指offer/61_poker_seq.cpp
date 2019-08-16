#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool is_poker_seq(const vector<int> &v);

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> v = {0, 0, 2, 4, 6};
	if (is_poker_seq(v)) cout << "Y" << endl;
	else cout << "N" << endl; 
	return 0;
}


bool is_poker_seq(const vector<int> &poker) {
	multiset<int> s;
	for (int p : poker) s.insert(p);
	int start = 1;
	while (start < 14 && s.find(start) == s.end()) ++start;
	cout << start << endl;
	for (int i = start; i < start + 5; i++) {
		if (i > 13) i %= 13;
		if (s.find(i) != s.end()) s.erase(i);
		else if(s.find(0) != s.end()) s.erase(s.find(0));
		else return false;
	}
	return s.empty();
}