// Time: O(n)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;

        for (auto interval : intervals) {
            if (newInterval[0] <= interval[1]) {
                // non-overlap for new interval
                if (newInterval[1] < interval[0]) {
                    ret.push_back(newInterval);
                    newInterval[0] = INT_MAX;
                }
                // overlap for new interval
                else {
                    newInterval[0] = min(interval[0], newInterval[0]);
                    newInterval[1] = max(interval[1], newInterval[1]);
                    continue;
                }
            }
            // non-overlap before new interval
            ret.push_back(interval);
        }
        if (newInterval[0] != INT_MAX)
            ret.push_back(newInterval);
        return ret;
    }
};
