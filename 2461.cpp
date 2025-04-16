// Time Complexity: O(n), where n is the length of nums
// Space Complexity: O(k), for the sliding window hashmap of at most k distinct elements

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ret = 0;             // To store the maximum subarray sum with k distinct elements
        long long sum = 0;             // Current sliding window sum
        unordered_map<int, int> map;   // Frequency map for elements in the current window

        // Two-pointer sliding window: [l, r]
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];            // Add current element to the window sum
            map[nums[r]]++;            // Increment frequency of nums[r] in the window

            // When window size reaches k
            if (r - l + 1 == k) {
                if (map.size() == k)   // If all k elements are distinct
                    ret = max(sum, ret);  // Update maximum sum if current sum is greater

                sum -= nums[l];        // Remove element at the left of the window from the sum
                map[nums[l]]--;        // Decrease frequency of the removed element
                if (map[nums[l]] == 0) // If its frequency becomes zero, erase it from the map
                    map.erase(nums[l]);
                l++;                   // Move the left pointer to shrink the window
            }
        }
        return ret;                    // Return the maximum subarray sum with exactly k distinct elements
    }
};

