// TC: O(n)
// SC: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n > 1)
            nums[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
        }
        return nums[n-1];
    }
};
