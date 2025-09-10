class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) {
            return true;
        }
        if ('a' <= word[0] && word[0] <= 'z') {
            for (int i = 1; i < word.size(); i++) {
                if ('A' <= word[i] && word[i] <= 'Z') {
                    return false;
                }
            }
            return true;
        } else {
            if (word.size() == 2) {
                return true;
            } else {
                if (word[1] <= 'Z' && word[1] >= 'A') {
                    for (int i = 2; i < word.size(); i++) {
                        if ('a' <= word[i] && word[i] <= 'z') {
                            return false;
                        }
                    }
                    return true;
                } else {
                    for (int i = 2; i < word.size(); i++) {
                        if ('A' <= word[i] && word[i] <= 'Z') {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
};
