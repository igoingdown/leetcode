class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        for (string s : cpdomains) {
            istringstream in(s);
            int c; string domain; 
            in >> c >> domain;
            istringstream strm(domain);
            vector<string> v;
            string tmp;
            while (getline(strm, tmp, '.')) v.push_back(tmp);
            for (int i = 0; i < v.size(); ++i) {
                string combine = "";
                for (int j = i; j < v.size(); ++j) combine += v[j] + (j + 1 < v.size() ? "." : "");
                if (m.find(combine) == m.end()) m[combine] = c;
                else m[combine] += c;
            }
        }
        vector<string> res;
        for (auto iter = m.begin(); iter != m.end(); iter++) res.push_back(to_string(iter->second) + " " + iter->first);
        return res;
    }
};