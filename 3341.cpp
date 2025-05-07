// Time Complexity: O(n * m * log(n * m))
//   - Each cell can be pushed multiple times, but dp[i][j] ensures we only process the best time once.
//   - Priority queue operations are O(log(n * m)) each.
//
// Space Complexity: O(n * m)
//   - For the dp matrix and the priority queue in the worst case.

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();        // Number of rows
        int n = moveTime[0].size();     // Number of columns
        
        // 4 possible directions: up, down, right, left
        vector<vector<int>> directs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        // dp[i][j] = minimum time to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        // Min-heap: (time, row, col)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minq;
        minq.push({0, 0, 0});  // Start at (0, 0) at time 0

        while (!minq.empty()) {
            auto [t, i, j] = minq.top(); // Current time and position
            minq.pop();

            // If we already reached (i, j) earlier with a better time, skip
            if (dp[i][j] <= t)
                continue;

            // Update the earliest time to reach this cell
            dp[i][j] = t;

            // Early exit if we reached the destination
            if (i == m-1 && j == n-1)
                break;

            // Explore adjacent cells
            for (auto direct : directs) {
                int x = i + direct[0];
                int y = j + direct[1];
                // Check if neighbor is within bounds and not finalized yet
                if (x >= 0 && x < m && y >= 0 && y < n && dp[x][y] == INT_MAX) {
                    // Must wait until moveTime[x][y] is ready, then add 1 second to move
                    int nextTime = max(t, moveTime[x][y]) + 1;
                    minq.push({nextTime, x, y});
                }
            }
        }

        return dp[m-1][n-1];  // Return minimum time to reach destination
    }
};
