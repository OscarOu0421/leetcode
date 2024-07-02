// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, ret = INT_MAX;

        for (; r < n; r++) {
            sum += nums[r];

            /*
             * sum is larger than or equal to target, means the window is valid
             * because the result shoild be minimum size, then we should increase the l to decrease the sum.
             */
            while (sum >= target) {
                ret = min(ret, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ret == INT_MAX ? 0 : ret;
    }
};
