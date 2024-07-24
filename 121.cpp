// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = prices[0];
        int maxP = prices[0];
        int ret = 0;

        for (auto p : prices) {
            /*
             * These price is min, so you could buy it,
             * and you need to update the sell price, because you could not sell 
             * this stuck before.
             */
            if (p < minP) {
                maxP = p;
                minP = p;
            }
            if (p > maxP) {
                maxP = p;
            }
            ret = max(ret, maxP - minP);
        }
        return ret;
    }
};
