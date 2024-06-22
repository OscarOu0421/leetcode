// TC : O(nlogm), n is the length of the array, m is the sum of the array.
// SC : O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        unsigned int r = 0;

        for (auto bananas : piles) {
            r += bananas;
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            int hours = 0;
            for (auto bananas : piles) {
                int result = bananas / m;
                int carry = bananas % m ? 1 : 0;
                hours += result + carry;
            }
            if (hours > h)
                l = m + 1;
            else
                r = m;
        }
        return r;
    }
};
