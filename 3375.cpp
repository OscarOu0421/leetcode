// Time Complexity: O(n), where n is the size of the nums array
// Space Complexity: O(n), for storing unique elements in the unordered_set

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> set;            // Stores unique elements in nums
        int minValue = INT_MAX;            // Tracks the minimum value in nums
        int ret = 0;                       // Stores the final result (number of operations)

        for (auto num : nums) {
            if (num < k)                   // If any number is less than k, it's impossible
                return -1;
            set.insert(num);              // Insert current number into the set
            minValue = min(num, minValue); // Update minimum value
        }

        ret = set.size() - 1;              // We need one operation per unique value > k
        if (minValue > k)                  // If k is not yet reached, we need one extra step
            ret++;
        return ret;                        // Return the total number of operations
    }   
};

