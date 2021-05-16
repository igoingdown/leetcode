#include <iostream>
#include <vector>

using namespace std;

string vec2str(vector<int>& nums, int n) {
        if (n > nums.size()) {
            return  "";
        }
        string result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i] + '0');
        }
        return result;
    }

string maxStr(string s1, string s2) {
    if (s1.size() < s2.size()) {
        return s2;
    }
    return max(s1, s2);
}


void maxNum(vector<vector<string>>& result, vector<int>& nums, int n) {
        for (int i = 1; i <= n; i++) {
            result[i][i] = vec2str(nums, i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                result[i][j] = max(result[i][j-1], result[i-1][j-1] + to_string(nums[j-1]));
            }
        }
    }


void chooseNum(vector<vector<bool>>& mat, string s1, string s2) {
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] > s2[j - 1]) {
                mat[i][j] = true;
            }
        }
    }
    for (int i = s1.size() ; i > 0; i--) {
        for (int j = s2.size(); j > 0; j--) {
            if (s1[i-1] != s2[j-1]) {
                continue;
            }
            if (i < s1.size() && j < s2.size()){
                mat[i][j] = mat[i+1][j+1];
            }
            if (i == s1.size() && j < s2.size()) {
                mat[i][j] = false;
            }
            if (i < s1.size() && j == s2.size()) {
                mat[i][j] = true;
            }
        }
    }

    cout << "\n" << "nums:"<< s1  << " " << s2 << endl;
    for (int i = 0; i <= s1.size(); i++) {
        cout << "row " << i << ":";
        for (int j = 0; j <= s2.size(); j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}


string combineNums(string x, string y) {
    string result = "";
    vector<vector<bool>> chooseX(x.size() + 1, vector<bool>(y.size()+1, false));
    chooseNum(chooseX, x, y);
    int i = 0, j = 0;
    while (i< x.size() && j < y.size()) {
        cout << "compare" << i+1 << " " << j+1 << " " << chooseX[i+1][j+1] << endl;
        if (chooseX[i+1][j+1]) {
            result.push_back(x[i++]);
        } else {
            result.push_back(y[j++]);
        }
    }
    while (i < x.size()) {
        result.push_back(x[i++]);
    }
    while (j < y.size()) {
        result.push_back(y[j++]);
    }
    return result;
}

vector<int> str2vec(string num) {
    vector<int> result;
    for (char c : num) {
        result.push_back(c - '0');
    }
    return result;
}


vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<string>> maxNums1(m+1, vector<string>(m+1, ""));
    vector<vector<string>> maxNums2(n+1, vector<string>(n+1, ""));

    maxNum(maxNums1, nums1, m);
    for (int i =0; i<= m; i++) {
        cout << i << " ";
        for (auto s : maxNums1[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    maxNum(maxNums2, nums2, n);

    for (int i =0; i<= n; i++) {
        cout << i << " ";
        for (auto s : maxNums2[i]) {
            cout << s << " ";
        }
        cout << endl;
    }

    string result;
    for (int i = 0; i <= k && i <= m; i++) {
        if ((k - i) > n) {
            continue;
        }
        auto t = combineNums(maxNums1[i][m], maxNums2[k-i][n]);
        result = maxStr(result, t);
    }


    return str2vec(result);
}
    
        
        
int main() {
    vector<vector<string>> mat(5, vector<string>(5,""));
    vector<int> nums = {3,5,2,4};
    cout << combineNums("67", "604") << endl;
    maxNum(mat, nums, nums.size());
    for (auto &v : mat) {
        for (auto i : v) {
            cout << i << "\t";
        }
        cout << endl;
    }


    // vector<int> a={6,3,9,0,5,6};
    // vector<int> b={2,2,5,2,1,4,4,5,7,8,9,3,1,6,9,7,0};
    // for (auto i: maxNumber(a,b,23)) {
    vector<int> a={3,4,6,5};
    vector<int> b={9,1,2,5,8,3};
    for (auto i: maxNumber(a,b,5)) {
        cout << i << " ";
    }
    cout << endl;
}
