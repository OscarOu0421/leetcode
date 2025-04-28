// Time Complexity: O(n) - each element is added and removed from sum at most once
// Space Complexity: O(1) - constant extra space used
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ret = 0;   // Store the final result (number of valid subarrays)
        long long sum = 0;   // Current window sum
        int n = nums.size(); // Number of elements in the array

        // Two pointers approach: l = left end, r = right end of the window
        for (int l = 0, r = 0; r < n; r++) {
            sum += nums[r]; // Expand the window by including nums[r]

            // Shrink the window from the left if the condition is violated
            while (sum * (r - l + 1) >= k) {
                sum -= nums[l]; // Remove nums[l] from sum
                l++;            // Move left pointer to the right
            }

            ret += r - l + 1; // Add the number of valid subarrays ending at r
        }
        return ret; // Return the total count
    }
};
