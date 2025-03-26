// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(1) - No extra space used
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = n - 1; // Start by assuming the last index must be reachable

        // Traverse the array from right to left
        for (int i = n - 2; i >= 0; i--) {
            // If the current index can reach the 'reach' point, update 'reach'
            if (i + nums[i] >= reach)
                reach = i; // Move the target closer to the start
        }
        
        // If the leftmost index becomes the target, the start is reachable
        return reach == 0;
    }
};
