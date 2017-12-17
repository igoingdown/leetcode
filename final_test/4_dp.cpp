#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

int calculateMaxMatch(string str, std::vector<string>& dict);
int removeCharacters(string str, vector<string>& dict);


int main(int argc, char const *argv[])
{
    string s = "hellowworld";
    std::vector<string> v;
    v.push_back("hello");
    v.push_back("world");
    cout << removeCharacters(s, v) << endl;
    return 0;
}


int removeCharacters(string str, vector<string>& dict) {
    int l = str.size();
    vector<int> dp(l + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < l + 1; i++) {
        for (int j = 0; j < i; j++) {
            int maxMatch = calculateMaxMatch(str.substr(j, i - j + 1), dict);
            // DP算法的关键
            // dp[i] = min(dp[i], dp[j] + (以i位置结束的子串还原到dict中的一个单词要删掉的最少字符数))
            if (dp[j] != INT_MAX) dp[i] = min(dp[i], dp[j] + i - j - maxMatch);
        }
    }
    return dp[l];
}

// 查看从j到i位置的子串和dict中每个单词是否匹配，匹配规则是删掉一部分，能成为该单词。
int calculateMaxMatch(string str, std::vector<string>& dict) {
    int res = 0;
    for (string word : dict) {
        int m = 0, i = 0, j = 0;
        do {
            if (word[i] == str[j]) {
                i++;
                if (i == word.size()) {
                    m = word.size();
                    break;
                }
            }
            j++;
        } while (j < str.size());
        res = max(res, m);
    }
    return res;
}





