#include <iostream>
#include <vector>

using namespace std;

int main() {
	return 0;
}


// 平面上N个点，没两个点都确定一条直线，求出斜率最大的那条直线所通过的两个点（斜率不存在的情况不考虑）

// 先把N个点按x排序。
// 斜率k最大值为max(斜率(point[i],point[i+1])) 0<=i<n-2。
// O(Nlog(N)。

// 任意三个点可以组成一个三角形，斜率最大的直线一定是由两个相邻的点画出的。
pair<pair<float, float>, pair<float, float>> max_k_line(vector<pair<float, float>> &points) {
	sort(points.begin(), points.end(), [](pair<float, float> a, pair<float, float> b) {return a.first < b.first;});
	int max_start = 0;
	float max_k = -inf;
	for (int i = 0; i < points.size() - 1; i++) {
		float k = (points[i].second - points[i + 1].second) / (points[i].first - points[i + 1].first);
		if (k > max_k) {
			max_k = k; max_start = i; 
		}
	}
	return {points[max_start], points[max_start + 1]};
}

