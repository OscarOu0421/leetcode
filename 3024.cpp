// Time Complexity: O(1) - Sorting a fixed-size vector of 3 elements takes constant time.
// Space Complexity: O(1) - Uses a constant amount of extra space.

class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_set<int> set; // To determine the number of unique side lengths
        sort(nums.begin(), nums.end()); // Sort the sides to simplify triangle inequality check

        for (auto num : nums)
            set.insert(num); // Insert each side into the set to track distinct values

        // Check for triangle validity using triangle inequality
        if (nums[0] + nums[1] <= nums[2])
            return "none"; // Not a valid triangle
        else if (set.size() == 1)
            return "equilateral"; // All sides are equal
        else if (set.size() == 2)
            return "isosceles"; // Two sides are equal
        else
            return "scalene"; // All sides are different
    }
};

