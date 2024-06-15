// Time: O(nlogn), sorting the vector, removeing/adding priority queue
// Space: O(n), vector and priority queue
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ret = 0, sumS = 0;
        vector<pair<int, int>> v(n);
        priority_queue<int, vector<int>, greater<int>> minq;

        for (int i = 0; i < n; i++) {
            v[i] = {efficiency[i], speed[i]};     
        }
        /*
         * sorting vector with num2[i] descending order.
         * we iterate vector with current index i, then v[i].first ensure be
         * min nums2 from 0 to i.
         */
        sort(rbegin(v), rend(v));

        for (auto [e, s] : v) {
            sumS += s;
            minq.push(s);
            /*
             * Keep priority queue size equals to k
             * if size bigger than k, pop min nums1[i]
             */
            if (minq.size() > k) {
                sumS -= minq.top();
                minq.pop();
            }
            ret = max(ret, sumS * e);
        }
        return ret % (int)(pow(10, 9) + 7);
    }
};
