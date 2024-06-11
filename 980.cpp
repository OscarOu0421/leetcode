// Time: O(3^(mn)), for any cell, you can only go to max 3 neighbors(you can not go back to previous cell)
// Space: (mn) recursive stack in dfs
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int steps, int empty) {
        int tmp, left, right, up, down;

        // index is invalid
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
            return 0;
        
        // There is the obstacle
        if (grid[i][j] == -1)
            return 0;
        
        // if we arrive at ending and works over every empty square.
        if (grid[i][j] == 2 && steps == empty)
            return 1;

        // mark it visited, avoid to walk again
        tmp = grid[i][j];
        grid[i][j] = -1;

        left = dfs(grid, i, j-1, steps+1, empty);
        right = dfs(grid, i, j+1, steps+1, empty);
        up = dfs(grid, i-1, j, steps+1, empty);
        down = dfs(grid, i+1, j, steps+1, empty);
        
        grid[i][j] = tmp;
        return left + right + up + down;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0, empty = 0, start_i = 0, start_j = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                } else if (grid[i][j] == 0 || grid[i][j] == 2)
                    empty++;
            }
        }
        return dfs(grid, start_i, start_j, 0, empty);
    }
};
