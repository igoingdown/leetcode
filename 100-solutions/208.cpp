class Trie {
public:
    class Node{
    public:
        bool end;
        vector<Node*> next;
        Node() {
            end = false;
            next.resize(26, NULL);
        }
    };
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* tmp = root;
        for (char c : word) {
            if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new Node();
            tmp = tmp->next[c - 'a'];
        }
        tmp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* tmp = root;
        for (char c: word) {
            if (!tmp->next[c - 'a']) return false;
            tmp = tmp->next[c - 'a'];
        }
        return tmp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp = root;
        for (char c : prefix) {
            if (!tmp->next[c - 'a']) return false;
            tmp = tmp->next[c - 'a'];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */