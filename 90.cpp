// Time Complexity: O(2^n) - At most 2^n subsets are generated (n = nums.size())
// Space Complexity: O(2^n) - For storing all subsets in 'ret'
// This function returns all unique subsets of a list with possible duplicate elements.

class Solution {
public:
    // Recursive helper function to generate subsets
    void helper(vector<int> &nums, vector<vector<int>> &ret, int start, vector<int> path) {
        ret.push_back(path);  // Add the current subset to the result

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i != start && nums[i] == nums[i-1])
                continue;

            path.push_back(nums[i]);              // Include nums[i] in the current subset
            helper(nums, ret, i + 1, path);       // Recurse with next index
            path.pop_back();                      // Backtrack by removing the last added element
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;                  // To store all unique subsets

        sort(nums.begin(), nums.end());           // Sort to group duplicates together
        helper(nums, ret, 0, {});                 // Start backtracking from index 0 with empty path
        return ret;                               // Return all unique subsets
    }
};
