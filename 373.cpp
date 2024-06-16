// Time: O(klogk)
// Space: O(k)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size(), sum = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minq;
        vector<vector<int>> ret;

        if (n1 == 0 || n2 == 0 || k == 0)
            return ret;
        
        /*
         * type of minq is {sum of nums1[i] and nums2[j], {i, j}}
         * for every numbers in nums1, its best partner always start from nums2[0]
         */
        for (int i = 0; i < n1 && i < k; i++) {
            minq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!minq.empty() && k--) {
            int sum = minq.top().first;
            int i = minq.top().second.first;
            int j = minq.top().second.second;
            minq.pop();
            ret.push_back({nums1[i], nums2[j]});
            if (j + 1 == n2)
                continue;
            /*
             * next candidate should be nums1[i] + nums2[j+1]
             */
            minq.push({nums1[i] + nums2[j+1], {i, j+1}});
        }
        return ret;
    }
};
