// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        int end = 0;
        int ret = 0;

        if (n <= 1)
            return ret;
        /*
         * Greedy
         * current jump from begin to end.
         * reach is farthest distance in current jump [begin, end].
         */
        for (int i = 0; i < n && i <= reach; i++) {
            reach = max(i + nums[i], reach);
            /*
             * current jump reachs end, then trigger another jump
             */
            if (i == end) {
                ret++;
                end = reach;
            }
            if (end >= n-1)
                break;
        }
        return ret;
    }
};
