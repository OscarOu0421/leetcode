// Time Complexity:
//   - Binary Search: O(log N)
//   - Expansion in worst case (all elements equal to target): O(N)
//   - Overall: O(log N) average, O(N) worst case
//
// Space Complexity: O(1) — only constant extra space used

class Solution {
public:
    // Helper function to expand from index m to find full range of target
    vector<int> expand(vector<int>& nums, int m) {
        int start = m;
        int end = m;

        // Expand left while previous elements are equal to nums[start]
        while (start - 1 >= 0 && nums[start - 1] == nums[start])
            start--;

        // Expand right while next elements are equal to nums[end]
        while (end + 1 < nums.size() && nums[end + 1] == nums[end])
            end++;

        // Return the range [start, end]
        return {start, end};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        // Handle empty input
        if (nums.size() == 0)
            return {-1, -1};

        // Binary search to find any occurrence of target
        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) {
                // Found target, expand to get full range
                return expand(nums, m);
            }

            if (target < nums[m])
                r = m;        // Search left half
            else
                l = m + 1;    // Search right half
        }

        // Final check after loop
        if (nums[l] == target)
            return expand(nums, l);

        // Target not found
        return {-1, -1};
    }
};
