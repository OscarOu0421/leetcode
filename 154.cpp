// Time Complexity: O(n) in worst case (if many duplicates exist)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        // Perform binary search while skipping duplicates
        while (l < r) {
            // Skip duplicates on the left side
            while (l + 1 < r && nums[l+1] == nums[l])
                l++;
            
            // Skip duplicates on the right side
            while (l < r - 1 && nums[r-1] == nums[r])
                r--;

            // Standard binary search logic
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r])
                r = m;  // Minimum is in the left half, including m
            else
                l = m + 1;  // Minimum is in the right half

        }

        // When l == r, we've found the minimum element
        return nums[l];
    }
};

