#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool s1IsSubstrOfS2(const string& s1, const string& s2);
int findLUSlength(vector<string>& strs);
bool myCompare(const pair<string, int> &p1, const pair<string, int>& p2);

int main(void) {
    vector< string > strs{"aabbcc", "aabbcc", "abc", "cb"};
    cout << findLUSlength(strs) << endl;
    return 0;
}

bool myCompare(const pair<string, int> &p1, const pair<string, int>& p2) {
    return p1.first.size() > p2.first.size();
}

int findLUSlength(vector<string>& strs) {
    map< string, int> m;
    for (auto s: strs) {
        m[s]++;
    }
    vector< pair< string, int > > vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), myCompare);
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it->second == 1) {
            auto jit = vec.begin();
            for (; jit != it; jit++) {
                if (s1IsSubstrOfS2(it->first, jit->first)) {
                    break;
                }
            }
            if (jit->first == it->first) {
                cout << jit->first << endl;
                return it->first.size();
            }
        }
    }
    return -1;
}


bool s1IsSubstrOfS2(const string& s1, const string& s2) {
    for (int i = 0, j = 0; i < s1.size(); i++) {
        while (s2[j] != s1[i] && j < s2.size()) {
            j++;
        }
        if (j == s2.size()) {
            cout << s1 << " " << s2 << endl;
            return false;
        }
        j++;
    }
    return true;
}
    
    