// Time Complexity: O(m * n)
// Space Complexity: O(1) (In-place marking using the matrix itself)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false; // Tracks if the first row should be zeroed
        bool firstColZero = false; // Tracks if the first column should be zeroed

        // Step 1: Identify zeros and mark them in the first row/column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRowZero = true; // Mark first row
                    if (j == 0) firstColZero = true; // Mark first column
                    matrix[i][0] = 0; // Mark first column for row zeroing
                    matrix[0][j] = 0; // Mark first row for column zeroing
                }
            }
        }

        // Step 2: Zero out the marked cells (excluding first row/column)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
