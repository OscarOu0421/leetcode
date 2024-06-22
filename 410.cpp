// TC: O(nlogm), n is the length of the array, m is sum(array) - max(array)
// SC: O(1)
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;

        /*
         * Find the largest sum of the subarray
         * l: each element build one subarray, the min is the max value of the array.
         * r: Entire array build one subarray, the max is the sum of the array.
         */
        for (auto num : nums) {
            l = max(l, num);
            r += num;
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            int need = 1;
            int cur = 0;
            for (auto num : nums) {
                /* 
                 * add this number would exceed the largest sum limitation.
                 * Build the new subarray to store this number
                 */
                if (cur + num > m) {
                    cur = 0;
                    need++;
                }
                cur += num;
            }
            if (need > k)
                l = m + 1;
            else
                r = m;
        }
        return r;
    }
};
