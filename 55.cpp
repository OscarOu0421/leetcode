class Solution {
public:
    /*
     * Time Complexity: O(n)
     *   - Traverse the array once.
     *
     * Space Complexity: O(1)
     *   - Uses constant extra space.
     */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;  // Farthest index that can be reached so far

        for (int i = 0; i < n; i++) {
            // If current index is beyond reachable range, jump is impossible
            if (i > reach)
                return false;

            // Update the farthest reachable index
            reach = max(reach, i + nums[i]);
        }

        // Successfully reached or passed the last index
        return true;
    }
};
