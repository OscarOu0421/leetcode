// Time: O((n-2)^2)
// Space: O(n^2)

class Solution {
public:
    int maxlocal(vector<vector<int>> &grid, int ci, int cj) {
        int ret = INT_MIN;
        for (int i = ci-1; i <= ci+1; i++) {
            for (int j = cj-1; j <= cj+1; j++) {
                ret = max(ret, grid[i][j]);
            }
        }
        return ret;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ret(n-2, vector<int>(n-2, 0));

        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                ret[i][j] = maxlocal(grid, i+1, j+1);
            }
        }
        return ret;
    }
};
