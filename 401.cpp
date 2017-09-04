class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                bitset<10> bits(i * 64 + j);
                if (bits.count() == num) {
                    string min = to_string(j);
                    if (j < 10) {
                        min = "0" + min;
                    }
                    v.push_back(to_string(i) + ":" + min);
                }
            }
        }
        return v;
    }
};