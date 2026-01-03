class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), locks = 0;
        int bias[5] = {1, 0, -1, 0, 1};
        queue<pair<int, set<char>>> q, next;
        int layers = 0;
        bool allKeys = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') q.push({i * 30 + j, set<char>()});
                if (isupper(grid[i][j])) locks++;
            }
        }
        
        set<pair<int, set<char>>> visited;
        while (!q.empty()) {
            
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                visited.insert(cur);
                int curX = cur.first / 30, curY = cur.first % 30;
                set<char> curKeys = cur.second;
                if (curKeys.size() == locks) {
                    allKeys = true;
                    break;
                }
                for (int k = 0; k < 4; k++) {
                    int newX = curX + bias[k], newY = curY + bias[k + 1];
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == '#') continue;
                    if (isupper(grid[newX][newY])) {
                        if (curKeys.find(tolower(grid[newX][newY])) != curKeys.end() && visited.find({newX * 30 + newY, curKeys}) == visited.end()) {
                            next.push({newX * 30 + newY, curKeys});
                        }
                        
                    } else if (islower(grid[newX][newY])) {
                        set<char> keys(curKeys);
                        keys.insert(grid[newX][newY]);
                        if (visited.find({newX * 30 + newY, keys}) == visited.end()) {
                            next.push({newX * 30 + newY, keys});
                        }  
                    } 
                    else {
                        if (visited.find({newX * 30 + newY, curKeys}) == visited.end()) {
                            next.push({newX * 30 + newY, curKeys});
                        }
                    }
                }
            }
            swap(q, next);
            if (allKeys) break;
            layers++;
        }
        return allKeys ? layers : -1;
    }
};