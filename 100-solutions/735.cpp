class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        if (asteroids.size() == 0) return asteroids;
        for (int i = 0; i < asteroids.size(); i++) {
            if (s.empty()) s.push(asteroids[i]);
            else {
                if (s.top() > 0 && asteroids[i] < 0){
                    while (!s.empty() && s.top() > 0 && asteroids[i] < 0 && abs(s.top()) < abs(asteroids[i])) s.pop();
                    if (s.empty()) s.push(asteroids[i]);
                    else {
                        if (s.top() > 0) {
                            if (abs(s.top()) == abs(asteroids[i])) s.pop();
                        } else s.push(asteroids[i]);
                    }
                } else {
                    s.push(asteroids[i]);
                }
            }
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};