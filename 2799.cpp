// Time Complexity: O(n)
//   - O(n) to compute the number of distinct elements
//   - O(n) for the sliding window pass
// Space Complexity: O(n) for the set and map

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set;  // To store all distinct elements in nums
        unordered_map<int, int> map;  // Frequency map for current window
        int ret = 0;
        int n = nums.size();

        // Count all distinct elements in nums
        for (auto num : nums) {
            set.insert(num);
        }
        
        // Sliding window approach
        for (int l = 0, r = 0; r < n; r++) {
            map[nums[r]]++;  // Include nums[r] in the window

            // When current window contains all distinct elements
            while (map.size() == set.size() && l <= r) {
                ret += n - r;  // All subarrays starting at l and ending from r to n-1 are valid
                map[nums[l]]--;  // Shrink the window from the left
                if (!map[nums[l]])
                    map.erase(nums[l]);  // Remove element if its count drops to 0
                l++;
            }
        }
        return ret;
    }
};
