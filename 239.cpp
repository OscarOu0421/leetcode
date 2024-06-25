// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxq;
        vector<int> ret;
        int l = 0, r = 0, sum = 0;
        
        for (; r < nums.size(); r++) {
            /*
             * maintain the largest elements in the maxq,
             * remove all elements smaller than nums[r]
             */
            while (!maxq.empty() && maxq.back() < nums[r])
                maxq.pop_back();
            
            maxq.push_back(nums[r]);

            /* the window size is smaller than k */
            if (r - l + 1 < k)
                continue;
            
            /*
             * at each etiration, the first element is largest,
             * add it into result
             */
            ret.push_back(maxq.front());
            /*
             * if nums[l] is present in the maxq, it must be the biggest element
             * nums[l] >= nums[x], x = l+1, ... , r.
             * else nums[l] have already been removed.
             */
            if (maxq.front() == nums[l])
                maxq.pop_front();
            l++;
        }
        return ret;
    }
};
