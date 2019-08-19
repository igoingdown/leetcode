class Solution {
public:
    class Node {
    public:
        vector<Node*> next;
        bool end;
        Node(): next(vector<Node*>(26, NULL)), end(false){};
    };
    string longestWord(vector<string>& words) {
        Node *trie = new Node();
        trie->end = true;
        build(trie, words);
        string path = "", res = "";
        dfs(trie, path, res);
        return res;
    }
    
    void build(Node* root, vector<string> &words) {
        Node *tmp = NULL;
        for (string & word: words) {
            tmp = root;
            for (char c: word) {
                if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new Node();
                tmp = tmp->next[c - 'a'];
            }
            tmp->end = true;
        }
    }
    
    void dfs(Node* root, string &path, string &res) {
        if (!root || !root->end) return;
        if (path.size() > res.size()) res = path;
        for (int i = 0; i < 26; i++) {
            path.push_back('a' + i);
            dfs(root->next[i], path, res);
            path.pop_back();
        }
    } 
};
