#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    bool isKey;
    TrieNode* child[26];
    TrieNode() : isKey(false) {
        memset(child, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
private:
    TrieNode* root;
    bool find(const char* w, TrieNode* root) {
        TrieNode* tmp = root;
        for (int i = 0; w[i]; i++) {
            if (tmp && w[i] != '.') {
                tmp = tmp->child[w[i] - 'a'];
            }
            else if (tmp && w[i] == '.') {
                TrieNode * run = tmp;
                for (int j = 0; j < 26; j++) {
                    run = tmp->child[j];
                    if (find(w + i + 1, tmp->child[j])) {
                        return true;
                    }
                }
                tmp = run;
            }
            else {
                break;
            }
        }
        return tmp && (tmp->isKey);
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (!tmp->child[c - 'a']) {
                tmp->child[c - 'a'] = new TrieNode();
                
            }
            tmp = tmp->child[c - 'a'];
        }
        tmp->isKey = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word.c_str(), root);
    }
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/





int main(void) {
    vector<int> v = { 2, 3, 6, 7 };
    WordDictionary w;
    w.addWord("a");
    w.addWord("ab");
    cout << w.search("a.") << endl;
    return 0;
}
