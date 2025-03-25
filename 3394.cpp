// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    // Checks if there are at least 3 distinct non-overlapping intervals
    bool isValid(vector<vector<int>> coordinates, int n) {
        int l = 0, r = 0, cont = 0;

        // Sort coordinates based on starting points
        sort(coordinates.begin(), coordinates.end());
        for (int i = 0; i < coordinates.size(); i++) {
            // Core logic: Handling overlapping intervals
            if (coordinates[i][0] < r)  // If overlap, extend the right boundary
                r = max(r, coordinates[i][1]);
            else {  // Non-overlapping segment starts
                cont++;  // Increment distinct interval count
                l = coordinates[i][0];
                r = coordinates[i][1];
            }
            if (cont == 3)  // Early exit if 3 segments are identified
                return true;
        }
        return false;
    }

    // Determines if there are valid cut segments in either x or y coordinates
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_coordinates, y_coordinates;

        // Extract x and y coordinate intervals from rectangles
        for (auto rec : rectangles) {
            x_coordinates.push_back({rec[0], rec[2]});
            y_coordinates.push_back({rec[1], rec[3]});
        }
        return isValid(x_coordinates, n) || isValid(y_coordinates, n);
    }
};

