#include<vector>
#include<algorithm>

using namespace std;

int maxLenSubstring(string &s);

int main() {
    return 0;
}

int maxLenSubstring(string &s) {
    int res = 0, start = 0;
    vector<int> pos(256, -1);
    for (int i = 0; i < s.size(); i++) {
        if (pos[s[i]] >= start) {  // 修复：检查重复字符是否在当煎窗口内
            start = pos[s[i]] + 1;  // 修复：移动到重复字符的下一个位置
        } 
        pos[s[i]] = i;
        res = max(res, i - start + 1);
    }
    return res;
}
