// Time Complexity: O(C(n, k)) — where C(n, k) = n! / (k!(n-k)!)
// Each combination takes O(k) time to construct
// Space Complexity: O(k) for recursion stack depth and path vector

class Solution {
public:
    // Recursive helper function to build combinations
    void helper(int n, int k, int start, vector<vector<int>> &ret, vector<int> path) {
        // Base case: combination of size k completed
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }

        // Stop recursion if start goes beyond n
        if (start > n)
            return;
        
        // Try all possible next numbers from 'start' to 'n'
        for (int i = start; i <= n; i++) {
            path.push_back(i);  // Choose number i
            helper(n, k, i + 1, ret, path);  // Recurse with i+1
            path.pop_back();  // Backtrack
        }
    }

    // Main function to return all k-combinations from 1 to n
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        helper(n, k, 1, ret, {});  // Start backtracking from 1
        return ret;
    }
};

