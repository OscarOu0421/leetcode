// Time Complexity: O(n)
// Space Complexity: O(1)
// This function counts the number of subarrays where the maximum element appears exactly k times.

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();              // Get the size of the input array
        long long ret = 0;                // Initialize the result counter
        int maxValue = nums[0];           // Initialize maxValue with the first element

        // Find the maximum value in the array
        for (auto num : nums)
            maxValue = max(maxValue, num);

        // Use sliding window technique
        for (int l = 0, r = 0, count = 0; r < n; r++) {
            if (nums[r] == maxValue)      // Increment count if current element is maxValue
                count++;
            
            // When we have exactly k maxValue in the window
            while (count == k) {
                ret += n - r;             // All subarrays starting from l to n-1 are valid
                if (nums[l] == maxValue)  // Shrink the window from the left
                    count--;
                l++;
            }
        }
        return ret;                       // Return the total count
    }
};
