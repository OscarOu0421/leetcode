// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
// m = number of rows, n = number of columns

class Solution {
public:
    // DFS to mark reachable cells
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        int m = heights.size();
        int n = heights[0].size();
        visited[i][j] = true; // mark current cell as visited

        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}}; // directions: down, up, right, left
        for (auto [dx, dy] : dirs) {
            int x = i + dx, y = j + dy;
            // check bounds, not visited, and height constraint
            if (x >= 0 && x < m && y >= 0 && y < n && 
                !visited[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, visited, x, y); // DFS to neighbor
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // visited matrices for each ocean
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Perform DFS from Pacific borders (top and left)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0); // left edge
            dfs(heights, atlantic, i, n - 1); // right edge
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j); // top edge
            dfs(heights, atlantic, m - 1, j); // bottom edge
        }

        vector<vector<int>> res;
        // Find cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j}); // cell reachable by both oceans
                }
            }
        }
        return res;
    }
};
