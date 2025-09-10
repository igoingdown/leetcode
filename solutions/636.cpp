class Solution {

public:
    struct Log {
        int id;
        string status;
        int t;
    };
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<Log> s;
        for (string str : logs) {
            stringstream ss(str);
            string t1, t2, t3;
            getline(ss, t1, ':');
            getline(ss, t2, ':');
            getline(ss, t3, ':');
            Log log = {stoi(t1), t2, stoi(t3)};
            if (log.status == "start") {
                s.push(log);
            } else {
                if (s.top().id == log.id) {
                    int time = log.t - s.top().t + 1;
                    res[log.id] += time;
                    s.pop();
                    if (!s.empty() && s.top().status == "start") {
                        res[s.top().id] -= time;
                    }
                }
            }
        }
        return res;
    }
};