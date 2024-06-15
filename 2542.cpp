// Time: O(nlogn), sorting vector and removeing/adding priority queue at most n times.
// Space: O(n), vector and priority queue
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long sum1 = 0, ret = 0;
        vector<pair<int, int>> v(n);
        priority_queue<int, vector<int>, greater<int>> minq;
        
        for (int i = 0; i < n; i++) {
            v[i] = {nums2[i], nums1[i]};
        }
        /*
         * sorting vector with num2[i] descending order.
         * we iterate vector with current index i, then v[i].first ensure be
         * min nums2 from 0 to i.
         */
        sort(rbegin(v), rend(v));

        for (auto [n2, n1] : v) {
            sum1 += n1;
            minq.push(n1);
            /*
             * Keep priority queue size equals to k
             * if size bigger than k, pop min nums1[i]
             */
            if (minq.size() > k) {
                sum1 -= minq.top();
                minq.pop();
            }
            /*
             * if the size equals to k, n2 is the min nums2[i] from index 0 to i.
             */
            if (minq.size() == k) {
                ret = max(ret, sum1 * n2);
            }
        }
        return ret;
    }
};
