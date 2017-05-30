class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string buf;
        stringstream ss(path);
        while (getline(ss, buf, '/')) {
            if (buf == "." || buf == "") {
                continue;
            }
            if (buf == ".." && !stk.empty()) {
                stk.pop_back();
            }else if (buf != "..") {
                stk.push_back(buf);
            }
        }
        string res;
        for (auto s: stk) {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};
