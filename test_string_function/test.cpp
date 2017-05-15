#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  string s("10.");
  printf("%d\n", s.find('.'));
  printf("%d\n", string::npos);
  return 0;
}
