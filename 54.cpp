// TC: O(m * n)
// SC: O(1)
class Solution {
public:
    // Traverse the matrix in one of four directions and mark visited cells
    void traverse(vector<vector<int>>& matrix, int &x, int &y, int direct, vector<int> &ret) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (direct == 0) { // Move right
            while (y < n && matrix[x][y] != 101) {
                ret.push_back(matrix[x][y]);
                matrix[x][y] = 101; // Mark visited
                y++;
            }
            y--; // Adjust position
            x++; // Change direction
        } else if (direct == 1) { // Move down
            while (x < m && matrix[x][y] != 101) {
                ret.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                x++;
            }
            x--;
            y--;
        } else if (direct == 2) { // Move left
            while (y >= 0 && matrix[x][y] != 101) {
                ret.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                y--;
            }
            y++;
            x--;
        } else { // Move up
            while (x >= 0 && matrix[x][y] != 101) {
                ret.push_back(matrix[x][y]);
                matrix[x][y] = 101;
                x--;
            }
            x++;
            y++;
        }
    }

    // Main function to collect elements in spiral order
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int direct = 0; // Direction: 0=right, 1=down, 2=left, 3=up
        int x = 0, y = 0; // Start position
        vector<int> ret;

        while (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] != 101) {
            traverse(matrix, x, y, direct, ret);
            direct = (direct + 1) % 4; // Change direction cyclically
        }
        return ret;
    }
};

