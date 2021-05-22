#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;




class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < 1 << n; i++) {
            cout << i << " " << (i >> 1) << " " << (i ^ (i >> 1)) << endl;
            res.push_back(i ^ (i >> 1));
        }
        return res;
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


