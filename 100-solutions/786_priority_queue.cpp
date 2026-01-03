#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<int> kthSmallestPrimeFraction(vector<int>& A, int K);

vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    priority_queue<pair<double, pair<int, int>>> pq;
    for (int i = 0; i < A.size(); i++) {
        pq.push({-1.0 * A[i] / A.back(), {i, A.size() - 1}});
    }
    while (--K) {
        auto p = pq.top().second;
        pq.pop();
        p.second--;
        pq.push({-1.0 * A[p.first] / A[p.second], p});
    }
    return vector<int> {A[pq.top().second.first], A[pq.top().second.second]};
}

int main() {
    vector<int> nums{1,2,3,5};
    auto res = kthSmallestPrimeFraction(nums, 3);
    printf("%d/%d\n", res[0], res[1]);
}


