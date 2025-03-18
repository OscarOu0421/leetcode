// TC: O(n)
// SC: O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        int bits = 0;

        for (int l = 0, r = 0; r < n; r++) {
            /* delete left side that make the current add right side window is nice */
            while (bits & nums[r]) {
                bits ^= nums[l++];
            }
            bits |= nums[r];
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
