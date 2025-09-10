class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for (char c : tasks) {
            v[c - 'A']++;
        }
        sort(v.begin(), v.end());
        int i = 25;
        while (i >= 0 && v[i] == v[25]) i--;
        int s = tasks.size();
        return max(s, (n + 1) * (v[25] - 1) + 25 - i);
    }
};