class myCmp {
public:
    bool operator() (tuple<int, int, int> &a, tuple<int, int, int> &b) {
        return get<0>(a) >  get<0>(b);
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, myCmp> q;
        for (int i = 0; i < nums1.size(); i++) {
            q.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> res;
        while (!q.empty() && k--) {
            auto [sum, i,j ] = q.top(); 
            q.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {
                q.push({nums1[i]+nums2[j+1], i, j+1});
            }
        }
        return res;
    }
};