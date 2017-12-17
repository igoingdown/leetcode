#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

bool canContruct(string& s, vector<string>& dict, int start);
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


// dfs查看当前str能否由dict中的单词组成
bool canContruct(string& s, vector<string>& dict, int start) {
    if (s.size() == start) return true;
    for (int i = start; i < s.size(); i++) {
        if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && canContruct(s, dict, i + 1)) return true;
    }
    return false;
}

// DFS, 本步查看当前str能否由dict单词组成，如果可以返回0，如果不可以，遍历str，str变为除去一个字符之后的str，递归，如果都不行，返回-1
int removeCharacters(string str, vector<string>& dict){
    int l = str.size();
    if (l == 0) return 0;
    if (canContruct(str, dict, 0)) return 0;
    int res = l;
    for (int i = 0; i < l - 1; i++) {
        string tmp = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
        int r = removeCharacters(tmp, dict);
        if (r != -1) res = min(res, r + 1);
    }
    return res == l ? -1 : res;
}


