#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> res_set;
        f(res, res_set, n, 0);
        return res;
    }

    void f(vector<int>& res, unordered_set<int>& res_set, int n, int num) {
        if (res.size() == pow(2, n)) {
            return;
        }
        if (res_set.find(num) != res_set.end()) {
            return;
        }
        res.push_back(num);
        if (res.size() == pow(2, n)) {
            return;
        }
        res_set.insert(num);
        for (auto i = 0; i < n; i++) {
            f(res, res_set, n, num ^ (1 << i));
        }
    }
};


int main() {
    Solution s;
    auto res = s.grayCode(2);
    for (auto n : res) {
        cout << n << endl;
    }
    return 0;
}


