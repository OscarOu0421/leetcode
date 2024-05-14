// Time: O(n * 3 ^n), n is the number of the cell, each cell run most k length for dfs
// only 3 directions except from parent cell
// Space: O(n)
class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        int org, l = 0, r = 0, u = 0, d = 0;
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size()|| grid[i][j] == 0)
            return 0;
        
        org = grid[i][j];
        grid[i][j] = 0;
        u = dfs(grid, i-1, j);
        d = dfs(grid, i+1, j);
        l = dfs(grid, i, j-1);
        r = dfs(grid, i, j+1);
        u = max(u, d);
        l = max(l, r);
        grid[i][j] = org;
        return org + max(u, l);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, dfs(grid, i, j));
            }
        }
        return ret;
    }
};
