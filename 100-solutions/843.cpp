/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int check(string &target, string &word) {
        int c = 0;
        for (int i = 0; i < target.size(); i++) {
            c += (target[i] == word[i]) ? 1 : 0;
        }
        return c;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0; i < 10; i++) {
            string target = wordlist[rand() % wordlist.size()];
            int r = master.guess(target);
            if (r == 6) return;
            vector<string> next;
            for (string & word : wordlist) {
                if (check(word, target) == r) next.push_back(word);
            }
            wordlist = next;
        }
    }
};