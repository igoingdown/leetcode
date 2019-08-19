string find(string s, map<string, string> &parents) {
    if (s == parents[s]) return s;
    else {
        parents[s] = find(parents[s], parents);
        return parents[s];
    }
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> parents, owner;
        for (auto &personAccounts : accounts) {
            string person = personAccounts[0];
            for (int i = 1; i < personAccounts.size(); i++) {
                parents[personAccounts[i]] = personAccounts[i];
                owner[personAccounts[i]] = person;
            }
        }
        for (auto &personAccounts : accounts) {
            int n = personAccounts.size();
            if (n < 2) continue;
            string firstParent = find(personAccounts[1], parents);
            for (int i = 2; i < personAccounts.size(); i++) {
                parents[find(personAccounts[i], parents)] = firstParent;
            }
        }
        map<string, set<string>> m;
        for (auto &p: owner) {
            parents[p.first] = find(p.first, parents);
            m[parents[p.first]].insert(p.first);
        }
        vector<vector<string>> res;
        for (auto &p : m) {
            res.push_back({owner[p.first], });
            for (auto &s: p.second) res.back().push_back(s);
        }
        return res;
    }
};
