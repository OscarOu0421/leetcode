// Time: O(32n)
// Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum;
        int ret = 0;
        // Traverse each bits from int.
        for (int i = 0; i < 32; i++) {
            sum = 0;
            // Sum all bit at i index of all numbers
            for (auto num : nums) {
                num = num >> i;
                sum += num & 1;
            }
            /*
             * Mod 3 to remove the bit that appears 3 times,
             * then only remain the bit that appares 1 times.
             */
            sum %= 3;
            // Recover remained bit to original index and add it.
            ret += sum << i;
        }
        return ret;
    }
};
