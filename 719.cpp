class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r, mid, ret;

        sort(nums.begin(), nums.end());
        r = nums[n-1];

        //     4  62  100
        // 4.  0. 58. 96
        // 62.    0.  38
        // 100.       0
        while (l <= r) {
            mid = (l + r) / 2;
            int i = n-2, j = n-1, total = 0, max_dist = 0;
            for (; i >= 0; i--) {
                while (j > i && nums[j] - nums[i] > mid)
                    j--;
                if (i == j)
                    continue;
                total += j-i;
                max_dist = max(max_dist, nums[j] - nums[i]);
            }
            if (total >= k) {
                ret = max_dist;
                r = mid-1;
            } else
                l = mid+1;
        }
        return ret;
    }
};
