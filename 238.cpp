// Time Complexity: O(n)
// Space Complexity: O(1) extra space (excluding the result array)
// This version avoids using separate prefix/suffix arrays by reusing the result array.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);  // Initialize result array with 1s

        // First pass: compute prefix product and store in ret
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = prefix;     // Set current index to product of all elements before it
            prefix *= nums[i];   // Update prefix product
        }

        // Second pass: compute suffix product and multiply with existing ret values
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ret[i] *= suffix;    // Multiply with product of all elements after it
            suffix *= nums[i];   // Update suffix product
        }

        return ret;  // Return the result
    }
};
