/*
 * Problem: Given a 2D grid of integers, return a matrix where each cell (i, j)
 * contains the product of all elements in the grid except the element at (i, j),
 * modulo 12345.
 *
 * Approach:
 * - Traverse the grid once to compute prefix products and store them in the result matrix.
 * - Traverse the grid again in reverse to compute suffix products and multiply with existing values.
 * - The result at each (i, j) will be the product of all elements except grid[i][j].
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n) for the result matrix
 */

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int modulo = 12345;
        vector<vector<int>> ret(m, vector<int>(n, 1));

        int prefix = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] %= modulo;          // Ensure values are within modulo
                ret[i][j] = prefix;            // Store prefix product so far
                prefix *= grid[i][j];          // Update prefix
                prefix %= modulo;
            }
        }

        int suffix = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                ret[i][j] *= suffix;           // Multiply with suffix product
                ret[i][j] %= modulo;
                suffix *= grid[i][j];          // Update suffix
                suffix %= modulo;
            }
        }
        return ret;
    }
};
