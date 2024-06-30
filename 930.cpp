// TC: O(n)
// SC: O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size(), ret = 0, count = 0;

        for (; r < n; r++) {
            /*
             * if nums[r] is 1, we can reduce the goal.
             * because nums[l:r-1] may be a valid nums with goal equals 0,
             * and it would have count cases,
             * then at nums[r] equals 1, we should culculate new count cases, 
             * so we need to reset the count.
             */
            if (nums[r] == 1) {
                goal--;
                count = 0;
            }

            /*
             * if goal is 0, we can advance the count when we increase the l
             * For example: [0, 1, 0, 1, 0], goal = 2
             * if r at 3, we can get the count 2 for the following cases:
             * 1. [0, 1, 0, 1]
             * 2. [*, 1, 0, 1]
             * and next iteration we can still add count 2 to the result for the cases:
             * 1. [0, 1, 0, 1, 0]
             * 2. [*, 1, 0, 1, 0]
             *
             * if goal less than 0, means it is invalid subarray, we should not
             * count this case.
             */
            while (goal <= 0 && l <= r) {
                count += goal == 0 ? 1 : 0;
                goal += nums[l++] == 1 ? 1 : 0;
            }
            
            ret += count;
        }

        return ret;
    }
};
