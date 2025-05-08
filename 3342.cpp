// Time Complexity: O(m * n * log(m * n)) due to Dijkstra-like traversal with a priority queue
// Space Complexity: O(m * n) for the dp table and priority queue

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();          // number of rows
        int n = moveTime[0].size();       // number of columns
        vector<vector<int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // 4 possible directions
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));  // dp[i][j] = min time to reach cell (i, j)
        
        // min-heap: {current time, row, column, step value (alternating between 1 and 2)}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minq;
        minq.push({0, 0, 0, 1});  // start at (0,0) with time 0 and step size 1

        while (!minq.empty()) {
            auto element = minq.top();
            int t = element[0];     // current time
            int i = element[1];     // current row
            int j = element[2];     // current column
            int step = element[3];  // current step size
            minq.pop();

            if (t >= dp[i][j])      // already found a faster way to this cell
                continue;

            dp[i][j] = t;           // update the minimum time to reach (i, j)

            if (i == m-1 && j == n-1)  // reached the target cell
                break;

            // explore all 4 directions
            for (auto direct : directs) {
                int x = i + direct[0];
                int y = j + direct[1];
                if (x >= 0 && x < m && y >= 0 && y < n && dp[x][y] == INT_MAX) {
                    // calculate the next available time to enter cell (x, y)
                    int nextTime = max(moveTime[x][y], t) + step;
                    int nextStep = step == 1 ? 2 : 1;  // toggle between 1 and 2
                    minq.push({nextTime, x, y, nextStep});
                }
            }
        }
        return dp[m-1][n-1];  // return minimum time to reach bottom-right cell
    }
};
