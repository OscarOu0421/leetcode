/*
    Problem: Search Insert Position (LeetCode)
    Approach: Binary Search to find the index of the target or where it should be inserted.

    Time Complexity: O(log n), where n is the size of the input array
    Space Complexity: O(1), constant extra space
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        // Binary search loop: search space is [l, r]
        while (l < r) {
            // Compute middle index safely to avoid overflow
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return m;  // Target found
            else if (nums[m] < target)
                l = m + 1; // Move right if target is larger
            else
                r = m;     // Move left if target is smaller
        }

        // After the loop, l == r (potential insert position)
        // Check if target is greater than the last element
        if (l == n - 1 && target > nums[l])
            l++; // Insert after the last element

        return l; // Return the index to insert target
    }
};

