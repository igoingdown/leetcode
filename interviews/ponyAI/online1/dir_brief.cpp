// 在线面试平台。将链接分享给你的朋友以加入相同的房间。
// Author: tdzl2003<dengyun@meideng.net>
#include <iostream>
#include <stack>

using namespace std;

string cd(string cur, string target) {
  stack<string> stk;
  vector<string> v = split(cur), t = split(target);
  for (string &s: v) {
   stk.push(s);
  }
  
  for (string &s : t) {
   if (s == ".." && !stk.empty()) {
     stk.pop();
    } else if (s != "." && s!= "..") {
     stk.push(s);
    }
  }
  string res = "";
  while (!stk.empty()) {
   res = stk.top() + "/" + res;
  }
  return "/" + res;
} 


vector<string> split(string s) {
 vector<string> v;
  string dir = "";
  for (char c : s) {
   if (c == '/') {
     v.push_back(dir);
      dir = "";
    } else {
     dir.push_back(c);
    }
  }
  if (dir != "") v.push_back(dir);
  return v;
}

int main() {
	cout << cd("/PONY/", "../../aa/")
}
