class Solution {
public:
    /*
     * Time Complexity: O(log(m * n))
     *   - Binary search over the flattened matrix.
     *
     * Space Complexity: O(1)
     *   - Uses constant extra space.
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();          // Number of rows
        int n = matrix[0].size();       // Number of columns

        int l = 0;
        int r = m * n - 1;              // Treat matrix as a 1D array

        while (l < r) {
            int mid = l + (r - l) / 2;

            // Convert 1D index to 2D coordinates
            int i = mid / n;
            int j = mid % n;

            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        // Final check when l == r
        return matrix[l / n][l % n] == target;
    }
};

