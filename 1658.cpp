/*
Time Complexity:  O(n)      // Single pass through the array
Space Complexity: O(n)      // Prefix sums stored in hash map
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> map;
        int n = nums.size();
        int sum = 0, total = 0, target, ret = -1;

        // Step 1: Compute the total sum of the array
        for (auto num : nums) {
            total += num;
        }

        /*
        Problem asks: remove elements from either end to reduce x to 0.
        That is, sum of removed elements = x.
        
        So, instead of tracking removed elements,
        we find the *longest subarray to keep* such that its sum = total - x.
        Why? Because: total_sum - subarray_sum = x  ⟹  subarray_sum = total - x
        */
        target = total - x;

        // Edge case: if total == x, it means we must remove all elements
        if (target == 0) return n;

        // Initialize map with prefix sum 0 at index -1 for subarrays starting at index 0
        map[0] = -1;

        // Step 2: Use prefix sum + hashmap to find longest subarray with sum == target
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            // If a previous prefix sum exists such that:
            // current_sum - previous_sum = target, we found a valid subarray
            if (map.find(sum - target) != map.end()) {
                int length = i - map[sum - target];
                ret = max(ret, length);
            }

            // Only record the first occurrence of each prefix sum
            if (map.find(sum) == map.end()) {
                map[sum] = i;
            }
        }

        // If no valid subarray found, return -1; else, return number of operations (n - max subarray length)
        return ret == -1 ? -1 : n - ret;
    }
};
