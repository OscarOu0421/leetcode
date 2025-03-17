// TC: O(n)
// SC: O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(501, 0);

        for (auto i : nums) {
            v[i]++;
        }
        for (auto i : v) {
            if (i % 2)
                return false;
        }
        return true;
    }
};
