#include <ctime>
#include <iostream>
#include <sys/time.h>

using namespace std;

int main(int argc, char const *argv[]) {
  struct timeval t_start;
  gettimeofday(&t_start, NULL);
  cout << t_start.tv_sec << endl;
  cout << t_start.tv_usec << endl;
  long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000;
  cout << start << endl;
  return 0;
}
