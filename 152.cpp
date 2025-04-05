/*
Time Complexity: O(n)
- We iterate through the array once.

Space Complexity: O(1)
- We use constant extra space.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxProd = nums[0];
        int currMax = nums[0]; // max ending here
        int currMin = nums[0]; // min ending here (for negative flip)

        for (int i = 1; i < n; ++i) {
            int num = nums[i];

            // Swap if num is negative (so currMax becomes currMin and vice versa)
            if (num < 0) {
                swap(currMax, currMin);
            }

            // Compute new max/min ending at i
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);

            // Update global max
            maxProd = max(maxProd, currMax);
        }

        return maxProd;
    }
};
