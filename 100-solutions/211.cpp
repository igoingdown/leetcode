class TrieNode {
public:    
    bool finish;
    vector<TrieNode*> next;
    TrieNode(): finish(false), next(vector<TrieNode*>(26, NULL)) {}
};

class WordDictionary {
private:
    TrieNode* root;
    bool find(TrieNode* root, string word) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!root->next[c - 'a']) return false;
                else root = root->next[c - 'a'];
            } else {
                for (auto ptr : root->next) {
                    if (ptr && find(ptr, word.substr(i + 1))) return true;
                }
                return false;
            }
        }
        return root && root->finish;
    }
    
    void add(TrieNode *root, string word){
    for (char c : word) {
        if (!root->next[c - 'a']) {
            root->next[c - 'a'] = new TrieNode();
        }
        root = root->next[c - 'a'];
    }
    root->finish = true;
}
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        add(root, word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(root, word.c_str());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */