// Time Complexity: O(n), where n is the size of nums
// Space Complexity: O(1), fixed size auxiliary vector of size 101

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        vector<int> v(101, -1); // Tracks the last index each value was seen (values in range 0-100)

        for (int r = 0, l = 0; r < n; r++) {
            // If nums[r] is already in the current window [l, r), shift window
            while (v[nums[r]] < r && v[nums[r]] >= l) {
                l += 3; // Move left pointer forward by 3 positions to simulate making a group distinct
                ret++;  // Each such move represents one operation
            }
            v[nums[r]] = r; // Update the last seen index of nums[r]

            // Ensure the right pointer doesn't fall behind the left window after shifting
            // If l > r (i.e., we skipped ahead), we reset r to l - 1, so after the next loop increment r++,
            // we resume at the correct position (r == l)
            r = max(r, l - 1);
        }
        return ret;
    }
};
