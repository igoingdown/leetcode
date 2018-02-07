class Node {
public:
    bool end;
    vector<Node*> next;
    Node() {
        end = false;
        next.resize(256, NULL);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node *root = new Node();
        for (string s : strs) {
            auto tmp = root;
            for (char c : s) {
                if (!tmp->next[c]) tmp->next[c] = new Node();
                tmp = tmp->next[c];
            }
            tmp->end = true;
        }
        string res = "";
        while (root && !root->end) {
            int next = -1;
            for (int i = 0; i < 256; i++) {
                if (root->next[i]) {
                    if (next >= 0) return res;
                    next = i;
                }
            }
            if (next >= 0) res += char(next);
            root = next >= 0 ? root->next[next] : NULL;
        }
        return res;
    }
};