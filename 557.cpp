class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 2) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            // cout << i << endl;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            for (int k = 0; k < (j - i) / 2; k++) {
                char temp = s[i + k];
                s[i + k] = s[j - 1 - k];
                s[j - 1 - k] = temp;
                // swap(s[i + k], s[j - 1 - k]);
            }
            // cout << s << endl;
            i = j;
        }
        return s;
    }
};
