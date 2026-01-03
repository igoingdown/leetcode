class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> r;
        for (auto s: ops) {
            if (s == "C") {
                r.pop_back();
            } else if (s == "D") {
                r.push_back(r.back() * 2);
            } else if (s == "+") {
                r.push_back(r.end()[-2] + r.end()[-1]);
            } else {
                r.push_back(stoi(s));
            }
        }
        return accumulate(r.begin(), r.end(), 0);
    }
};