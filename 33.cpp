// Time Complexity: O(log N) — binary search over rotated sorted array
// Space Complexity: O(1) — constant extra space

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;                            // left boundary of search range
        int r = nums.size() - 1;              // right boundary of search range
        
        while (l <= r) {                      // binary search loop
            int m = l + (r - l) / 2;          // calculate middle index (avoids overflow)

            if (nums[m] == target)            // found target
                return m;
            
            if (nums[l] <= nums[m]) {         // left half is sorted
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;                // target is in the left sorted half
                else
                    l = m + 1;                // target is in the right half
            } else {                          // right half is sorted
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;                // target is in the right sorted half
                else
                    r = m - 1;                // target is in the left half
            }
        }

        return -1;                            // target not found
    }
};
