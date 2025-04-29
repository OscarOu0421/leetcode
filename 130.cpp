// Time Complexity: O(m * n) 
//    - Each cell is visited at most once by the DFS.
// Space Complexity: O(m * n) in the worst case due to the recursion stack (DFS depth)
// This function flips all 'O's that are completely surrounded by 'X' to 'X'.

class Solution {
public:
    // DFS helper to mark 'O's connected to the border
    void helper(vector<vector<char>> &board, int i, int j) {
        // Boundary and visited check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'S';  // Temporarily mark as safe (connected to border)

        // Visit 4-connected neighbors (up, down, left, right)
        helper(board, i + 1, j);
        helper(board, i - 1, j);
        helper(board, i, j - 1);
        helper(board, i, j + 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();     // Number of rows
        int n = board[0].size();  // Number of columns

        // Step 1: Mark all 'O's connected to borders as 'S'
        for (int i = 0; i < m; i++) {
            helper(board, i, 0);      // Left column
            helper(board, i, n - 1);  // Right column
        }
        for (int j = 0; j < n; j++) {
            helper(board, 0, j);      // Top row
            helper(board, m - 1, j);  // Bottom row
        }

        // Step 2: Flip surrounded 'O's to 'X', and restore 'S' to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';     // Surrounded region
                if (board[i][j] == 'S')
                    board[i][j] = 'O';     // Safe region connected to border
            }
        }
    }
};
