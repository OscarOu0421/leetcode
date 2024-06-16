// Time: O(4^n), 4 directions at most n stacks
// Space: O(n), at most n tims for stack
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return false;
        
        // current character of board is not equals to  current character of the word
        if (board[i][j] != word[k])
            return false;
        
        // arriave at last character of the word
        if (k == word.size()-1)
            return true;
        
        char tmp = board[i][j];
        board[i][j] = '.';
        bool up = dfs(board, word, i+1, j, k+1);
        bool down = dfs(board, word, i-1, j, k+1);
        bool left = dfs(board, word, i, j-1, k+1);
        bool right = dfs(board, word, i, j+1, k+1);
        board[i][j] = tmp;

        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
