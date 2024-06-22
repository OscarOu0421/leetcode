// Time: O(nlog(m)), n is the length of the bloomDay, m is the max of the bloomDay
// Space: O(1)
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        unsigned int n = bloomDay.size(), left = 1, right = INT_MAX;
        
        if ((unsigned int)m * k > n)
            return -1;
        
        while (left < right) {
            unsigned int mid = left + (right - left) / 2;
            int flow = 0;
            int bouq = 0;
            for (auto bloom : bloomDay) {
                if (mid < bloom)
                    flow = 0;
                else {
                    flow++;
                    if (flow >= k) {
                        bouq++;
                        flow = 0;
                    }
                }
            }
            if (bouq < m)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
