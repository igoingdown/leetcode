class Solution {
private:
    static bool myCompare(int a, int b) {
        string s1 = to_string(a), s2 = to_string(b);
        return s1 + s2 > s2 + s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return "";
        sort(nums.begin(), nums.end(), myCompare);
        if (nums[0] == 0) return "0";
        string res = "";
        for (int num : nums) res += to_string(num);
        return res;
    }
};