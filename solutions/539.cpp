class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minDiff = INT_MAX, n = timePoints.size();
        for (int i = 0; i < timePoints.size(); i++) {
            int diff = timeDiff(timePoints[(i - 1 + n) % n], timePoints[i]);
            diff = min(diff, 1440 - diff);
            minDiff = min(diff, minDiff);
        }
        return minDiff;
    }
    
    int timeDiff(string t1, string t2) {
        int t1h = stoi(t1.substr(0, 2)), t1m = stoi(t1.substr(3, 2));
        int t2h = stoi(t2.substr(0, 2)), t2m = stoi(t2.substr(3, 2));
        return abs((t1h - t2h) * 60 + (t1m - t2m));
        
    }
};
