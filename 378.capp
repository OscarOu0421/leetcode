// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1], mid;
        int ret;

        while (l <= r) {
            mid = (l + r) / 2;
            int i = 0, j = n-1, total = 0;
            for (; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid)
                    j--;
                total += j+1;
            }
            if (total >= k) {
                ret = mid;
                r = mid-1;
            } else
                l = mid + 1;
        }
        return ret;
    }
};
