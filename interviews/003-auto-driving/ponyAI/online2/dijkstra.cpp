#include <iostream>
#include <vector>
#include <set>

using namespace std;


int shortPath(vector<vector<int>> &matrix, pair<int, int> x, pair<int, int> y) {
  int m = matrix.size(), n;
  if (m == 0) return 0;
  n = matrix[0].size();
  vector<long long> q(m * n, LL_MAX);
  q[x.first * n + x.second] = 0;
  
  set<int> visited;
  visited.insert(x.first * n + x.second);
  int[5] bias={1, 0, -1, 0, 1};
  
  int cur = x.first * n + x.second;
  while (cur / n != y.first && cur % n != y.second) {
    int minP = -1;
    for (int i = 0; i < m * n; i++) {
      if (canArrive(make_pair(cur/n, cur %n), make_pair(i / n, i %n), bias) {
        q[i] = min(q[cur] + matrix[cur/n][cur%n], q[i]);
        if (visited.find(i) == visited.end()) {
            if (minP < 0) minP = i;
          else {
            minP = q[minP] > q[i] ? i : minP; 
          }
        }
      }
    }
    cur = minP;
  }
  return q[y.first * n + y.second];
} 


bool canArrive(pair<int, int>x, pair<int, int> y, int *bias) {
  for (int i = 0; i < 4; i++) {
    if (x.first + bias[i] >= 0 && x.first + bias[i] < m  && x.first + bias[i] == y.first && x.second + bias[i + 1] >= 0 && x.second + bias[i+ 1] < n && x.second + bias[i + 1] == y.second) return true;
  }
  return false;
}
