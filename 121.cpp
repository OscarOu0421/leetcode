// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int maxP = 0;

        for (auto price : prices) {
            minP = min(price, minP);
            maxP = max(maxP, price - minP);
        }
        return maxP;
    }
};
