// Time Complexity: O(n^3), where n is the size of the digits array. We explore all permutations of 3 digits.
// Space Complexity: O(n) for recursion stack and visited array, and up to O(1000) for storing valid 3-digit numbers.

class Solution {
public:
    // Helper function for backtracking
    void helper(vector<int> &digits, vector<int> &path, unordered_set<int> &ret, vector<int> &visited) {
        // Base case: if 3 digits are chosen, form the number
        if (path.size() == 3) {
            int num = path[0] * 100 + path[1] * 10 + path[2];  // Combine digits into an integer
            ret.insert(num);  // Add to result set to ensure uniqueness
            return;
        }

        // Try each digit at the current position
        for (int i = 0; i < digits.size(); i++) {
            // Skip if:
            // 1. First digit is 0 (leading zero),
            // 2. Last digit is not even,
            // 3. Digit already used at this position
            if ((path.size() == 0 && digits[i] == 0) || 
                (path.size() == 2 && digits[i] % 2) || 
                visited[i])
                continue;

            visited[i] = true;             // Mark digit as used
            path.push_back(digits[i]);     // Choose the digit
            helper(digits, path, ret, visited);  // Recurse
            path.pop_back();               // Backtrack
            visited[i] = false;            // Unmark digit
        }
    }

    // Main function
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> set;        // To store unique results
        vector<int> path;              // Current number being formed
        vector<int> ret;               // Final sorted result
        vector<int> visited(n, false); // Track used digits

        helper(digits, path, set, visited); // Start DFS

        for (auto num : set)
            ret.push_back(num);       // Copy from set to result vector

        sort(ret.begin(), ret.end()); // Sort results as required
        return ret;
    }
};
