class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> mins = {600, 60, 10, 1};
        int cur = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        string next = "0000";
        int j = 0;
        for (int i = 1; i <= 1440 && j < 4; i++) {
            int n = (cur + i) % 1440;
            for (j = 0; j < 4; j++) {
                next[j] = n / mins[j] + '0';
                n %= mins[j];
                if (time.find(next[j]) == string::npos) {
                    break;
                }
            }
        }
        return next.substr(0, 2) + ":" + next.substr(2, 2);
    }
};