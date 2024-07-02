// TC: O(n)
// SC: O(k)
class Solution {
public:
    /*
     * the maximum length of the subarray with at most k distinct number
     */
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, n = fruits.size(), k = 2, ret = 0;
        unordered_map<int, int> count;
        
        for (; r < n; r++) {
            /* first appearment in the window */
            if (count[fruits[r]]++ == 0) {
                k--;
            }
            
            /* window is invalid, increase l to make window valid. */
            while (k < 0) {
                if (--count[fruits[l]] == 0) {
                    k++;
                }
                l++;
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};
