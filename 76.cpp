// Time Complexity: O(m + n), where m = s.size(), n = t.size()
// Space Complexity: O(k), where k is the number of unique characters in t

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window; // Stores character counts in the current window
        unordered_map<char, int> freqs;  // Stores required character frequencies from t
        int offset = 0;                  // Starting index of the minimum window
        int length = INT_MAX;            // Length of the minimum window
        int formed = 0;                  // Number of characters that match the required frequency

        // Count frequency of each character in t
        for (auto c : t)
            freqs[c]++;

        // Two pointers: l for left, r for right
        for (int l = 0, r = 0; r < s.size(); r++) {
            window[s[r]]++; // Add current character to the window

            // If current character satisfies the required frequency
            if (freqs.count(s[r]) && window[s[r]] == freqs[s[r]])
                formed++;

            // Try to shrink the window from the left while it's valid
            while (l <= r && formed == freqs.size()) {
                // Update minimum window if the current one is smaller
                if (r - l + 1 < length) {
                    length = r - l + 1;
                    offset = l;
                }

                // Remove the leftmost character from the window
                window[s[l]]--;
                // If removing breaks the frequency match, reduce `formed`
                if (freqs.count(s[l]) && window[s[l]] < freqs[s[l]])
                    formed--;
                l++; // Move left pointer forward
            }
        }

        // If no valid window found, return ""
        length = length == INT_MAX ? 0 : length;
        return s.substr(offset, length); // Return the minimum window substring
    }
};
