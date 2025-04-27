/*
Time Complexity: O(m * n)
    - We visit each cell at most once (either pushing into the queue or checking).
Space Complexity: O(m * n)
    - In the worst case, all oranges are rotten and stored in the queue at once.

Where m = number of rows, n = number of columns.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // Get number of rows
        int n = grid[0].size(); // Get number of columns
        int fresh = 0; // Counter for fresh oranges
        int mins = 0; // Minutes passed
        queue<pair<int, int>> q; // Queue for BFS (rotten oranges)
        vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 4 directions: down, up, right, left

        // Initialize queue with all initially rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j}); // Rotten orange
                else if (grid[i][j] == 1)
                    fresh++; // Count fresh oranges
            }
        }

        // If no fresh oranges exist, no minutes needed
        if (fresh == 0)
            return mins;
        
        // Start BFS traversal
        while (!q.empty()) {
            int size = q.size(); // Number of rotten oranges at this minute
            bool rotten = false; // Track if any fresh oranges rot in this round

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front(); // Current rotten orange position
                q.pop();

                // Explore 4-directional neighbors
                for (auto [dx, dy] : direct) {
                    int newx = x + dx;
                    int newy = y + dy;

                    // Check if neighbor is inside grid and is a fresh orange
                    if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1) {
                        grid[newx][newy] = 2; // Rot the fresh orange
                        fresh--; // Decrease fresh orange count
                        q.push({newx, newy}); // Add new rotten orange to queue
                        rotten = true; // Mark that rotting happened
                    }                    
                }
            }

            if (rotten)
                mins++; // Only increment minutes if at least one fresh orange rotted
        }

        // If no fresh oranges are left, return time; otherwise, return -1
        return fresh == 0 ? mins : -1;
    }
};
