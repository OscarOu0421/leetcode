// TC: O(2^n + nlogn) Each element can either be included or excluded in the combination. In the worst case, every possible subset is explored.
// SC: O(n) The recursion depth is at most n in the worst case.
class Solution {
public:
    // Recursive backtracking function to find combinations
    void traverse(vector<int> &candidates, int start, int target, 
                  vector<int> &path, vector<vector<int>> &ret) {

        // Base case: if target is zero, add the current path as a valid combination
        if (target == 0) {
            ret.push_back(path);
            return;
        }

        // Base case: if target becomes negative, stop exploring this path
        if (target < 0) {
            return;
        }
        
        // Iterate through candidates starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {
            // Add the current candidate to the path
            path.push_back(candidates[i]);

            // Recursive call: move to the next index (i + 1) and reduce target
            traverse(candidates, i + 1, target - candidates[i], path, ret);

            // Backtrack: remove the last element to explore other combinations
            path.pop_back();

            // Skip duplicates to avoid generating duplicate combinations
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }

    // Main function to initiate combination search
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;  // Stores all valid combinations
        vector<int> path;         // Tracks the current combination

        // Sort the candidates to efficiently skip duplicates
        sort(candidates.begin(), candidates.end());

        // Start recursive backtracking from index 0
        traverse(candidates, 0, target, path, ret);
        return ret;
    }
};
