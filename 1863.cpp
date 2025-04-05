/*
Time Complexity: O(2^n)
- For each element in the array, we have two choices: include it or exclude it from the current subset.
- So, total number of subsets = 2^n → DFS explores all of them.

Space Complexity: O(n)
- The depth of the recursion tree is n (number of elements in the input vector),
  so the maximum space used by the call stack is O(n).
*/

class Solution {
public:
    // Helper DFS function to explore all subsets and calculate XOR sum
    void dfs(vector<int> &nums, int index, int cur, int &ret) {
        int n = nums.size();  // Get the total number of elements

        // Base case: if we've considered all elements
        if (index == n) {
            ret += cur;  // Add the XOR value of this subset to the result
            return;
        }
        
        // Include the current number in the subset (XOR it)
        dfs(nums, index + 1, cur ^ nums[index], ret);
        
        // Exclude the current number from the subset
        dfs(nums, index + 1, cur, ret);
    }

    // Main function to calculate sum of XOR of all subsets
    int subsetXORSum(vector<int>& nums) {
        int ret = 0;  // Initialize result
        dfs(nums, 0, 0, ret);  // Start DFS with index 0 and XOR value 0
        return ret;  // Return the total XOR sum
    }
};

