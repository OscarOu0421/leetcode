// Time Complexity: O(n)
//   - n = size of nums
//   - Single pass through nums with constant-time hash map operations
// Space Complexity: O(modulo)
//   - At most `modulo` distinct prefix remainders are stored in the map
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int sum = 0;                // Count of elements where num % modulo == k
        long long ret = 0;          // Result: number of interesting subarrays
        unordered_map<int, int> map;

        map[0] = 1; // Base case: prefix remainder 0 occurs once

        for (auto num : nums) {
            // Increment sum if current number meets the condition
            if (num % modulo == k)
                sum++;

            int remain = sum % modulo;                       // Current prefix remainder
            int need = (remain - k + modulo) % modulo;       // Required prefix remainder to form a valid subarray

            ret += map[need];    // Count how many prefixes match the required remainder
            map[remain]++;       // Record current prefix remainder
        }

        return ret;
    }
};
