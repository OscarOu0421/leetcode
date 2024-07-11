// TC: O(n)
// SC: O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int i = 0, n = nums.size(), ret = n + 1;
        vector<long long> prefixSum(n, 0);
        deque<int> deq;

        /*
         * prefixSum[i] means sum(nums[0], ... , nums[i])
         *
         * basic idea: for prefixSum[j], find the smallest i that
         * prefixSum[j] - prefixSum[i] >= k
         * prefixSum[j] - prefixSum[i] = sum(nums[i+1], ..., nums[j])
         */
        for (int i = 0; i < n; i++) {

            prefixSum[i] = nums[i] + (i > 0 ? prefixSum[i-1] : 0);
            if (prefixSum[i] >= k)
                ret = min(ret, i + 1);

            /*
             * 1. remove the worse candidates
             * 2. left an increasing queue list of candidates
             */
            while (!deq.empty() && prefixSum[i] <= prefixSum[deq.back()]) {
                deq.pop_back();
            }

            /*
             * We check with decresing size to find the best solution
             */
            while (!deq.empty() && prefixSum[i] - prefixSum[deq.front()] >= k) {
                ret = min(ret, i - deq.front());
                deq.pop_front();
            }

            deq.push_back(i);
        }
        return ret == n+1 ? -1 : ret;
    }
};
