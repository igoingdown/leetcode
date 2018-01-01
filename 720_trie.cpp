class Solution {
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
    Node* root = new Node();
    string longestWord(vector<string>& words) {
        root->end = true;
        for (string word: words) {
            Node* tmp = root;
            for (char c : word) {
                if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new Node;
                tmp = tmp->next[c - 'a'];
            }
            tmp->end = true;
        }
        string res = "", path = "";
        dfs(root, res, path);
        return res;
    }
    void dfs(Node* cur, string& res, string& path) {
        if (!cur || !cur->end) return;
        if (path.size() > res.size()) res = path; 
        for (int i = 0; i < 26; i++) {
            path.push_back('a' + i);
            dfs(cur->next[i], res, path);
            path.pop_back();
        }
    }
};