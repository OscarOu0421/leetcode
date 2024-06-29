// TC: O(n), all elements are pushed and popped at most once
// SC: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> dp(n, 0);
        int ret = nums[0];

        /*
         * dp[i] means the max sum we can get from nums[:i], and nums[i] is included
         * dp[i] = max(dp[i-k], ... , dp[i-1], 0) + nums[i]
         */
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
            if (deq.size())
                dp[i] += deq.front();
            ret = max(ret, dp[i]);

            while (!deq.empty() && deq.back() < dp[i])
                deq.pop_back();
            
            if (dp[i] > 0)
                deq.push_back(dp[i]);

            /*
             * we always keep the size of the window with length k, from i-k to i,
             * so in the next iteration nums[i+1], we don't need the nums[i-k]
             */
            if (i >= k && deq.size() && deq.front() == dp[i-k])
                deq.pop_front();
        }

        return ret;
    }
};
