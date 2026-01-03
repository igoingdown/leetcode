#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 函数声明
void sort(vector<int> &nums);
void merge_sort(vector<int> &nums, int left, int right);
void merge(vector<int> &nums, int left, int mid, int right);
void print_array(const vector<int> &nums, const string &label);
void test_sort();

/**
 * 主函数 - 执行测试用例
 */
int main() {
    test_sort();
    return 0;
}

/**
 * 归并排序入口函数
 * @param nums 待排序的整数数组
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void sort(vector<int> &nums) {
    if (nums.size() <= 1) {
        return;
    }
    merge_sort(nums, 0, nums.size() - 1);
}

/**
 * 递归实现归并排序
 * @param nums 待排序数组
 * @param left 左边界索引
 * @param right 右边界索引
 */
void merge_sort(vector<int> &nums, int left, int right) {
    // 递归终止条件：当子数组长度为1时停止递归
    if (left >= right) {
        return;
    }
    
    // 计算中间位置，避免整数溢出
    int mid = left + ((right - left) >> 1);
    
    // 递归排序左右子数组
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    
    // 合并两个已排序的子数组
    merge(nums, left, mid, right);
}

/**
 * 合并两个已排序的子数组
 * @param nums 原始数组
 * @param left 左子数组起始索引
 * @param mid 中间位置（左子数组结束）
 * @param right 右子数组结束索引
 */
void merge(vector<int> &nums, int left, int mid, int right) {
    int lb = left, le = mid;      // 左子数组指针
    int rb = mid + 1, re = right;   // 右子数组指针
    
    vector<int> temp;  // 临时数组存储合并结果
    // 比较并合并两个子数组
    while (lb <= le && rb <= re) {
        if (nums[lb] <= nums[rb]) {
            temp.push_back(nums[lb++]);
        } else {
            temp.push_back(nums[rb++]);
        }
    }
    
    // 处理剩余的元素
    while (lb <= le) {
        temp.push_back(nums[lb++]);
    }
    
    while (rb <= re) {
        temp.push_back(nums[rb++]);
    }
    
    // 将合并结果复制回原数组
    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

/**
 * 打印数组内容
 * @param nums 要打印的数组
 * @param label 标签字符串
 */
void print_array(const vector<int> &nums, const string &label) {
    cout << label << ": ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * 测试归并排序函数
 * 包含多种测试用例：空数组、单元素、随机数组、重复元素等
 */
void test_sort() {
    cout << "=== 归并排序测试开始 ===" << endl;
    
    // 测试用例1：空数组
    vector<int> empty_array = {};
    vector<int> empty_expected = {};
    sort(empty_array);
    assert(empty_array == empty_expected);
    cout << "✓ 空数组测试通过" << endl;
    
    // 测试用例2：单元素数组
    vector<int> single = {5};
    vector<int> single_expected = {5};
    sort(single);
    assert(single == single_expected);
    cout << "✓ 单元素数组测试通过" << endl;
    
    // 测试用例3：已排序数组
    vector<int> sorted = {1, 2, 3, 4, 5};
    vector<int> sorted_expected = {1, 2, 3, 4, 5};
    sort(sorted);
    assert(sorted == sorted_expected);
    cout << "✓ 已排序数组测试通过" << endl;
    
    // 测试用例4：逆序数组
    vector<int> reverse = {5, 4, 3, 2, 1};
    vector<int> reverse_expected = {1, 2, 3, 4, 5};
    sort(reverse);
    assert(reverse == reverse_expected);
    cout << "✓ 逆序数组测试通过" << endl;
    
    // 测试用例5：随机数组
    vector<int> random = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    vector<int> random_expected = {11, 12, 22, 25, 34, 50, 64, 76, 88, 90};
    sort(random);
    assert(random == random_expected);
    cout << "✓ 随机数组测试通过" << endl;
    
    // 测试用例6：包含重复元素
    vector<int> duplicates = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> duplicates_expected = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
    sort(duplicates);
    assert(duplicates == duplicates_expected);
    cout << "✓ 重复元素数组测试通过" << endl;
    
    // 测试用例7：包含负数
    vector<int> negative = {-5, 2, -8, 0, 7, -3, 10};
    vector<int> negative_expected = {-8, -5, -3, 0, 2, 7, 10};
    sort(negative);
    assert(negative == negative_expected);
    cout << "✓ 负数数组测试通过" << endl;
    
    cout << "=== 所有测试用例通过！ ===" << endl;
}



