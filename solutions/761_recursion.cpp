class Solution {
public:
    string makeLargestSpecial(string S) {
        vector<string> specials, res;
        int cnt = 0;    
        for (char c : S) {
            if (cnt == 0) specials.push_back("");
            cnt += (c == '1' ? 1 : -1);
            specials.back() += c;
        }
        for (string s : specials) {
            int ss = s.size();
            res.push_back("1" + makeLargestSpecial(s.substr(1, ss - 2)) + "0");
        }
        sort(res.begin(), res.end(), greater<string>());
        string ret = "";
        for (string & s : res) ret += s;
        return ret;
    }
};