#include <iostream>
#include <vector>

using namespace std;

void heap_push(vector<int> &h, int k);

int main() {
	vector<int> v;
	for (int i = 100; i >= 0; i--) heap_push(v, i);
	cout << v[0] << endl;
	return 0;
}


void heap_push(vector<int> &heap, int k) {
	heap.push_back(k);
	int child = heap.size() - 1, parent = (child - 1) / 2;
	while (parent >= 0 && child > 0) {
		if (heap[parent] > heap[child]) {
			// 只需检查child和parent的关系即可,左子和右子的关系不用比较，因为插入之前就是堆结构。
			swap(heap[parent], heap[child]); child = parent; parent = (parent - 1) / 2;
		} else break;
	}
}
