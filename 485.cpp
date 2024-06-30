// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), ret = 0, count = 0;

        for (; r < n; r++) {
            count = nums[r] == 1 ? count + 1 : 0;
            ret = max(ret, count);
        }
        return ret;
    }
};
