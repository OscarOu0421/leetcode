// Time Complexity: O(n), where n is the number of dominoes
// Space Complexity: O(1), since the counts array size is fixed (100 elements)

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> counts(100, 0);  // Frequency array for normalized domino values
        int ret = 0;                 // Result to store total number of equivalent pairs

        for (auto domino : dominoes) {
            // Normalize the domino: sort the two values to ensure order doesn't matter
            int a = domino[0] > domino[1] ? domino[0] : domino[1];
            int b = domino[0] > domino[1] ? domino[1] : domino[0];
            int key = a * 10 + b;    // Encode the pair as a unique integer (e.g., [1,2] → 12)

            ret += counts[key];      // For each previous identical domino, one new pair is formed
            counts[key]++;           // Increment the count for this domino type
        }

        return ret;  // Return the total number of equivalent domino pairs
    }
};

