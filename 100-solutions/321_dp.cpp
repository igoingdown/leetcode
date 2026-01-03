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

string combineNums(string x, string y) {
        string result = "";
        int i = 0, j = 0;
        while (i< x.size() && j < y.size()) {
               bool x_big = true;
                int a = i, b = j;
                while (a < x.size() && b < y.size()) {
                    if (x[a] > y[b]) {
                        break;
                    } else if (x[a] < y[b]) {
                        x_big = false;
                        break;
                    } else {
                        a++;
                        b++;
                    }
                }
                if (a == x.size()) {
                    x_big = false;
                }
                if (x_big) {
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
            cout << "nums:"<< maxNums1[i][m]  << " " << maxNums2[k-i][n] << endl;
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

        vector<int> a={8,1,8,8,6};
        vector<int> b={4};
        for (auto i: maxNumber(a,b,2)) {
            cout << i << " ";
        }
        cout << endl;
}
