class Solution {
public:
    string pushDominoes(string dominoes) {
        string next(dominoes);
        int n = dominoes.size();
        while (1) {
            for (int i = 0; i < n; i++) {
                if (dominoes[i] == '.') {
                    if (i > 0 && dominoes[i - 1] == 'R' && (i == n - 1 || dominoes[i + 1] != 'L')) next[i] = 'R';
                    else if (i + 1 < n && dominoes[i + 1] == 'L' && (i == 0 || dominoes[i - 1] != 'R')) next[i] = 'L';
                    else next[i] = '.';
                } else next[i] = dominoes[i];
            }
            if (next == dominoes) break;
            dominoes = next;
        }
        return dominoes;
    }
};