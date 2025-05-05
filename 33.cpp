// Time Complexity: O(log N) — binary search
// Space Complexity: O(1) — constant space

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;                         // left index (inclusive)
        int r = nums.size() - 1;          // right index (inclusive)

        while (l < r) {
            int m = l + (r - l) / 2;      // mid index

            if (nums[m] == target)
                return m;

            if (nums[l] <= nums[m]) {
                // left half is sorted
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;            // target is in the left half
                else
                    l = m + 1;            // target is in the right half
            } else {
                // right half is sorted
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;            // target is in the right half
                else
                    r = m - 1;            // target is in the left half
            }
        }

        // After the loop, l == r, check if target is at index l
        return nums[l] == target ? l : -1;
    }
};
