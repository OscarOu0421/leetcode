// Time Complexity: O(log n) - Binary search narrows the search space by half each time.
// Space Complexity: O(1) - Only a few pointers/variables are used.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If the mid element is less than its next neighbor,
            // then a peak must exist on the right half
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid; // A peak is on the left half or at mid
        }

        // left == right is the index of a peak element
        return left;
    }
};
