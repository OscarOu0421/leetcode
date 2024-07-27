// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 1;

        /* Sorting with x_start */
        sort(points.begin(), points.end());
        for (int i = 1; i < n; i++) {
            /* current start x exceeds previous end x, means we need the othre arrow. */
            if (points[i][0] > points[i-1][1]) {
                ret++;
            /* 
             * modify current end x, for example, [1, 10], [3, 8]
             * when we arraive at [3, 8], then the maximim x we can shoot is 8, not 10.
             */
            } else {
                points[i][1] = min(points[i-1][1], points[i][1]);
            }
        }
        return ret;
    }
};
