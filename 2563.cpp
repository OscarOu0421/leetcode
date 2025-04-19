// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring recursion stack and sort implementation space)
//
// The main idea is to count the number of pairs (i, j) such that 
// lower <= nums[i] + nums[j] <= upper using two-pointer technique.

class Solution {
public:
    // Helper function to count pairs with sum <= upper
    long long helper(vector<int> &nums, int upper) {
        int l = 0;
        int r = nums.size() - 1;
        long long ret = 0;

        // Two pointers approach to find valid pairs
        while (l < nums.size() && l < r) {
            // Decrease right pointer until nums[l] + nums[r] <= upper
            while (l < r && nums[l] + nums[r] > upper)
                r--;
            // Count valid pairs with current left pointer
            ret += r - l;
            l++;
        }
        return ret;
    }

    // Main function to count fair pairs with sum in [lower, upper]
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());  // Sort the array for two-pointer technique
        return helper(nums, upper) - helper(nums, lower - 1);
    }
};
