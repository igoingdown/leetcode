class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        if (n < 1) {
            return 0;
        } 
        vector<int> is_valid(n, 0);
        vector<int> scores(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "C") {
                for (int j = i - 1; j >= 0; j--) {
                    if (is_valid[j]) {
                        is_valid[j] = 0;
                        sum -= scores[j];
                        break;
                    }
                }
            } else if (ops[i] == "D") {
                for (int j = i - 1; j >= 0; j--) {
                    if (is_valid[j]) {
                        sum += scores[j] * 2;
                        scores[i] = scores[j] * 2;
                        break;
                    }
                }
                is_valid[i] = 1;
            } else if (ops[i] == "+") {
                int last = i - 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (is_valid[j]) {
                        sum += scores[j];
                        last = j;
                        break;
                    }
                }
                for (int j = last - 1; j >= 0; j--) {
                    if (is_valid[j]) {
                        sum += scores[j];
                        scores[i] = scores[j] + scores[last];
                        break;
                    }
                }
                is_valid[i] = 1;
            } else {
                int score = stoi(ops[i]);
                scores[i] = stoi(ops[i]);
                sum += score;
                is_valid[i] = 1;
            } 
        }
        return sum;
    }
};