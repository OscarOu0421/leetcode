/*
 * Problem: Leetcode 216 - Combination Sum III
 *
 * Time Complexity: O(C(9, k))
 *   - We generate combinations by picking k numbers from 1 to 9 (no repetition).
 *   - There are at most C(9, k) possible combinations.
 *   - Each combination is built recursively, so overall time is O(C(9, k)).
 *
 * Space Complexity: O(k)
 *   - Maximum depth of recursion is k (size of each combination).
 *   - Result storage uses O(C(9, k) * k), but path stack uses O(k).
 */

class Solution {
public:
    // Helper function to recursively build combinations
    void dfs(int k, int n, int i, vector<int> path, vector<vector<int>> &ret) {
        // Base case: if we have k numbers and the sum is n, add to result
        if (path.size() == k && n == 0) {
            ret.push_back(path);
            return;
        }
        // Pruning: if we exceed k numbers, or n becomes negative, or number > 9
        if (path.size() > k || n < 0 || i == 10)
            return;

        // Include current number i
        path.push_back(i);
        dfs(k, n - i, i + 1, path, ret); // move to next number
        path.pop_back(); // backtrack

        // Exclude current number i and move to the next
        dfs(k, n, i + 1, path, ret);
    }

    // Main function to start DFS from number 1
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        dfs(k, n, 1, {}, ret);
        return ret;
    }
};
