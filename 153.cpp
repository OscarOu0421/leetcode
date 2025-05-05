// Time Complexity: O(log N) — binary search reduces the search space by half
// Space Complexity: O(1) — constant extra space

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;                        // left boundary
        int r = nums.size() - 1;         // right boundary

        while (l < r) {
            int m = l + (r - l) / 2;     // compute mid index safely

            if (nums[m] > nums[r]) {
                // minimum is in the right half (excluding mid)
                l = m + 1;
            } else {
                // minimum is in the left half (including mid)
                r = m;
            }
        }

        // when l == r, we found the smallest element
        return nums[l];
    }
};
