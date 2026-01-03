class NumArray {
private:
    vector<int> v;
public:
    NumArray(vector<int> nums) {
        v = nums;
    }
    
    void update(int i, int val) {
        v[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) sum += v[k];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */