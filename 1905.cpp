// TC: O(mn)
// SC: O(mn)
class Solution {
public:
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int ret = 1;

        // Reach the end, return 1 to success.
        if (i < 0 || i == grid1.size() || j < 0 || j == grid1[0].size() || grid2[i][j] == 0)
            return 1;
        
        grid2[i][j] = 0;
        // if the neighbor is invalid island, the current cell is also invalid.
        ret &= dfs(grid1, grid2, i-1, j);
        ret &= dfs(grid1, grid2, i+1, j);
        ret &= dfs(grid1, grid2, i, j-1);
        ret &= dfs(grid1, grid2, i, j+1);

        // check current cell is valid or not
        return ret & grid1[i][j];
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ret = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] && dfs(grid1, grid2, i, j))
                    ret++;
            }
        }
        return ret;
    }
};
