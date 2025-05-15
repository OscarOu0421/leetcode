// Time Complexity: O(n)
//   - Each element is processed once with at most 2 extra comparisons (since nums[i] ∈ {1, 2, 3})
// Space Complexity: O(1)
//   - Fixed-size vector of length 4 is used regardless of input size

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;

        // curlen[i] stores the length of the longest increasing subsequence ending with i
        // Since nums[i] can only be 1, 2, or 3, we use a vector of size 4
        vector<int> curlen(4, 0);  // Index 0 is unused

        for (int i = 0; i < n; i++) {
            // Increment length of subsequence ending with nums[i]
            curlen[nums[i]]++;

            // Update curlen[nums[i]] based on smaller numbers (to maintain increasing property)
            for (int j = 1; j < nums[i]; j++) {
                curlen[nums[i]] = max(curlen[j] + 1, curlen[nums[i]]);
            }

            // Update maxlen to track the longest increasing subsequence length so far
            maxlen = max(maxlen, curlen[nums[i]]);
        }

        // The minimum number of operations is the total size minus the length of the longest increasing subsequence
        return n - maxlen;
    }
};
