// Time Complexity: O(n), where n is the length of the string `s`
// Space Complexity: O(1), since the alphabet size is fixed (26 uppercase letters)
//
// Sliding window approach to find the longest substring where we can replace at most `k` characters
// to make all characters in the window the same.
//
// NOTE:
// - `maxfreq` keeps track of the maximum frequency of any character seen so far in the window.
// - It may become stale as we move the left pointer (`l`), but we never decrease it for performance.
// - This is okay because the check `(r - l + 1) - maxfreq > k` becomes slightly conservative (shrinks the window a bit early),
//   but never allows invalid windows.
// - This ensures correctness while maintaining O(n) time complexity.

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;  // Frequency map of characters in the current window
        int ret = 0;
        int maxfreq = 0;  // Max frequency of a single character in the current window

        // Sliding window: [l, r]
        for (int l = 0, r = 0; r < s.size(); r++) {
            freq[s[r]]++;  // Add current character to window
            maxfreq = max(maxfreq, freq[s[r]]);  // Update max frequency in window

            // Shrink the window if more than `k` characters need to be replaced
            while ((r - l + 1) - maxfreq > k) {
                freq[s[l]]--;  // Remove character at left
                l++;  // Move left pointer
            }

            // Update result with the maximum valid window size
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};
