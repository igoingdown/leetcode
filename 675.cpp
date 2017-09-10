class Solution {
private:
    struct TreeComparator {
        bool operator() (vector<int> a, vector<int> b) {
            return a[2] > b[2];
        }
    };
    
    int bfs(vector<vector<int> > forest, int i0, int j0, int i1, int j1) {
        if (i0 == i1 && j0 == j1) {
            return 0;
        }
        int m = forest.size(), n = forest[0].size();
	int delta[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        queue<pair<int, int> > q;
        q.push({i0, j0});

        forest[i0][j0] = -forest[i0][j0];
	int dis = 0;
        while (!q.empty()) {
            dis++;
            for (int k = q.size(); k > 0; k--) {
                pair<int, int> p = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int i = p.first + delta[d][0], j = p.second + delta[d][1];
                    if (i == i1 && j == j1) {
                        return dis;
                    }
                    if (i < 0 || i >= m || j < 0 || j >= n || forest[i][j] <= 0) {
                        continue;
                    }
                    forest[i][j] = -forest[i][j];
                    q.push({i, j});
                }
            }
        }
        return -1;
    }
    
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<vector<int>, vector<vector<int> >, TreeComparator> trees;
	int m = forest.size(), n = forest[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.push({i, j, forest[i][j]});
                }
            }
        }
        int total = 0;

        for (int i = 0, j = 0, i1 = 0, j1 = 0; !trees.empty(); i = i1, j = j1) {
            vector<int> tree = trees.top();
            trees.pop();
            i1 = tree[0];
	    j1= tree[1];
            int dis = bfs(forest, i, j, i1, j1);
            if (dis == -1) {
                return -1;
            }
            total += dis;
        }
        return total;
    }
    
    
};