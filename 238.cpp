// Time Complexity: O(n) - Single pass through the array using two pointers.
// Space Complexity: O(1) - Constant extra space used (output vector usually doesn't count).

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();        // Get the length of the input array
        int prev = 1;               // Accumulator for the product of elements to the left
        int post = 1;               // Accumulator for the product of elements to the right
        vector<int> v(n, 1);        // Initialize the result vector with 1s

        // Single loop: 'l' moves from start to end, 'r' moves from end to start
        for (int l = 0, r = n-1; l < n; l++, r--) {
            // Multiply the current index from the left by the product of all previous elements
            v[l] *= prev;
            
            // Multiply the current index from the right by the product of all following elements
            v[r] *= post;
            
            // Update the prefix product for the next element on the left
            prev *= nums[l];
            
            // Update the suffix product for the next element on the right
            post *= nums[r];
        }
        
        // Return the completed product array
        return v;
    }
};
