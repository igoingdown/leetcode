#include <iostream>
#include <string>

using namespace std;

string shortestSubstringWithAllCharacters(string &s);

int main() {
	return 0;
}

// 给定一个字符串，找到包含该字符串所有字符的最短子串
// leetcode 76的简化版
string shortestSubstringWithAllCharacters(string &s) {
	vector<int> freq(256), aMap(256);
	int min_start = 0, min_len = s.size(), count = 0;
	for (char c : s) {
		if (freq[c] == 0) count++;
		freq[c]++;
	}
	for (int j = 0, i = 0; j < s.size(); j++) {
		aMap[s[j]]++;
		if (aMap[s[j]] == 1) count--;
		if (count == 0) {
			while (i <= j) {
				if (min_len > j - i + 1) {
					min_start = i; min_len = j - i + 1;
				}
				if (aMap[s[i]] == 1) break;
				aMap[s[i]]--; i++;
			}
		}
	}
	return s.substr(min_start, min_len);
} 