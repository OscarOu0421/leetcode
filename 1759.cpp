// Time Complexity: O(n), where n is the length of the string s
// Space Complexity: O(1)

class Solution {
public:
    int countHomogenous(string s) {
        int ret = 0;                 // Total count of homogenous substrings
        int mod = 1e9 + 7;           // Modulo for large output
        int length;                  // Length of current homogenous substring

        // Two-pointer technique: l is the start of current homogenous segment
        for (int l = 0, r = 0; r < s.size(); r++) {
            if (s[l] == s[r])        // If the current character matches the start of the segment
                length = r - l + 1;  // Increase the length of current homogenous substring
            else {
                length = 1;          // Reset length since new character found
                l = r;               // Move left pointer to current position
            }

            // Add the length to the result (number of substrings ending at r)
            ret = (ret + length) % mod;
        }

        return ret;                  // Return total homogenous substrings modulo 1e9+7
    }
};
