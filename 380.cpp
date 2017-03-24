class RandomizedSet {
private:
    unordered_map<int, int> val2Idx;
    vector<int> vals;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        vals.push_back(0);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val2Idx.find(val) == val2Idx.end()) {
            vals.push_back(val);
            vals[0]++;
            val2Idx[val] = vals[0];
            return true;
        } else {
            if (val2Idx[val] < 0) {
                val2Idx[val] = -val2Idx[val];
                vals[0]++;
                return true;
            }
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (val2Idx.find(val) != val2Idx.end() && val2Idx[val] > 0) {
            val2Idx[val] = -val2Idx[val];
            vals[0]--;
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand() % vals.size();
        while (val2Idx[vals[i]] < 0 || i == 0) {
            i = rand() % vals.size();
        }
        return vals[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
