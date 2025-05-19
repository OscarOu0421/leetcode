// Problem Summary:
// Find the maximum number of indices you can mark in pairs (i, j) such that:
// nums[i] * 2 <= nums[j] and both i and j are marked (each element used at most once).
// Return the total number of marked indices.

// Strategy:
// - Sort the array.
// - Try to greedily pair the smallest numbers with large enough numbers from the other half.
// - Use two pointers (l, r) to find such valid pairs.
// - Each valid pair contributes 2 marked indices.

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) extra space

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        // Start 'r' from the beginning of the right half of the sorted array.
        // We use 'n - n/2' to ensure there's enough space in the right half for pairing,
        // especially when n is odd. This keeps the left and right halves balanced.
        int r = n - n / 2;

        sort(nums.begin(), nums.end()); // Sort to apply greedy matching

        // Try to form as many valid pairs as possible
        for (; r < n; r++) {
            // If nums[l] * 2 <= nums[r], a valid pair is formed
            if (nums[l] * 2 <= nums[r])
                l++; // Move to the next small number to pair
        }

        // Each valid pair marks two indices (l from left half, r from right half),
        // so total marked indices = number of pairs * 2
        return l * 2;
    }
};

