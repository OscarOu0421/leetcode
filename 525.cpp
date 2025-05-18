/*
Time Complexity:  O(n)      // One pass through the array
Space Complexity: O(n)      // Hash map stores at most n prefix sums
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;  // Stores the earliest index of each cumulative sum
        int n = nums.size();
        int sum = 0;  // Cumulative sum where 0s are treated as -1 and 1s as +1
        int ret = 0;  // Length of the longest subarray with equal number of 0s and 1s

        map[0] = -1;  // Initialize map with sum 0 at index -1 to handle subarrays starting from index 0

        for (int i = 0; i < n; i++) {
            // Convert 0 to -1 and calculate running sum
            sum += nums[i] == 1 ? 1 : -1;

            if (map.find(sum) != map.end()) {
                // If this sum has been seen before, a subarray from previous index + 1 to i has equal 0s and 1s
                ret = max(ret, i - map[sum]);
            } else {
                // Store the first occurrence of this sum
                map[sum] = i;
            }
        }
        return ret;
    }
};

