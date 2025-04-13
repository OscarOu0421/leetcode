/*
 * Problem: 673. Number of Longest Increasing Subsequence
 *
 * Approach:
 * - Use Dynamic Programming to track:
 *     - `length[i]`: the length of the longest increasing subsequence ending at index i
 *     - `count[i]`: the number of such subsequences ending at i
 * - For each pair (j, i) where j < i:
 *     - If nums[j] < nums[i], then nums[i] can extend the subsequence ending at j
 *     - Update `length[i]` and `count[i]` accordingly
 * - After filling the DP arrays, sum all `count[i]` where `length[i]` equals the maximum LIS length
 *
 * Time Complexity: O(n^2)
 *   - Two nested loops over `n` elements
 * Space Complexity: O(n)
 *   - Two auxiliary arrays of size `n`
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int LISlength = 1;

        vector<int> length(n, 1); // length[i]: LIS length ending at i
        vector<int> count(n, 1);  // count[i]: number of LIS of that length ending at i

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i])
                    continue;

                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j]; // start new LIS of greater length
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j]; // found another LIS of same length
                }
            }
            LISlength = max(LISlength, length[i]); // track max LIS length so far
        }

        for (int i = 0; i < n; i++) {
            if (length[i] == LISlength)
                ret += count[i]; // sum up number of LIS of max length
        }

        return ret;
    }
};
