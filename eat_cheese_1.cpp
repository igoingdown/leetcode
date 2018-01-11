#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

double eatCheese(vector<pair<double, double>>& cheeses);
void dfs(int len, vector<pair<double, double>>& cheeses, double sum, pair<double, double>& start, double& ans, vector<bool>& visit);
int main() {
    vector<pair<double, double>> v;
    v.push_back(pair<double, double>(1.0, 1.0));
    v.push_back(pair<double, double>(2.0, 2.0));
    v.push_back(pair<double, double>(3.0, 3.0));
    cout << eatCheese(v) << endl;
    return 0;
}

double eatCheese(vector<pair<double, double>>& cheeses) {
    pair<double, double> start = {0, 0};
    vector<bool> visit(cheeses.size(), false);
    double ans = 0x7f7f7f7f;
    dfs(1, cheeses, 0.0, start, ans, visit);
    return ans;
}

void dfs(int len, vector<pair<double, double>>& cheeses, double sum, pair<double, double>& start, double& ans, vector<bool>& visit) {
    if (len > cheeses.size()) {
        ans = min(ans, sum);
        return;
    }
    if (sum > ans) return;
    for (int i = 0; i < cheeses.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            double d = sqrt((start.first - cheeses[i].first) * (start.first - cheeses[i].first) +
                            (start.second - cheeses[i].second) * (start.second - cheeses[i].second));
            dfs(len + 1, cheeses, sum + d, cheeses[i], ans, visit);
            visit[i] = false;
        }
    }
}
