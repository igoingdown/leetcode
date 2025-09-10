#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution {
private:
    int n, max_num;
    vector<int> B;
public:
    Solution(int N, vector<int> blacklist) {
        n = N;
        B = blacklist;
        sort(B.begin(), B.end());
        max_num = N - B.size();
    }
    
    int pick() {
        int i = rand() % max_num;
        int low = 0, high = n, mid, index;
        while (low < high) {
            mid = low + ((high - low) >> 1);
            index = mid;
            auto iter = upper_bound(B.begin(), B.end(), mid);
            if (iter != B.begin()) index -= iter - B.begin();
            if (index < i) low = mid + 1;
            else if (index > i) high = mid - 1;
            else if (iter != B.end() && (*iter == mid)) low = mid + 1;
            else return mid;
        }
        return low; 
    }
};


int main() {
    Solution s(3, vector<int>{1});
    for (int i = 0; i < 10; i++) {
        printf("%d\n", s.pick());
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
