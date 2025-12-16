/*
 Time Complexity (TC):
 - O(n * n!)
   There are n! permutations, and copying each permutation takes O(n).

 Space Complexity (SC):
 - O(n)
   Used by the recursion stack and the visited array.
   (Result storage not counted.)
*/
class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& used,
             vector<int>& path, vector<vector<int>>& res) {

        // One complete permutation is formed
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        // Try every unused number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            path.push_back(nums[i]);

            // Explore
            dfs(nums, used, path, res);

            // Un-choose (backtrack)
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        dfs(nums, used, path, res);
        return res;
    }
};
