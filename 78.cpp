// Time: O(n * 2^n)
// Space: O(1)
/*
Using [1, 2, 3] as an example, the iterative process is like:

1. Initially, one empty subset [[]]
2. Adding 1 to []: [[], [1]];
3. Adding 2 to [] and [1]: [[], [1], [2], [1, 2]];
4. Adding 3 to [], [1], [2] and [1, 2]: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret{{}};

        for (auto num : nums) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                ret.push_back(ret[i]);
                ret.back().push_back(num);
            }
        }

        return ret;
    }
};
