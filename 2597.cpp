// Time Complexity: O(2^n), where n is the number of elements in `nums`. 
//   Each element can be either included or excluded, and we may recurse on each subset.
// Space Complexity: O(n) for recursion depth and frequency map.

class Solution {
public:
    // Recursive helper to explore all subsets starting from index `start`
    void helper(vector<int>& nums, int k, int start, int &ret, unordered_map<int, int> &freq) {
        ret++;  // Count current subset as valid

        for (int i = start; i < nums.size(); i++) {
            // Skip if adding nums[i] would violate the beautiful condition
            if (freq[nums[i] - k] != 0 || freq[nums[i] + k] != 0)
                continue;

            freq[nums[i]]++;                       // Choose nums[i]
            helper(nums, k, i + 1, ret, freq);     // Recurse with next index
            freq[nums[i]]--;                       // Backtrack
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int ret = 0;                         // Count of all valid beautiful subsets
        int n = nums.size();                 // Number of elements in input
        unordered_map<int, int> freq;        // Frequency map to track current subset elements

        helper(nums, k, 0, ret, freq);       // Start recursive exploration
        return ret - 1;                      // Subtract empty set which was counted
    }
};
