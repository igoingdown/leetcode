class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> mini(triangle[n - 1]);
        for (int layer = n - 2; layer >= 0; layer--) {
            for (int i = 0; i <= layer; i++) {
                // cout << layer << " "  << i << endl;
                mini[i] = min(mini[i], mini[i + 1]) + triangle[layer][i];
            }
        }
        return mini[0];
    }
};
