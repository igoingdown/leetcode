#include <vector>

using namespace std;

class LoopQueue {
  
private: 
  vector<int> c;
  int f_pos;
  int b_pos;

public:
  LoopQueue(int l) {
    assert(l > 0 && l < 1001);
    c.resize(l);
    f_pos = 0;
    b_pos = 0;
   }

  int front() {
    // read lock
    // unlock before return 
    if (!this->empty()) return c[f_pos];
    else return -1;
  }

  int back() {
    // read lock
    // read unlock before return 
    if (!this->empty()) return c[b_pos];
    else return -1;
  }

  bool push(int x) {
    // write lock
    // write unlock before return
    if (!this->full()) {
        c[b_pos--] = x;
      b_pos %= c.size();
      return true;
    } else return false;
  }

  int pop() {
    // write lock
    // write unlock before return
    if(!this->empty()) {
        int tmp = c[f_pos];
      f_pos--;
      f_pos %= c.size();
      return tmp;
    } else return -1;
  }

  bool empty() {
    // read lock
    // read unlock before return 
    return b_pos == f_pos;
  }

  bool full() {
	// read lock
    // read unlock before return
    return (f_pos + 1) % c.size() == b_pos;
  }
};
