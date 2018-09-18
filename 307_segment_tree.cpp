class NumArray {
private:
    vector<int> v;
    int n;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        v.clear();
        v.resize(n * 2);
        for (int i = n; i < n * 2; i++) v[i] = nums[i - n];
        for (int i = n - 1; i >= 0; i--) v[i] = v[i * 2] + v[i * 2 + 1];
    }
    
    void update(int i, int val) {
        int pos = i + n, left, right;
        v[pos] = val;
        while (pos > 0) {
            left = pos;
            right = pos;
            if ((pos & 1) == 0) right = pos + 1;
            else left = pos - 1;
            v[pos / 2] = v[left] + v[right];
            pos /= 2;
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0, left = i + n, right = j + n;
        while (left <= right) {
            if ((left & 1) > 0) {
                sum += v[left];
                left++;
            }
            if ((right & 1) == 0) {
                sum += v[right];
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */