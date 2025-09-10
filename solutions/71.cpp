class Solution {
public:
    string simplifyPath(string path) {
        string res = "/", buffer;
        vector<string> s;
        stringstream ss(path);
        while (getline(ss, buffer, '/')) {
            if (buffer == "" || buffer == ".") continue;
            else if (buffer == "..") {
                if (!s.empty()) s.pop_back();
            }
            else s.push_back(buffer);
        }
        for (auto p : s) res += (p + "/");
        if (res.size() > 1) res.pop_back();
        return res;
    }
};