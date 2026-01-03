#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> kthSmallestPrimeFraction(vector<int>& A, int K);


vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    double low = 0, high = 1, mid;
    for (int n = A.size(), cnt = 0, p = 0, q = 1; true; cnt = 0, p = 0) {
        mid = (low + high) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n && (A[j] + 0.0) / A[i] < mid; j++) {
                cnt += 1;
                if ((p + 0.0) / q <  (A[j] + 0.0) / A[i]) {
                    p = A[j];
                    q = A[i];
                }
            }
        }
        if (cnt == K) return vector<int> {p, q};
        else if (cnt < K) low = mid;
        else high = mid;
    }
}


int main() {
	vector<int> nums{1,7,23,29,47};
	auto res = kthSmallestPrimeFraction(nums, 8);
	printf("%d/%d\n", res[0], res[1]);
}