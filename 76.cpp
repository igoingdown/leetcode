#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string minWindow(string s, string t);

int main(int argc, char const *argv[])
{
    /* code */
    string s("ab"), t("b");
    cout << minWindow(s, t) << endl;
    return 0;
}

string minWindow(string s, string t) {
    vector<int> window(256, 0), pattern(256, 0);
    for (char c : t) pattern[c]++;
    int count = t.size(), min_len = s.size() + 1, start = 0, end = 0, min_start = 0, min_end = 0;
    window[s[0]]++;
    if (pattern[s[0]] >= 1) count--;
    bool included = false;
    while (1) {
        if (count == 0) {
            included = true;
            while (window[s[start]] > pattern[s[start]]) window[s[start++]]--;
            if (min_len > end - start + 1) {
                min_len = end - start + 1;
                min_start = start;
                min_end = end;
            }
        }
        if (end < s.size() - 1) {
            window[s[++end]]++;
            if (pattern[s[end]] >= window[s[end]]) count--;
        } else break;
    }
    return included ? s.substr(min_start, min_end - min_start + 1) : "";
}