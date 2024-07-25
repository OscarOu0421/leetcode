// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minq;
        vector<int> ret;
        
        for (auto num : nums) {
            minq.push(num);
        }
        while (!minq.empty()) {
            ret.push_back(minq.top());
            minq.pop();
        }
        return ret;
    }
};
