// Time: O(n)
// Space: O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> letters(52, 0);
        int ret = 0, single = 0;

        // Record each letter appearment
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                letters[c - 'a']++;
            else
                letters[c - 'A' + 26]++;
        }

        for (auto letter : letters) {
            // Add the result by every 2 appearment.
            while (letter >= 2) {
                ret += 2;
                letter -= 2;
            }
            // Only mid of the palindrome can be 1 appearment.
            if (letter && single == 0)
                single++;
        }
        return ret + single;
    }
};
