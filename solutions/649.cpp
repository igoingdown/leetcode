class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1, q2;
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }
        while (!q1.empty() && !q2.empty()) {
            int i1 = q1.front(), i2 = q2.front();
            q1.pop();
            q2.pop();
            if (i1 < i2) q1.push(i1 + n);
            else q2.push(i2 + n);
        }
        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};