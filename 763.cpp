// Time Complexity: O(N) - We iterate through the string twice (one for storing last occurrences, one for partitioning).
// Space Complexity: O(1) - The unordered_map stores at most 26 characters, which is constant space.

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence; // Stores the last index of each character
        vector<int> ret; // Stores the partition sizes
        
        int n = s.size();
        
        // Step 1: Populate lastOccurrence map
        for (int i = 0; i < n; i++) {
            lastOccurrence[s[i]] = i;
        }

        // Step 2: Determine partitions
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, lastOccurrence[s[i]]); // Extend the partition boundary
            if (r == i) { // When reaching a boundary, finalize the partition
                ret.push_back(r - l + 1);
                l = i + 1; // Move to the next partition
            }
        }
        return ret;
    }
};
