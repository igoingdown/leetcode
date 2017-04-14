class Solution {
private:
    string str = "guwxfhsio";
    
public:
    
    string originalDigits(string s) {
        unordered_map<char, int> m;
        for (char c: str) {
            m[c] = 0;
        }
        for (char c: s) {
            m[c]++;
        }
        vector<int> res(10, 0);
        res[8] = m['g'];
        res[4] = m['u'];
        res[2] = m['w'];
        res[6] = m['x'];
        res[0] = m['z'];
        res[5] = m['f'] - res[4];
        res[3] = m['h'] - res[8];
        res[7] = m['s'] - res[6];
        res[9] = m['i'] - res[5] - res[6] - res[8];
        res[1] = m['o'] - res[2] - res[4] - res[0];
        string resStr;
        for (int i = 0; i < 10; i++) {
            if (res[i] > 0) {
                string temp(res[i], char(i + '0'));
                resStr += temp;
            }
        }
        return resStr;
    }
};
