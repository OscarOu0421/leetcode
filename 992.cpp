// TC: O(n)
// SC: O(k)
class Solution {
public:
    int atmostK(vector<int> &nums, int k) {
        int l = 0, r = 0, n = nums.size(), ret = 0, count = 0;
        unordered_map<int, int> map;

        for (; r < n; r++) {
            /*
             * if nums[r] is first appearment in the array, decrease the k
             */
            if (map[nums[r]]++ == 0) {
                k--;
            }
            
            /*
             * if k < 0 means this window is invalid, so we need to 
             * increase the l to make the window valid.
             */
            while (k < 0) {
                if (--map[nums[l]] == 0)
                    k++;
                l++;
            }
            /* 
             * the result is the number of the subarray at most k distinct elements,
             * so if k is 0, 1, 2, ... also valid.
             */
            ret += r - l + 1;
        }
        return ret;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*
         * atmostK(): the number of subarrays with at most K distinct elements
         */
        return atmostK(nums, k) - atmostK(nums, k - 1);
    }
};
