// TC: O(n)
// SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;

        for (auto i : nums) {
            sum -= i;
        }
        return sum;
    }
};
