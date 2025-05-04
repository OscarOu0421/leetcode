// Time Complexity: O(n), where n is the number of triplets
// Space Complexity: O(1), constant extra space used

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = 0, y = 0, z = 0;  // Track the maximum valid values seen for each coordinate

        for (auto triplet : triplets) {
            int a = triplet[0];  // First value of the triplet
            int b = triplet[1];  // Second value
            int c = triplet[2];  // Third value
            
            // Skip if this triplet cannot contribute to any target component
            if (a > target[0] || b > target[1] || c > target[2])
                continue;

            // Only keep useful triplets: at least one component must match target's
            if (a != target[0] && b != target[1] && c != target[2])
                continue;

            // Update max values we can reach without exceeding target
            x = max(a, x);
            y = max(b, y);
            z = max(c, z);
        }

        // If we can form all three components of the target, return true
        return x == target[0] && y == target[1] && z == target[2];
    }
};

