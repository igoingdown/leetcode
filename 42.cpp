#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int trap(vector<int>& height);

int main(int argc, char const *argv[])
{
	/* code */
	int a[4] = {2, 1, 0, 2};
	vector<int> v(a, a + 4);
	cout << trap(v) << endl;
	return 0;
}

int trap(vector<int>& height) {
    stack<int> s;
    int res = 0, i = 0;
    while (i < height.size()) {
        if (s.empty() || height[i] <= height[s.top()]) {
            s.push(i++);
        } else {
            int bot = height[s.top()];
            s.pop();
            res += s.empty() ? 0 : (min(height[s.top()], height[i]) - bot) * (i - s.top() - 1);
        }
    }
    return res;
}