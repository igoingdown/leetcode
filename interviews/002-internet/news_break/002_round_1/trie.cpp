#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Trie节点定义
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // 子节点映射
    bool isEnd;                              // 是否是单词结尾
    int frequency;                           // 单词频次
    string word;                             // 完整单词

    TrieNode() {
        isEnd = false;
        frequency = 0;
    }
};

// Trie树实现
class Trie {
private:
    TrieNode* root;
    
    // 用于存储频次比较结果的比较器
    struct CompareWords {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;  // 频次大的优先
            }
            return a.first < b.first;        // 频次相同按字典序
        }
    };

public:
    Trie() {
        root = new TrieNode();
    }
    
    // 插入单词和频次
    void insert(const string& word, int freq) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
        node->frequency = freq;
        node->word = word;
    }
    
    // 获取前缀对应的所有单词及其频次
    void getWordsWithPrefix(const string& prefix, vector<pair<string, int>>& result) {
        TrieNode* node = root;
        // 找到前缀对应的节点
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return;
            }
            node = node->children[c];
        }
        // DFS收集所有单词
        dfs(node, result);
    }
    
    // DFS遍历收集单词
    void dfs(TrieNode* node, vector<pair<string, int>>& result) {
        if (!node) return;
        if (node->isEnd) {
            result.push_back({node->word, node->frequency});
        }
        for (auto& pair : node->children) {
            dfs(pair.second, result);
        }
    }
    
    // 获取前缀对应的top k个单词
    vector<string> getTopK(const string& prefix, int k) {
        vector<pair<string, int>> words;
        getWordsWithPrefix(prefix, words);
        
        // 使用优先队列排序
        priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;
        for (const auto& word : words) {
            pq.push(word);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // 构造结果
        vector<string> result;
        while (!pq.empty()) {
            result.insert(result.begin(), pq.top().first);
            pq.pop();
        }
        return result;
    }
};

// 测试主函数
int main() {
    Trie trie;
    
    // 测试用例1：基本功能测试
    cout << "Test Case 1: Basic functionality" << endl;
    trie.insert("apple", 5);
    trie.insert("app", 3);
    trie.insert("apt", 2);
    trie.insert("apex", 4);
    
    vector<string> result = trie.getTopK("ap", 3);
    cout << "Top 3 words starting with 'ap':" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }
    
    // 测试用例2：相同频次测试
    cout << "\nTest Case 2: Same frequency" << endl;
    Trie trie2;
    trie2.insert("cat", 3);
    trie2.insert("car", 3);
    trie2.insert("cab", 3);
    
    result = trie2.getTopK("ca", 3);
    cout << "Top 3 words starting with 'ca' (should be in lexicographical order):" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }
    
    // 测试用例3：空前缀测试
    cout << "\nTest Case 3: Empty prefix" << endl;
    result = trie2.getTopK("", 2);
    cout << "Top 2 words with empty prefix:" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }
    
    // 测试用例4：不存在的前缀
    cout << "\nTest Case 4: Non-existent prefix" << endl;
    result = trie2.getTopK("z", 1);
    cout << "Words starting with 'z' (should be empty):" << endl;
    for (const string& word : result) {
        cout << word << endl;
    }
    
    return 0;
}
