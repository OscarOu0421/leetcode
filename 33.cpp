// TC: O(logn)
// SC: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Check which half is sorted
            if (nums[left] <= nums[mid]) {  // Left side sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Search in the sorted left part
                } else {
                    left = mid + 1;   // Search in the right part
                }
            } else {  // Right side sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Search in the sorted right part
                } else {
                    right = mid - 1;  // Search in the left part
                }
            }
        }

        return -1;  // Target not found
    }
};
