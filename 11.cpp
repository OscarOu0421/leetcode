// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
         * The widest container is a good container due to its width.
         * we start with its.
         */
        int l = 0, r = height.size() - 1, ret = 0;
        
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ret = max(ret, area);
            /*
             * All other container are less width, thus we need to 
             * hold the higher height. the lower height doesn't 
             * support the higher water level, just removed.
             */
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ret;
    }
};
