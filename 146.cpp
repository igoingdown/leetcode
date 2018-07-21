class LRUCache {
private:
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            items.splice(items.begin(), items, cache[key]); 
            cache[key] = items.begin();
            return cache[key]->second;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (items.size() == _capacity) {
                cache.erase(items.back().first); items.pop_back();
            }
            items.push_front({key, value});
            cache[key] = items.begin(); 
        } else {
            items.splice(items.begin(), items, cache[key]); 
            cache[key] = items.begin(); 
            cache[key]->second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */