#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

struct cmpByKeyLength {
    bool operator() (const string& s1, const string& s2) {
        return s1.size() > s2.size();
    }
};

bool s1IsSubstrOfS2(const string& s1, const string& s2);
int findLUSlength(vector<string>& strs);

int main(void) {
    vector< string > strs{"aba", "cdc", "eae"};
    cout << findLUSlength(strs) << endl;
    return 0;
}


int findLUSlength(vector<string>& strs) {
    map< string, int, cmpByKeyLength > m;
    for (auto s: strs) {
        m[s]++;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) {
            auto jit = m.begin();
            for (; jit != it; jit++) {
                if (s1IsSubstrOfS2(it->first, jit->first)) {
                    break;
                }
            }
            if (jit->first == it->first) {
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
    
    