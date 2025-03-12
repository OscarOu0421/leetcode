// TC: O(n)
// SC: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n) {
            ret += n & 1;
            n = n >> 1;
        }
        return ret;
    }
};
