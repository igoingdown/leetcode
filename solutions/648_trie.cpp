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
    string replaceWords(vector<string>& dict, string sentence) {
        for (string s : dict) {
            Node* tmp = root;
            for (char c : s) {
                if (!tmp->next[c - 'a']) tmp->next[c - 'a'] = new Node();
                tmp = tmp->next[c - 'a'];
            }
            tmp->end = true;
        }
        istringstream ss(sentence);
        string buffer, res;
        while (getline(ss, buffer, ' ')) {
            string path = "";
            Node* tmp = root;
            bool finded = false;
            for (char c : buffer) {
                if (!tmp) break;
                if (tmp->end) {
                    finded = true;
                    break;
                }
                tmp = tmp->next[c - 'a'];
            }
            if (!finded) res += buffer + " ";
            else {
                tmp = root;
                for (char c : buffer) {
                    if (!tmp || tmp->end) break;
                    path.push_back(c);
                    tmp = tmp->next[c - 'a'];
                }
                res += path + " ";
            }
        }
        res.pop_back();
        return res;
    }
};