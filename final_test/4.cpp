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
    
    return 0;
}


// dfs查看当前str能否由dict中的单词组成
bool canContruct(string& s, vector<string>& dict, int start) {
    if (s.size() == start) return false;
    for (int i = start; i < s.size(); i++) {
        if (find(dict.begin(), dict.end(), s.substr(start, i - start + 1)) != dict.end() && canContruct(s, dict, i + 1)) return true;
    }
    return false;
}

// DFS, 本步查看当前str能否由dict单词组成，如果可以返回0，如果不可以，遍历str，str变为除去一个字符之后的str，递归，如果都不行，返回-1
int removeCharacters(string str, vector<string>& dict){
    if (str.size() == 0) return 0;
    if (canContruct(str, dict, 0)) return 0;
    for (int i = 0; i < str.size(); i++) {
        string tmp = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
        int r = removeCharacters(tmp, dict)
        if (r != -1) return r + 1;
    }
    return -1;
}

