// TC: O(n)
// SC: O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), count = 0, ret = 0;

        for (; r < n; r++) {
            if (nums[r] & 1) {
                k--;
                /*
                 * if we counter k+1 odd values, we should reset the count for 
                 * 0 to k odd cases. than start calculate count for 1 to k+1.
                 */
                count = 0;
            }
            /* 
             * k == 0 means nums[l:r]contains k odd values,
             * we can reduce the window size until subarray not contains k odd values
             *
             * For example: nums:[2,2,2,1,2,2,1,2,2,2]
             * if r at 6, k will be 0
             * we would set l to 4, then we could add 4 cases to result
             * 1. [2,2,2,1,2,2,1]
             * 2. [2,2,1,2,2,1]
             * 3. [2,1,2,2,1]
             * 4. [1,2,2,1]
             */
            while (k == 0) {
                k += nums[l++] & 1;
                count ++;
            }
            /*
             * if r at 7, we could add current count "4" to result, because all 4 cases added the nums[r] can be the new 4 cases.
             */
            ret += count;
        }
        return ret;
    }
};
