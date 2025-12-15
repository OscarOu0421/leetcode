/*
 Time Complexity (TC):
 - O(1)
   The board size is fixed at 9x9, so the number of operations is constant.

 Space Complexity (SC):
 - O(1)
   Extra space used for rows, cols, and grids is constant (9 x 9).
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();  // n = 9 for a standard Sudoku

        // rows[i][num]    -> whether number 'num' already appears in row i
        // cols[j][num]    -> whether number 'num' already appears in column j
        // grids[k][num]   -> whether number 'num' already appears in 3x3 subgrid k
        vector<vector<bool>> rows(n, vector<bool>(10, false));
        vector<vector<bool>> cols(n, vector<bool>(10, false));
        vector<vector<bool>> grids((n / 3) * (n / 3), vector<bool>(10, false));

        // Traverse every cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Skip empty cells
                if (board[i][j] == '.')
                    continue;

                // Convert character digit to integer (1 ~ 9)
                int num = board[i][j] - '0';

                // Compute subgrid index
                // For 9x9 board: k = (i / 3) * 3 + (j / 3)
                int k = (i / 3) * (n / 3) + (j / 3);

                // Check if number already exists
                if (rows[i][num] || cols[j][num] || grids[k][num])
                    return false;

                // Mark number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                grids[k][num] = true;
            }
        }
        return true;
    }
};/*
 Time Complexity (TC):
 - O(1)
   The board size is fixed at 9x9, so the number of operations is constant.

 Space Complexity (SC):
 - O(1)
   Extra space used for rows, cols, and grids is constant (9 x 9).
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();  // n = 9 for a standard Sudoku

        // rows[i][num]    -> whether number 'num' already appears in row i
        // cols[j][num]    -> whether number 'num' already appears in column j
        // grids[k][num]   -> whether number 'num' already appears in 3x3 subgrid k
        vector<vector<bool>> rows(n, vector<bool>(10, false));
        vector<vector<bool>> cols(n, vector<bool>(10, false));
        vector<vector<bool>> grids((n / 3) * (n / 3), vector<bool>(10, false));

        // Traverse every cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Skip empty cells
                if (board[i][j] == '.')
                    continue;

                // Convert character digit to integer (1 ~ 9)
                int num = board[i][j] - '0';

                // Compute subgrid index
                // For 9x9 board: k = (i / 3) * 3 + (j / 3)
                int k = (i / 3) * (n / 3) + (j / 3);

                // Check if number already exists
                if (rows[i][num] || cols[j][num] || grids[k][num])
                    return false;

                // Mark number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                grids[k][num] = true;
            }
        }
        return true;
    }
};
