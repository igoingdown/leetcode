//
//  main.cpp
//  126
//
//  Created by 赵明星 on 2017/2/5.
//  Copyright © 2017年 赵明星. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <stack>
#include <list>
#include <map>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
void backTrace(string word, string start, list<string>& path, map<string, vector<string>>& dict, vector<vector<string>>& res);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> pathList = findLadders("hit", "cog", wordList);
    for (auto path: pathList) {
        for (auto word: path) {
            cout << word << endl;
        }
        for (int i = 0; i < 80; i++) {
            cout << "-";
        }
        cout << endl;
    }
    return 0;
}


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    list<string> path;
    unordered_set<string> visited;
    unordered_set<string> unvisited(wordList.begin(), wordList.end());
    map<string, vector<string>> word2forwards;
    queue<string> q;
    q.push(beginWord);
    int cur = 1, next = 0;
    bool found = false;
    
    while(!q.empty()) {
        string word = q.front();
        q.pop();
        cur--;
        
        for (int i = 0; i < word.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string newWord = word;
                newWord[i] = ch;
                
                // newWord is in the dict.
                if (unvisited.find(newWord) != unvisited.end()) {
                    if (visited.find(newWord) == visited.end()) {
                        q.push(newWord);
                        next++;
                        visited.insert(newWord);
                    }
                    if (word2forwards.find(newWord) != word2forwards.end()) {
                        word2forwards[newWord].push_back(word);
                    } else {
                        vector<string> vec;
                        vec.push_back(word);
                        word2forwards[newWord] = vec;
                    }
                    if (newWord == endWord) {
                        found = true;
                    }
                }
            }
        }
        
        if (cur == 0) {
            if (found) {
                break;
            } else {
                cur = next;
                next = 0;
                for (auto word: visited) {
                    unvisited.erase(word);
                }
                visited.clear();
            }
        }
    }
    backTrace(endWord, beginWord, path, word2forwards, res);
    return res;
}

void backTrace(string word, string start, list<string>& path, map<string, vector<string>>& dict, vector<vector<string>>& res) {
    if (word == start) {
        path.push_front(word);
        vector<string> temp(path.begin(), path.end());
        res.push_back(temp);
        path.pop_front();
        return;
    } else {
        path.push_front(word);
        for (auto w: dict[word]) {
            backTrace(w, start, path, dict, res);
        }
        path.pop_front();
    }
}












