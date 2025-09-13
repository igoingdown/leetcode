#include <iostream>
#include<vector>

using namespace std;


void q_sort(vector<int>& nums, int left, int right);
int partition(vector<int>& nums, int left, int right);
void print_vector(const vector<int>& nums);

int main(void) {
    // 测试用例
    vector<int> test1 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> test2 = {5, 2, 8, 1, 9};
    vector<int> test3 = {1};
    vector<int> test4 = {};
    vector<int> test5 = {3, 3, 3, 1, 2, 2};
    
    cout << "测试用例1: ";
    print_vector(test1);
    q_sort(test1, 0, test1.size() - 1);
    cout << "排序结果: ";
    print_vector(test1);
    cout << endl;
    
    cout << "测试用例2: ";
    print_vector(test2);
    q_sort(test2, 0, test2.size() - 1);
    cout << "排序结果: ";
    print_vector(test2);
    cout << endl;
    
    cout << "测试用例3: ";
    print_vector(test3);
    q_sort(test3, 0, test3.size() - 1);
    cout << "排序结果: ";
    print_vector(test3);
    cout << endl;
    
    cout << "测试用例4: ";
    print_vector(test4);
    if (!test4.empty()) {
        q_sort(test4, 0, test4.size() - 1);
    }
    cout << "排序结果: ";
    print_vector(test4);
    cout << endl;
    
    cout << "测试用例5: ";
    print_vector(test5);
    q_sort(test5, 0, test5.size() - 1);
    cout << "排序结果: ";
    print_vector(test5);
    cout << endl;
    
    return 0;
}

void print_vector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void q_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int n = partition(nums, left, right);
        q_sort(nums, left, n - 1);
        q_sort(nums, n + 1, right);
    }
}

int partition(vector<int> &nums, int left, int right) {
    int i = left, j = right, pivot = nums[left];  // i指向小于pivot的最后一个元素
    while (i < j) {
        while (nums[j] >= pivot) j--;
        if (i < j ) nums[i++] = nums[j];
        while (nums[i] < pivot) i++;
        if (i < j) nums[j--] = nums[i];
    }
    nums[i] = pivot;
    return i;
}

