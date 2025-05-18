// Time Complexity: O(n), where n is the length of nums
// Space Complexity: O(k), for storing frequency of remainders in the hashmap

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> map; // Stores frequency of each remainder (mod k)
        int ret = 0;  // Total count of valid subarrays
        int sum = 0;  // Cumulative prefix sum

        map[0] = 1; // Initialize with remainder 0 to handle subarrays starting from index 0

        for (auto num : nums) {
            sum += num; // Update prefix sum with current number

            // Normalize remainder to be in range [0, k-1] to avoid negative keys
            int mod = ((sum % k) + k) % k;

            // If this remainder was seen before, add its frequency to the result
            // This means there are that many subarrays ending here with sum divisible by k
            ret += map[mod];

            // Increment frequency of the current remainder
            map[mod]++;
        }

        return ret; // Return total number of subarrays with sum divisible by k
    }
};
