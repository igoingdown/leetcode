#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> strs{"sat", "tas", "eat", "tea"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto v: res) {
        for (auto s: v) {
            cout << s;
        }
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>, vector<string>> m;
    vector<int> temp(26, 0);
    for (auto s: strs) {
        for (auto c: s) {
            temp[c - 'a']++;
        }
        m[temp].push_back(s);
    }
    vector<vector<string>> res;
    for (auto i = m.begin(); i != m.end(); i++) {
        res.push_back(i->second);
    }
    return res;
}

