#include <iostream>
#include <string>

using namespace std;


bool repeatedSubstringPattern(string s);


int main(void) {
  string s = "aaaaaaaaaaaaaaaaaaaaa";
  if (repeatedSubstringPattern(s)) {
    cout << "true" << endl;
  } else {
    cout << "hehe" << endl;
  }
  return 0;
}


bool repeatedSubstringPattern(string s) {
  cout << "why" << endl;
  if (s.size() < 2) {
    return false;
  }
  for(int i = 2; i <= s.size(); i++) {
    if (s.size() % i != 0) {
      continue;
    }
    cout << "i: " << i << endl;
    int subSize = s.size() / i;
    string subStr = s.substr(0, subSize);
    string tmp;
    for (int i = 0; i < s.size() / subSize; i++) {
      tmp += subStr;
    }
    if (tmp == s) {
      return true;
    }
  }
  return false;
}
