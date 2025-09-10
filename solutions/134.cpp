#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int canCompleteCircuit(vector<int>& gas, vector<int>& cost);

int main(int argc, char const *argv[])
{
    /* code */
    int a[4] = {1, 2, 3, 3};
    int b[4] = {2, 1, 5, 1};
    vector<int> v1(a, a + 4);
    vector<int> v2(b, b + 4);
    cout << canCompleteCircuit(v1, v2) << endl;
    return 0;
}


int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    if (n == 0) return -1;
    vector<int> left(n, 0);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        left[i] = gas[i] - cost[i];
        total += left[i];
    }
    if (total < 0) return -1;
    for (int i = 0; i < n; i++) {
        cout << i << " " << endl;
        if (left[i] < 0) continue;
        int sum = left[i], j = i + 1;
        while (j % n != i && sum >= 0) {
            sum += left[j % n];
            j++;
        }
        if (j % n == i && sum >= 0) return i;
        i = j - 1;
    }
    return -1;
}