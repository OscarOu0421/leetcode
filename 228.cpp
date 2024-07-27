// TC:O(n)
// SC:O(1)
class Solution {
public:
    string getString(int start, int end) {
        string s = "";
        if (start == end)
            s = to_string(start);
        else
            s = to_string(start) + "->" + to_string(end);
        return s;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int start;
        int end;

        if (nums.size() == 0)
            return ret;
        start = nums[0];
        end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - 1 != end) {
                ret.push_back(getString(start, end));
                start = nums[i];
                end = nums[i];
            } else {
                end = nums[i];
            }
        }
        ret.push_back(getString(start, end));
        return ret;
    }
};
