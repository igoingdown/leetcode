#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> twoSum(const vector<int> &nums, int sum);


int main() {
    vector<int> v = {1,2,3,2,2};
    auto res = twoSum(v, 4);
    if (res.size() == 2) {
        cout << res[0] << "_" << res[1] << endl;
    }
    return 0;

}

vector<int> twoSum(const vector<int> &nums, int sum) {
    vector<int> res;
    if (nums.size() < 2) {return res;}
    vector<pair<int, int>> v;

    v.reserve(nums.size());
    for(int i = 0; i < nums.size(); i++) {
        v.emplace_back(nums[i], i);
    }
    sort(v.begin(), v.end());
    
    int l = 0, r = v.size() - 1; 
    while (l < r) {
        int t = v[l].first + v[r].first;
        if (t == sum) {
            break;
        }
        if (t < sum) {l++;} else {r--;}
    }
    if (l < r) {
        res = {v[l].second, v[r].second};
    }
    return res;
}
