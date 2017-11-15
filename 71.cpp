class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string str;
        stack<string> s;
        while(getline(ss, str, '/')) {
            if (str == ".") continue;
            else if (str == "..") {
                if (!s.empty()) s.pop();
            } else {
                if (str != "") s.push(str);
            }
        }
        string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res == "" ? "/" : res;
    }
};