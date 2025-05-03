// Time Complexity: O(n)
// Space Complexity: O(1)
// n = size of the domino arrays

class Solution {
public:
    // Helper function to check how many rotations are needed to make all elements equal to x
    int helper(int x, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();           // Get the number of dominoes
        int top_rotate = 0;            // Count of rotations needed in tops
        int bot_rotate = 0;            // Count of rotations needed in bottoms

        for (int i = 0; i < n; i++) {
            // If neither side has x, it's impossible to align
            if (tops[i] != x && bottoms[i] != x)
                return -1;
            // If top needs to be rotated to x
            else if (tops[i] != x)
                top_rotate++;
            // If bottom needs to be rotated to x
            else if (bottoms[i] != x)
                bot_rotate++;
        }

        // Return the minimum rotations needed
        return min(top_rotate, bot_rotate);
    }

    // Main function to find the minimum domino rotations for equal row
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Try to make all values equal to tops[0]
        int top = helper(tops[0], tops, bottoms);
        // Try to make all values equal to bottoms[0]
        int bottom = helper(bottoms[0], tops, bottoms);
        
        // If neither works, return -1
        if (top == -1 && bottom == -1)
            return -1;
        // If both are possible, return the minimum
        else if (top != -1 && bottom != -1)
            return min(top, bottom);
        // Return the one that is possible
        else
            return max(top, bottom);
    }
};
