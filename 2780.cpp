// TC: O(n) - Each element is processed once in the forward and backward pass
// SC: O(n) - For the two hash maps used
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> rmap, lmap; // rmap: right side frequency map, lmap: left side frequency map

        // Populate rmap with the frequency of each element
        for (auto num : nums)
            rmap[num]++;
        
        // Traverse the array to find the valid split index
        for (int i = 0; i < n - 1; i++) {
            lmap[nums[i]]++;       // Increment left side frequency
            rmap[nums[i]]--;       // Decrement right side frequency

            // Check if the current element satisfies the condition on both sides
            if (lmap[nums[i]] * 2 > (i + 1) && rmap[nums[i]] * 2 > (n - i - 1))
                return i;          // Found the valid split index
        }
        return -1;                  // No valid index found
    }
};

