// Time Complexity: O(m * n * 4^L) 
// Space Complexity: O(L) — Depth of recursion stack (where L is the length of the word)

class Solution {
public:
    // Depth-First Search (DFS) function to explore possible word paths
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int cur) {
        int m = board.size();
        int n = board[0].size();

        // Out-of-bound check
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Character mismatch check
        if (word[cur] != board[i][j])
            return false;

        // Word fully matched
        if (cur == word.size() - 1)
            return true;

        // Mark the current cell as visited (temporary marker)
        char tmp = board[i][j];
        board[i][j] = '*';  

        // Explore all 4 possible directions
        bool ret = dfs(board, word, i-1, j, cur + 1) || // Up
                   dfs(board, word, i+1, j, cur + 1) || // Down
                   dfs(board, word, i, j-1, cur + 1) || // Left
                   dfs(board, word, i, j+1, cur + 1);   // Right
        
        // Restore the original character (backtracking)
        board[i][j] = tmp;

        return ret;
    }

    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Iterate through each cell to start the DFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) // Start DFS from each cell
                    return true;
            }
        }
        return false; // Word not found
    }
};
