class MapSum {
public:
    class Node{
    public:
        int val;
        vector<Node*> next;
        Node() {
            val = -1;
            next.resize(26, NULL);
        }
    };
    /** Initialize your data structure here. */
    Node* root;
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* tmp = root;
        for (char c : key) {
            if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new Node();
            tmp = tmp->next[c - 'a'];
        }
        tmp->val = val;
    }
    
    int sum(string prefix) {
        Node* tmp = root;
        for (char c : prefix) {
            if (!tmp->next[c - 'a']) return 0;
            tmp = tmp->next[c - 'a'];
        }
        int sum = 0;
        queue<Node*> q, next;
        q.push(tmp);
        while (!q.empty()) {
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                sum += (cur && cur->val >= 0 ? cur->val : 0);
                if (cur) {
                    for (auto p : cur->next) {
                        if (p) next.push(p);
                    }
                }
            }
            swap(q, next);
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */