#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s);

int main(int argc, char const *argv[]) {
  /* code */
  string s = "cbbd";
  cout << longestPalindrome(s) << endl;
  return 0;
}


string longestPalindrome(string s) {
  if (s.size() < 2) {
    return s;
  }
  int min_start = 0, max_len = 1;
  for (int i = 0; i < s.size();) {
    int k = i, j = i;
    while (k < s.size() - 1 && s[k + 1] == s[k]) {
      k++;
    }
    i = k + 1;
    while (k < s.size() - 1 && j >= 0 && s[k + 1] == s[j - 1]) {
      k++;
      j--;
    }
    if (k - j + 1 > max_len) {
      min_start = j;
      max_len = k - j + 1;
    }
  }
  return s.substr(min_start, max_len);
}
