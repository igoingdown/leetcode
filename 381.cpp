class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = m.find(val) == m.end();
        m[val].push_back(nums.size());
        nums.push_back({val, m[val].size() - 1});
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool ans = m.find(val) != m.end();
        if (ans) {
            m[nums.back().first][nums.back().second] = m[val].back();
            swap(nums.back(), nums[m[val].back()]);
            nums.pop_back();
            m[val].pop_back();
            if (m[val].empty()) m.erase(val);
        }
        return ans;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */