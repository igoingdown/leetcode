class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        string num1, num2;
        while (1) {
            if (!getline(s1, num1, '.')) num1= "0";
            if (!getline(s2, num2, '.')) num2 = '0';
            int v1 = stoi(num1), v2 = stoi(num2);
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            if (s1.eof() && s2.eof()) return 0;
        }
        return 0;
    }
};
