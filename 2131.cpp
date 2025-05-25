// Time Complexity: O(n), where n is the number of words
// Space Complexity: O(n), for storing unmatched words in the hash map

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ret = 0;  // Total length of the longest palindrome
        unordered_map<string, int> map;  // Tracks unmatched word frequencies

        // First pass: pair words with their reverse
        for (auto word : words) {
            string need = word;
            reverse(need.begin(), need.end());  // Get the reverse of the word

            if (map.count(need)) {
                // Found a reverse match: form a palindrome with word + need
                ret += 4;  // Each word is length 2, so 2 + 2 = 4
                map[need]--;  // Use up one occurrence of the reverse word
                if (map[need] == 0)
                    map.erase(need);  // Clean up zero-count entries
            } else {
                // No match yet, store the word for future pairing
                map[word]++;
            }
        }

        // Second pass: check if there's a symmetric word (like "aa") to place in the center
        for (auto [word, _] : map) {
            if (word[0] == word[1]) {
                ret += 2;  // One symmetric word can sit in the middle
                break;     // Only one such center piece is allowed
            }
        }

        return ret;  // Return the total length of the longest possible palindrome
    }
};

