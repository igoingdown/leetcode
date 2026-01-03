#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2);

int main(int argc, char const *argv[]) {
  /* code */
  string s1("tea"), s2("eat");
  cout << minDistance(s1, s2) << endl;
  return 0;
}

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector <vector<int> > dp(m + 1, vector<int> (n + 1, 0));
    for(int i = m - 1; i >= 0; i--) {
        dp[i][n] = dp[i + 1][n] + 1;
    }
    for (int j = n - 1; j >= 0; j--) {
        dp[m][j] = dp[m][j + 1] + 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int dela = 1 + dp[i + 1][j];
            int delb = 1 + dp[i][j + 1];
            int delab = (word1[i] == word2[j] ? 0 : 2) + dp[i + 1][j + 1];
            dp[i][j] = min(dela, min(delb, delab));
        }
    }
    return dp[0][0];
}
