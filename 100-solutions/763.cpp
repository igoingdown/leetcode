#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> partitionLabels(string S);
void dfs(vector<int>& path, vector<int>& res, vector<int>& visited, string s, int start);
int main() {
	auto v = partitionLabels("ababcbacadefegdehijhklij");
	for (int i : v) cout << i << endl;
	return 0;
}

vector<int> partitionLabels(string S) {
    vector<int> path, res, visited(26, 0);
    dfs(path, res, visited, S, 0);
    return res;
}
void dfs(vector<int>& path, vector<int>& res, vector<int>& visited, string s, int start) {
    if (start == s.size()) {
        if (path.size() > res.size()) res = path;
        return;
    }
    for (int i = start; i < s.size(); i++) {
        if (visited[s[i] - 'a']) break;
        else {
            for (int j = start; j <= i; j++) visited[s[j] - 'a'] = 1;
            path.push_back(i - start + 1);
            dfs(path, res, visited, s, i + 1);
            path.pop_back();
            for (int j = start; j <= i; j++) visited[s[j] - 'a'] = 0;
        }
    }
}