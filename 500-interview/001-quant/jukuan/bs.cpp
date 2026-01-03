#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int x) {
    if (a.size() == 0) {
        return 0;
    }
    int low = 0, high = a.size() - 1, mid = 0;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (a[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> a = {1,1,2,2,2,3,5};
    // index:        0 1 2 3 4 5 6
    cout << binary_search(a, 0) << endl;  // 0
    cout << binary_search(a, 7) << endl;  // 7
    cout << binary_search(a, 2) << endl;  // 5
    cout << binary_search(a, 4) << endl;  // 6
    return 0;
}
