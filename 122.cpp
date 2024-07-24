// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret = 0;

        for (int i = 1; i < n; i++) {
            ret += max(prices[i] - prices[i-1], 0);
        }
        return ret;
    }
};
