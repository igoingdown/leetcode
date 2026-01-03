class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != '#' && preorder[i] != ',') {
                s.push(preorder[i]);
                while (preorder[i] != ',') {
                    i++;
                }
            } else if (preorder[i] == '#') {
                while (!s.empty() && s.top() == '#') {
                    s.pop();
                    if (s.empty()) {
                        return false;
                    }
                    s.pop();
                }
                s.push('#');
            }
        }
        return s.top() == '#' && s.size() == 1;
    }
};