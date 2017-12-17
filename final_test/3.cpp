#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

bool my_compare(pair<double, double> l, pair<double, double> r);
int minimumRaindrops (vector<pair<double, double>> raindrops);

int main(int argc, char const *argv[])
{
    vector<pair<double, double>> v;
    v.push_back(make_pair(0, 0.3));
    v.push_back(make_pair(0.3, 0.6));
    v.push_back(make_pair(0.5, 0.8));
    v.push_back(make_pair(0.67, 1));
    v.push_back(make_pair(0, 0.4));
    cout << minimumRaindrops(v) << endl;
    return 0;
}

bool my_compare(pair<double, double> l, pair<double, double> r) {
    return l.first < r.first;
}

// 暴力解法，逐步增大k，查看前k个area是否能够组成0-1区间
// 题目中的原型好像不太对，这里我稍作改动。
int minimumRaindrops (vector<pair<double, double>> raindrops){
    int n = raindrops.size();
    if (n == 0) return -1;
    for (int i = 1; i <= n; i++) {
        vector<pair<double, double>> tmp(raindrops.begin(), raindrops.begin() + i);
        sort(tmp.begin(), tmp.end(), my_compare);
        double b = tmp[0].first, e = tmp[0].second;
        if (b != 0) continue;
        for (auto p : tmp) {
            if (p.first <= e) {
                e = p.second;
                if (e == 1) return i;
            } else break;
        }
    }
    return -1;
}
