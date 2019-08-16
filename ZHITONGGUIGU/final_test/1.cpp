#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct TreeNode{
    int  val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL),right(NULL){};
};

void printChristmasTree(TreeNode* Root);

int main(int argc, char const *argv[])
{
    
    return 0;
}


void printChristmasTree(TreeNode* Root) {
    if (!Root) return;
    vector<vector<string>> res;
    queue<TreeNode* > q, next;
    q.push(Root);
    vector<string> v, next_v;
    v.push_back(to_string(Root->val));
    res.push_back(v);
    while (!q.empty()) {
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur->left) {
                next_v.push_back(to_string(cur->left->val));
                next.push(cur->left);
                next_v.push_back(" ");
                next.push(cur->right);
                next_v.push_back(to_string(cur->right->val));
            }
        }
        if (next_v.size() > 0) {
            vector<vector<string>> new_res;
            for (auto iter = res.begin(); iter!= res.end(); iter++) {
                vector<string> s(iter->size() * 2 + 1, " ");
                for (int i = 0; i < iter->size(); i++) {
                    s[i * 2 + 1] = iter->at(i);
                }
                new_res.push_back(s);
            }
            new_res.push_back(next_v);
            res = new_res;
            next_v.clear();
            swap(q, next);
        } else {
            for (auto v : res) {
                for (auto s : v) {
                    cout << s;
                }
                cout << endl;
            }
            return;
        }
    }
    
}

