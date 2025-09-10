class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, overlap = 0;
        for (int i = 0; i < grid.size(); i ++)
        {
            for (int j = 0; j < grid[i].size(); j ++)
            {
                if (grid[i][j] == 1)
                {
                    res ++;
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
                        overlap ++;
                    if (i + 1 < grid.size() && grid[i + 1][j] == 1)
                        overlap ++;
                }
            }
        }
        
        return res * 4 - 2 * overlap;
        
    }
};
