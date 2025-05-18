// Time Complexity: O(n), where n is the length of nums
// Space Complexity: O(n), for the hashmap storing prefix sum frequencies

class Solution {
public:
    int numSubarraysWithSum(vector<int> nums, int goal) {
        unordered_map<int, int> map; // Maps prefix sum to its frequency
        int ret = 0; // Total count of valid subarrays
        int sum = 0; // Running prefix sum

        map[0] = 1; // Base case: prefix sum 0 has occurred once

        for (auto num : nums) {
            sum += num; // Update current prefix sum

            // Check if there exists a prefix sum equal to (sum - goal)
            // If yes, the subarray between that prefix and the current index sums to goal
            ret += map[sum - goal];

            // Increment frequency of the current prefix sum
            map[sum]++;
        }

        return ret; // Return total number of subarrays with sum equal to goal
    }
};

