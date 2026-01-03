class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        for (int i = 0; i < n; i++) {
            num.push_back(i + 1);
        }
        list<int> fact;
        fact.push_back(1);
        for (int i = 1; i < n; i++) {
            fact.push_back(i * fact.back());
        }
        string res;
        k--;
        for(int i = n; i > 0; i--) {
            int ind = k / fact.back();
            k %= fact.back();
            fact.pop_back();
            res += to_string(num[ind]);
            num.erase(num.begin() + ind);
        }
        return res;
    }
};
