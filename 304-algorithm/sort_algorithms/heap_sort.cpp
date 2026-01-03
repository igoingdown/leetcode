#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int> &nums, int b, int e);
void heap_sort(vector<int> &nums);
void print_array(const vector<int> &nums, const string &label);
bool test_heap_sort();

int main() {
    // Run comprehensive tests
    if (test_heap_sort()) {
        cout << "All tests passed!" << endl;
    } else {
        cout << "Some tests failed!" << endl;
    }
    return 0;
}

/**
 * @brief 堆化函数 - 维护最大堆性质
 * @param nums 待处理的数组
 * @param b 当前需要堆化的根节点索引
 * @param e 堆的有效范围（不包含e）
 * 
 * 该函数假设以b为根的左右子树已经是最大堆，
 * 通过向下调整使以b为根的子树满足最大堆性质。
 * 时间复杂度：O(log n)
 */
void heapify(vector<int> &nums, int b, int e) {
    int cur = b, child = cur * 2 + 1;  // child指向左子节点
    
    // 向下调整，直到到达叶子节点或找到合适位置
    while (cur < e && child < e) {
        // 选择较大的子节点（如果右子节点存在且更大）
        if (child + 1 < e && nums[child] < nums[child + 1]) child++;
        
        // 如果父节点小于较大的子节点，则交换
        if (nums[cur] < nums[child]) {
            swap(nums[child], nums[cur]);
            cur = child;  // 继续向下调整
            child = child * 2 + 1;
        } else {
            break;  // 已经满足堆性质，退出循环
        }
    }
}

/**
 * @brief 堆排序主函数
 * @param nums 待排序的数组
 * 
 * 堆排序算法步骤：
 * 1. 构建最大堆：从最后一个非叶子节点开始，向前依次堆化
 * 2. 排序阶段：重复将堆顶元素（最大值）与末尾元素交换，
 *    然后对剩余元素重新堆化
 * 
 * 时间复杂度：O(n log n)
 * 空间复杂度：O(1) - 原地排序
 * 稳定性：不稳定排序
 */
void heap_sort(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
        return;  // 空数组或单元素数组无需排序
    }
    
    // 步骤1：构建最大堆
    // 从最后一个非叶子节点开始向前堆化
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }
    
    // 步骤2：排序阶段
    // 每次将堆顶元素（最大值）放到数组末尾
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);  // 将最大值移到已排序区域
        heapify(nums, 0, i);     // 对剩余元素重新堆化
    }
}

/**
 * @brief 打印数组内容
 * @param nums 要打印的数组
 * @param label 打印标签
 */
void print_array(const vector<int> &nums, const string &label) {
    cout << label << ": ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/**
 * @brief 堆排序测试函数
 * @return true 如果所有测试通过，false 否则
 * 
 * 测试用例包括：
 * - 空数组
 * - 单元素数组
 * - 已排序数组
 * - 逆序数组
 * - 包含重复元素的数组
 * - 随机数组
 * - 大数组（性能测试）
 */
bool test_heap_sort() {
    cout << "=== 堆排序测试开始 ===" << endl;
    
    // 测试1：空数组
    vector<int> test1 = {};
    vector<int> expected1 = {};
    heap_sort(test1);
    if (test1 != expected1) {
        cout << "测试1（空数组）失败!" << endl;
        return false;
    }
    cout << "测试1（空数组）：通过" << endl;
    
    // 测试2：单元素数组
    vector<int> test2 = {5};
    vector<int> expected2 = {5};
    heap_sort(test2);
    if (test2 != expected2) {
        cout << "测试2（单元素）失败!" << endl;
        return false;
    }
    cout << "测试2（单元素）：通过" << endl;
    
    // 测试3：已排序数组
    vector<int> test3 = {1, 2, 3, 4, 5};
    vector<int> expected3 = {1, 2, 3, 4, 5};
    heap_sort(test3);
    if (test3 != expected3) {
        cout << "测试3（已排序）失败!" << endl;
        print_array(test3, "实际结果");
        print_array(expected3, "期望结果");
        return false;
    }
    cout << "测试3（已排序）：通过" << endl;
    
    // 测试4：逆序数组
    vector<int> test4 = {5, 4, 3, 2, 1};
    vector<int> expected4 = {1, 2, 3, 4, 5};
    heap_sort(test4);
    if (test4 != expected4) {
        cout << "测试4（逆序）失败!" << endl;
        print_array(test4, "实际结果");
        print_array(expected4, "期望结果");
        return false;
    }
    cout << "测试4（逆序）：通过" << endl;
    
    // 测试5：包含重复元素
    vector<int> test5 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> expected5 = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
    heap_sort(test5);
    if (test5 != expected5) {
        cout << "测试5（重复元素）失败!" << endl;
        print_array(test5, "实际结果");
        print_array(expected5, "期望结果");
        return false;
    }
    cout << "测试5（重复元素）：通过" << endl;
    
    // 测试6：随机数组
    vector<int> test6 = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    vector<int> expected6 = {11, 12, 22, 25, 34, 50, 64, 76, 88, 90};
    heap_sort(test6);
    if (test6 != expected6) {
        cout << "测试6（随机数组）失败!" << endl;
        print_array(test6, "实际结果");
        print_array(expected6, "期望结果");
        return false;
    }
    cout << "测试6（随机数组）：通过" << endl;
    
    // 测试7：大数组（性能测试）
    cout << "测试7（大数组）：开始性能测试..." << endl;
    vector<int> test7;
    for (int i = 1000; i >= 1; i--) {
        test7.push_back(i);
    }
    heap_sort(test7);
    // 验证是否排序正确
    bool sorted = true;
    for (int i = 0; i < test7.size() - 1; i++) {
        if (test7[i] > test7[i + 1]) {
            sorted = false;
            break;
        }
    }
    if (!sorted) {
        cout << "测试7（大数组）失败!" << endl;
        return false;
    }
    cout << "测试7（大数组）：通过 - 1000个元素排序成功" << endl;
    
    cout << "=== 堆排序测试完成 ===" << endl;
    return true;
}
