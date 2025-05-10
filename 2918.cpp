// Time Complexity: O(n + m), where n = size of nums1, m = size of nums2
// Space Complexity: O(1) - constant extra space used
class Solution {
public:
    // Helper function to count number of zeros and compute the sum of elements
    void count(vector<int> nums, int &count, long long &sum) {
        for (auto num : nums) {
            if (num == 0)
                count++;       // count the number of zeros
            sum += num;        // sum all elements
        }
    }

    // Main function to compute the minimum possible equal sum
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0;
        int count2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;

        // Count zeros and sum for both arrays
        count(nums1, count1, sum1);
        count(nums2, count2, sum2);

        // Compute minimum possible sums after converting zeros to ones
        long long minSum1 = sum1 + count1;
        long long minSum2 = sum2 + count2;

        // Determine if the two arrays can be made to have equal sum
        if (count1 == 0 && count2 == 0)
            return sum1 == sum2 ? minSum1 : -1;
        else if (count1 == 0)
            return minSum1 >= minSum2 ? minSum1 : -1;
        else if (count2 == 0)
            return minSum2 >= minSum1 ? minSum2 : -1;
        else
            return max(minSum1, minSum2);  // general case
    }
};

