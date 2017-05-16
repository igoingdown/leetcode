#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s);

int main(int argc, char const *argv[]) {
  /* code */
  string s("hi jack!");
  reverseWords(s);
  cout << s << endl;
  return 0;
}


void reverseWords(string &s) {
  reverse(s.begin(), s.end());
      int idx = 0;
      for (int i = 0; i < s.size(); i++) {
          if (s[i] != ' ') {
              if(idx != 0) {
                  s[idx++] = ' ';
              }
              int j = i;
              while (j < s.size() && s[j] != ' ') {
                  s[idx++] = s[j++];
              }
              reverse(s.begin() + idx - (j - i), s.begin() + idx);
              i = j;
          }
      }
      s.erase(s.begin() + idx, s.end());
}
