/*
    Problem: Range Sum Query - Immutable (LeetCode)
    Approach: Prefix Sum Array

    Time Complexity:
        - Constructor: O(n), to build prefix sum array
        - sumRange: O(1), constant time range sum query

    Space Complexity:
        - O(n), to store the prefix sum array
*/

class NumArray {
public:
    vector<int> prefixsum;

    // Constructor: builds prefix sum array
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixsum = nums;

        // prefixsum[i] holds the sum of nums[0] to nums[i]
        for (int i = 1; i < n; i++) {
            prefixsum[i] += prefixsum[i - 1];
        }
    }

    // Returns the sum of elements nums[left] to nums[right]
    int sumRange(int left, int right) {
        int rsum = prefixsum[right];  // sum from 0 to right
        int lsum = left > 0 ? prefixsum[left - 1] : 0;  // sum from 0 to left - 1
        return rsum - lsum;  // result is sum from left to right
    }
};

