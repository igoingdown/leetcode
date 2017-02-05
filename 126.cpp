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
void backTrace(string word, string start, list<string>& path, vector<vector<string>>& res, map<string, vector<string>> matrix);

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
    vector<vector<string>> pathList;
    queue<string> wordsToVisit;
    unordered_set<string> visitedWords;
    unordered_set<string> unvisitedWords(wordList.begin(), wordList.end());
    map<string, vector<string>> word2Forwards;
    unvisitedWords.insert(endWord);
    wordsToVisit.push(beginWord);

    bool foundFlag = false;
    int cur_layer = 1, next_layer = 0;
    while (!wordsToVisit.empty()) {
        string word = wordsToVisit.front();
        wordsToVisit.pop();
        cur_layer--;
        
        for (int i = 0; i < word.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string newWord = word;
                newWord[i] = ch;
                
                // newWord is in the dict.
                if (unvisitedWords.find(newWord) != unvisitedWords.end()) {
                    
                    // newWord has not been visited before.
                    if (visitedWords.find(newWord) == visitedWords.end()) {
                        visitedWords.insert(newWord);
                        next_layer++;
                        wordsToVisit.push(newWord);
                    }
                    
                    if (word2Forwards.find(newWord) != word2Forwards.end()) {
                        word2Forwards[newWord].push_back(word);
                    } else {
                        vector<string> temp_vec;
                        temp_vec.push_back(word);
                        word2Forwards[newWord] = temp_vec;
                    }
                    
                    if (newWord == endWord) {
                        foundFlag = true;
                    }
                }
            }  // end iteration from 'a' to 'z'.
        }  // end iteration from the first character to the last of the word.
        
        if (cur_layer == 0) {
            if (foundFlag) {
                break;
            } else {
                cur_layer = next_layer;
                next_layer = 0;
                for (auto visitedWord: visitedWords) {
                    unvisitedWords.erase(visitedWord);
                }
                visitedWords.clear();
            }
        }
    }
    
    list<string> path;
    backTrace(endWord, beginWord, path, pathList, word2Forwards);
    return pathList;
}


void backTrace(string word, string start, list<string>& path, vector<vector<string>>& res, map<string, vector<string>> matrix) {
    if (word == start) {
        path.push_front(word);
        vector<string> temp(path.begin(), path.end());
        res.push_back(temp);
        path.pop_front();
        return;
    }
    
    path.push_front(word);
    for (auto w: matrix[word]) {
        backTrace(w, start, path, res, matrix);
    }
    path.pop_front();
}



















