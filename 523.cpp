// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int cur = 0;
        /*
         * Suppose sum_i represents the sum from index 0 to index i,
         * once we find a mod that has been seen, then we get answer
         *
         * current:  sum_i = m*k + modk
         * previous: sum_j = n*k + modk
         * sum_i - sum_j = (m-n)*k is multiple of k
         * 
        if (nums.size() < 2)
            return false;

        /*
         * <0, -1> can allow it to return true when cur % k = 0
         *
         * for example nums = [1, 2, 3], k = 6
         * then the remainders are [1, 3, 0]
         * now 1+2+3=6 which is actually a multiple of 6 and hence 0 should be
         * stored in the hashmap.
         *
         * why -1?
         * for example nums[6], k = 6
         * then 0-(-1)=1 is not greater than 1.
         */
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            cur = (cur + nums[i]) % k;
            if (map.find(cur) != map.end()) {
                if (i - map[cur] > 1)
                    return true;
            } else
                map[cur] = i;
        }
        return false;
    }
};
