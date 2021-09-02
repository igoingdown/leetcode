#include<iostream>
#include<string>

using namespace std;
void dfs(string N, int i, string prefix) {
    // cout << N << '\t' << i << '\t' << prefix << endl;
    if (prefix.size() > 0 && prefix[0] > '0' )  {
        if (prefix.size() < N.size() || prefix <=  N) {
        cout << prefix << endl;
        }
    }

if (i >= N.size()) {
        return;
    }

    for (char c = '0'; c <= '9'; c++) {
        dfs(N, i + 1, prefix + c);
    }
    //dfs(N, i+1, prefix);

}



void printN(int n) {
    dfs(to_string(n), 0, "");
}

int main() {
    printN(123);
    return 0;
}
