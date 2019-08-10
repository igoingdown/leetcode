#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void compose(vector<int> &used, int &res, int i, vector<int> &expr) {
	if (i > 9){
		if (expr[1]*100 + expr[2] * 10 + expr[3] + expr[4] * 100 + expr[5] * 10 + expr[6] == expr[7] * 100 + expr[8] * 10 + expr[9]) {
			++res;
			printf("%d%d%d+%d%d%d=%d%d%d\n",expr[1],expr[2],expr[3],expr[4],expr[5],expr[6],expr[7],expr[8],expr[9]);
		}
	} else {
		for (int j = 1; j <= 9; j++) {
			if (!used[j]) {
				used[j] = 1;
				expr[i] = j;  
				compose(used, res, i + 1, expr);
				used[j] = 0;
			}
		}
	}
}

int main() {
	vector<int> used(10);
	vector<int> expr(10);
	int res = 0;
	compose(used, res, 1, expr);
	cout << res << endl;
}
