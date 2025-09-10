#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <regex>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;
vector<string> subdomainVisits(vector<string>& cpdomains);
double soupServings(int N);
double dfs(int a, int b, map<pair<int, int>, double> &m);
double bfs(int N);
double dp(int N);

int main() {
    int n;
    while (cin >> n) cout << soupServings(n) << endl;
    return 0;
}



double soupServings(int N) {
    map<pair<int, int>, double> m;
    return dfs(N, N, m);
}

double bfs(int N) {
    pair<int, int> p = {N, N};
    queue<pair<int, int>> q, next;
    q.push(p);
    int layer = 0; double prob = 0.0;
    while (!q.empty()) {
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.first == 0) {
                double tmp = pow(0.25, layer);
                prob += tmp * (cur.second == 0 ? 0.5 : 1);
            } else if (cur.first > 0 && cur.second > 0) {
                next.push({cur.first <= 100 ? 0 : cur.first - 100, cur.second});
                next.push({cur.first <= 75 ? 0 : cur.first - 75, cur.second <= 25 ? 0 : cur.second - 25});
                next.push({cur.first <= 50 ? 0 : cur.first - 50, cur.second <= 50 ? 0 : cur.second - 50});
                next.push({cur.first <= 25 ? 0 : cur.first - 25, cur.second <= 75 ? 0 : cur.second - 75});
            }
        }
        swap(q, next); ++layer;
    }
    return prob;
}


double dfs(int a, int b, map<pair<int, int>, double> &m) {
    if (a == 0) return b == 0 ? 0.5 : 1.0;
    if (b == 0) return 0.0;
    if (m.find({a,b}) != m.end()) return m[{a, b}];

    return  m[{a,b}] = 0.25 * (dfs(a <= 100 ? 0 : a - 100, b, m) + dfs(a <= 75 ? 0:a-75, b <= 25 ? 0 : b - 25, m) + dfs(a <= 50 ? 0 : a - 50, b <= 50 ? 0 : b - 50, m) + dfs(a <= 25 ? 0 : a-25, b <= 75 ? 0 : b - 75, m));
}

double dp(int N) {
    vector<vector<double>> dp(N / 25 + 1, vector<double> (N / 25 + 1));
    dp[0][0] = 0.5;
    for (int j = 1; j <= N / 25; j++) dp[0][j] = 1;
    for (int i = 1; i <= N / 25; i++) {
        for (int j = 1; j <= N / 25; j++) dp[i][j] = 0.25 * (dp[i < 4 ? 0 : i - 4][j] + dp[i < 3 ? 0 : i - 3][j < 1 ? 0 : j - 1] + dp[i < 2 ? 0 : i - 2][j < 2 ? 0 : j - 2] + dp[i < 1 ? 0 : i - 1][j < 3 ? 0 : j - 3]);
    }
    return dp[N/25][N/25];
}


