class TrieNode {
public:
    bool isKey;
    TrieNode* child[26];
    TrieNode(): isKey(false) {
        memset(child, NULL, sizeof(TrieNode*) * 26);
    }
};

class MagicDictionary {
private:
    TrieNode* root;
    bool find(const char* w, TrieNode* run, bool changed) {
        for (int i = 0; w[i]; i++) {
            if ( run && changed) {
                run = run->child[w[i] - 'a'];
            } else {
                if (run && run->child[w[i] - 'a']) {
                    run = run->child[w[i] - 'a'];
                } else if (run && !run->child[w[i] - 'a']) {
                    TrieNode* tmp = run;
                    for (int j = 0; j < 25; j++) {
                        tmp = run->child[w[i] - 'a'];
                        if (find(w + i + 1, tmp, true)) {
                            return true;
                        }
                    }
                    run = tmp;
                } else {
                    break;
                }
            }
        }
        return run && run->isKey;
    }
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string s: dict) {
            TrieNode * tmp = root;
            for (char c: s) {
                if (!tmp->child[c -'a']) {
                    tmp->child[c - 'a'] = new TrieNode();
                }
                tmp = tmp->child[c - 'a'];
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return find(word.c_str(), root, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */