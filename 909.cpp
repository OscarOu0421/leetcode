// Time Complexity: O(n^2) - each square is visited at most once
// Space Complexity: O(n^2) - for visited array and BFS queue

class Solution {
public:
    // Convert square number to (row, col) on the board considering Boustrophedon pattern
    pair<int, int> getCoordinates(int num, int n) {
        int r = n - 1 - (num - 1) / n;          // Row from bottom to top
        int c = (num - 1) % n;                  // Column from left to right initially
        if ((n - 1 - r) % 2 == 1) {             // If the row index from bottom is odd, reverse column direction
            c = n - 1 - c;
        }
        return make_pair(r, c);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false); // Tracks visited squares
        queue<pair<int, int>> q;               // Queue for BFS: {square number, steps taken}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            // Try all dice rolls from 1 to 6
            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) break; // Cannot move beyond last square

                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1) {
                    next = board[r][c]; // Take ladder or snake
                }

                if (next == n * n) return steps + 1; // Reached end

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1}); // Add to queue with incremented step count
                }
            }
        }

        return -1; // If end not reachable
    }
};

