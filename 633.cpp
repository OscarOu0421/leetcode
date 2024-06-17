// Time: O(sqrt(n))
// Space: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned int l = 0, r = sqrt(c);
        
        while (l <= r) {
            unsigned int cur = l * l + r * r;
            if (cur < c)
                l++;
            else if (cur > c)
                r--;
            else
                return true;
        }
        return false;
    }
};
