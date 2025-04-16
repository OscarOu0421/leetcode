// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> count; // To store the frequency of elements in the current window
        long long ret = 0;             // Final count of good subarrays
        int n = nums.size();           // Size of the input array

        // Two-pointer sliding window: [l, r]
        for (int l = 0, r = 0; r < n; r++) {
            k -= count[nums[r]];      // Subtract the number of existing equal elements for nums[r]
            count[nums[r]]++;         // Include nums[r] in the frequency map

            // Shrink the window from the left until there are fewer than k equal pairs
            while (k <= 0) {
                count[nums[l]]--;     // Remove nums[l] from the frequency map
                k += count[nums[l]];  // Add back the reduced number of equal pairs for nums[l]
                l++;                  // Move the left pointer right
            }

            ret += l;  // All subarrays ending at r and starting from 0 to l-1 are good
        }

        return ret; // Return the total number of good subarrays
    }
};
