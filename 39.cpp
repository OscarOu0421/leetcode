// TC: O(2^n), n is the size of candidates, the worst case is all combination of candidates
// SC: O(t/d), where t is the target and d is the smallest candidate, representing the depth of the recursion.
class Solution {
public:
    // Helper function for recursion with backtracking
    void recursive(vector<int> &candidates, int start, int target, vector<int> &path, vector<vector<int>> &ret) {
        // Base case: If the remaining target is zero, we've found a valid combination
        if (target == 0) {
            ret.push_back(path); // Add the valid combination to the result
            return;
        }
        // Base case: If target becomes negative, the current path is invalid
        if (target < 0)
            return;
        
        // Iterate through the candidates starting from the 'start' index
        for (int i = start; i < candidates.size(); i++) {
            // Add the current candidate to the path
            path.push_back(candidates[i]);
            
            // Recursively try the next combination with reduced target
            // 'i' instead of 'i + 1' allows repeated elements in the combination
            recursive(candidates, i, target - candidates[i], path, ret);
            
            // Backtrack: Remove the last element to explore other paths
            path.pop_back();
        }
    }

    // Main function to find all unique combinations that sum to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;  // Store all valid combinations
        vector<int> path;        // Track the current path (combination)
        
        // Start the recursive exploration from index 0
        recursive(candidates, 0, target, path, ret);
        
        return ret;  // Return all valid combinations
    }
};


