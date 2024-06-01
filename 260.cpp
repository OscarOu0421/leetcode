// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2, 0);
        int xorResult = 0;

        // Get the two different numbers xor result.
        for (auto num : nums) {
            xorResult ^= num;
        }

        /* 
         * get the rightest set bit, the first bit that is 
         * different bit between two different numbers.
         * the first number is 0, the second number is 1, or
         * the first number is 1, the second number is 0.
         */
        /* 
         * int range between -2^31 to 2^31-1.
         * For example: [1,1,0,-2^31]
         * the xorResult is 0 xor -2^31, then -xorResult is overflow.
         * then we need to cast (unsigned int)
         */
        xorResult &= -(unsigned int)xorResult;

        // We divide all numbers into two groups,
        // one is the righest bit set.
        // the other is the rightes bit set unset.
        // xor all numbers in each group, we can find a number in each group.
        for (auto num : nums) {
            if (num & xorResult) {
                ret[0] ^= num;
            } else {
                ret[1] ^= num;
            }
        }
        return ret;
    }
};
