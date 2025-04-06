// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0;  // Stores the maximum triplet value found
        long long maxDiff = 0;   // Stores the max (nums[i] - nums[j]) seen so far with i < j
        int maxNum = 0;          // Stores the maximum nums[i] so far (i < j)

        for (auto num : nums) {
            // At each step, num is nums[k]
            // maxDiff corresponds to (nums[i] - nums[j]) for i < j < current index
            maxValue = max(maxValue, maxDiff * num);  // Try using current num as nums[k]

            // Update maxDiff: this simulates choosing j = current index
            // and finding the best i before it (stored in maxNum)
            maxDiff = max(maxDiff, (long long)maxNum - num);

            // Update maxNum for next iteration: best candidate for nums[i]
            maxNum = max(num, maxNum);
        }

        return maxValue;  // If no positive result found, returns 0 as per problem description
    }
};

