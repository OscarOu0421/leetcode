// Time Complexity: O(log n) 
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int l = 0;  // Left pointer
        int r = n - 1;  // Right pointer

        // If the array is not rotated (i.e., nums[l] < nums[r]), return the first element
        if (nums[l] < nums[r])
            return nums[l];

        // Perform binary search
        while (l < r) {
            int m = l + (r - l) / 2;  // Calculate the middle index to avoid overflow

            // If nums[m] <= nums[r], the minimum is in the left half (including m)
            if (nums[m] <= nums[r])
                r = m;
            else
                l = m + 1;  // If nums[m] > nums[r], the minimum is in the right half

        }

        // When l == r, we have found the minimum element
        return nums[l];
    }
};

