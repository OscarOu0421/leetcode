// Time Complexity: O(n) where n is the length of nums
// Space Complexity: O(n) for the hashmap storing prefix sums

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map; // Stores frequencies of prefix sums
        int sum = 0;  // Current prefix sum
        int ret = 0;  // Total number of subarrays summing to k

        map[0] = 1; // Base case: prefix sum 0 has occurred once (helps handle subarrays starting at index 0)

        for (auto num : nums) {
            sum += num; // Update prefix sum to include current number
            
            // Check if there exists a prefix sum that is (current_sum - k)
            // If yes, it means the subarray between that point and current index sums to k
            ret += map[sum - k];

            // Record the current prefix sum in the map
            map[sum]++;
        }

        return ret; // Return total count of valid subarrays
    }
};
