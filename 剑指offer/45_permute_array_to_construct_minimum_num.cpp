#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute_array(vector<int> &arr);
bool myCompare(int a, int b) ;

int main(int argc, char const *argv[])
{
	vector<int> v = {32, 25, 10};
	permute_array(v);
	return 0;
}

void permute_array(vector<int> &arr) {
	sort(arr.begin(), arr.end(), myCompare);
	for (int n : arr) cout << n;
	cout << endl;
}

bool myCompare(int a, int b) {
	string sa = to_string(a), sb = to_string(b), str1 = sa + sb, str2 = sb + sa; 
	return str1 < str2;
}