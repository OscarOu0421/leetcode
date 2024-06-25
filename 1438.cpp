// TC: O(n)
// SC: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int l = 0, r = 0;

        for (; r < nums.size(); r++) {
            /*
             * At each iteration, we maintain the biggest elements in maxd.
             * Remove any element smaller than nums[l]
             */
            while (!maxd.empty() && nums[r] > maxd.back())
                maxd.pop_back();
            /*
             * At each iteration, we maintain the smallest elements in mind.
             * Remove any element bigger than nums[l]
             */
            while (!mind.empty() && nums[r] < mind.back())
                mind.pop_back();
            
            /*
             * Why do we always add nums[r] ?
             * As we will see below, we may have to remove an element
             * (may be nums[r-1] if l was r-1) from the beginning of the maxd/mind.
             * After that, we still need to know the max/min numbers from 
             * nums[l/l+1]...nums[r]
             */
            maxd.push_back(nums[r]);
            mind.push_back(nums[r]);
            /*
             * maxd holds the biggest elements from nums[l]...nums[r] in 
             * decreasing order.
             * So maxd[0] is the biggest element in the window nums[l]...nums[r]
             *
             * mind holds the smallest elements from nums[l]...nums[r] in 
             * increasing order.
             * So mind[0] is the smallest element in the window nums[l]...nums[r]
             *
             * maxd[0]-mind[0] is the biggest difference in the window 
             * nums[l]...nums[r]
             */
            if (maxd.front() - mind.front() > limit) {
                /*
                 * Why do we check only maxd[0]/mind[0] to remove A[i]?
                 * Take maxd as an example. In order for nums[l] to be 
                 * present in maxd, nums[l] >= nums[x], where x = l+1...r.
                 * In other words, it has to be the biggest element or 
                 * it would have already been removed. 
                 * The biggest element would be in maxd[0].
                 */
                if (maxd.front() == nums[l])
                    maxd.pop_front();
                if (mind.front() == nums[l])
                    mind.pop_front();
                l++;
            }
        }
        return r - l;
    }
};
