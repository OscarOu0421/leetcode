// TC: O(nlogm), n is the length of the array, m is sum(array) - max(array)
// SC: O(1)
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;

        for (auto weight : weights) {
            l = max(l, weight);
            r += weight;
        }

        while (l < r) {
            int m = l + (r - l ) / 2;
            int cur = 0;
            int need = 1;
            for (auto weight : weights) {
                if (cur + weight > m) {
                    need++;
                    cur = 0;
                }
                cur += weight;
            }
            if (need > days)
                l = m + 1;
            else
                r = m;
        }
        return r;
    }
};
