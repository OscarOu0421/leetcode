// TC: O(n)
// SC: O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), ret = 0;

        for (; r < n; r++) {
            /*
             * if nums[r] is 0, we need to use one k to flip this integer.
             */
            k -= nums[r] == 0 ? 1 : 0;

            /*
             * k < 0 means current conescutive window is invalid, 
             * we need to decrease the window to make current window is valid
             *
             * why we should not use k == 0?
             * k == 0 means we counter last valid 0, but there may some 1 behind
             * the 0.
             * For example: array: [1, 0, 0, 1], k = 2
             * if we use k == 0, we would stop the max window size with array[0:2]
             * but array[3] is still valid, and it can add into the window.
             */
            while (k < 0 && l <= r) {
                k += nums[l++] == 0 ? 1 : 0;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
