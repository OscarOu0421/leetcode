// Time Complexity: O(m * n * log(m * n)) - Sorting the entire grid's values
// Space Complexity: O(m * n) - Extra space used for the "values" vector
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int sum = 0; // Tracks total sum (not strictly needed but could be useful in modifications)
        int ret = 0; // Stores the final result (minimum number of operations)
        int median; // Median value used to minimize steps
        vector<int> values; // Flattened grid values for easier processing

        // Flatten the 2D grid into a 1D array
        for (auto row : grid) {
            for (auto value : row) {
                values.push_back(value);
            }
        }

        // Sort the array to identify the median efficiently
        sort(values.begin(), values.end());
        median = values[values.size() / 2];

        // Calculate the minimum operations required
        for (auto value : values) {
            // If the difference isn't divisible by x, it's impossible to equalize
            if (abs(median - value) % x) 
                return -1;
            
            // Accumulate the number of steps needed to reach the median
            ret += abs(median - value) / x;
        }
        return ret; // Return the total number of steps
    }
};
