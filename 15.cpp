// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    void twosum(vector<int> &nums, int i, vector<vector<int>> &ret) {
        int n = nums.size();
        for (int j = i+1, k = n-1; j < k;) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                /* Avoid to calculate 2nd  and 3rd numbers */
                if (j == 0 || nums[j-1] != nums[j] || k == n-1 || nums[k] != nums[k+1])
                    ret.push_back(vector<int>{nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (sum > 0)
                k--;
            else
                j++;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;

        /*
         * The key idea is the same as the TwoSum problem.
         * We fix the 1st number, and solve the TwoSum problem with 2nd and 3rd numbers.
         */
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            /* Avoid to calculate dup 1st number */
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            twosum(nums, i, ret);
        }
        return ret;
    }
};
