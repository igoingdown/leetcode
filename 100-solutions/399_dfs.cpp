class Solution {
private:
    void query(map<string, map<string, float>>& m, pair<string, string> p, int i, vector<double>& res, set<string>& visited) {
        if (m.find(p.first) != m.end()) {
            if (m[p.first].find(p.second) != m[p.first].end()) {
                res[i] = m[p.first][p.second];
                return;
            } else {
                visited.insert(p.first);
                for (auto iter = m[p.first].begin(); iter != m[p.first].end(); iter++) {
                    if (visited.find(iter->first) == visited.end()) {
                        query(m, make_pair(iter->first, p.second), i, res, visited);
                        if (res[i] != -1) {
                            res[i] *= m[p.first][iter->first];
                            m[p.first][p.second] = res[i];
                            m[p.second][p.first] = 1 / res[i];
                            return;
                        }
                    }
                }
            }
        } else {
            return;
        }
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, float> > m;
        for (int i = 0; i < equations.size(); i++) {
            auto p = equations[i];
            m[p.first][p.second] = values[i];
            m[p.first][p.first] = 1.0;
            m[p.second][p.second] = 1.0;
            m[p.second][p.first] = 1 / values[i];
        }
        vector<double> res(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            set<string> visited;
            query(m, queries[i], i, res, visited);
        }
        return res;
    }
};