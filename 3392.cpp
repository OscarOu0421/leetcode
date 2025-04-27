class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ret = 0;
        
        for (int l = 0, r = 2; r < nums.size(); r++, l++) {
            if ((nums[r] + nums[l]) * 2 == nums[l+1])
                ret++;
        }
        return ret;
    }
};
