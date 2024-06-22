// Time: O(nlogm), n is the length of the nums, m is the max of the nums
// Space: O(1)
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = nums[0];

        for (auto num : nums)
            r = max(r, num);

        while (l < r) {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (auto num : nums) {
                int result = num / m;
                int carry = (num % m) ? 1 : 0;
                sum += result + carry;
            }
            if (sum > threshold)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
