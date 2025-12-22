class Solution {
public:
    /*
     * Time Complexity: O(2^n)
     *   - Each element has two choices (include or exclude),
     *     resulting in 2^n subsets.
     *
     * Space Complexity: O(n)
     *   - Recursion depth is at most n (call stack).
     *   - Path vector also uses up to n space.
     *   - Output space (all subsets) is not counted.
     */
    void helper(vector<int> nums, int i, vector<vector<int>> &ret, vector<int> path) {
        // Base case: all elements have been considered
        if (i == nums.size()) {
            ret.push_back(path);
            return;
        }

        // Choice 1: include nums[i]
        path.push_back(nums[i]);
        helper(nums, i + 1, ret, path);

        // Backtrack
        path.pop_back();

        // Choice 2: exclude nums[i]
        helper(nums, i + 1, ret, path);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;

        // Start DFS from index 0 with an empty path
        helper(nums, 0, ret, {});
        return ret;
    }
};

