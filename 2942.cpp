// Time Complexity: O(n * m)
//   - n = number of words
//   - m = average length of each word
// Space Complexity: O(k)
//   - k = number of words that contain the character x

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;

        // Iterate through all words
        for (int i = 0; i < words.size(); i++) {
            // Check each character in the current word
            for (auto c : words[i]) {
                if (c == x) {
                    // If the character matches, add the index to the result
                    ret.push_back(i);
                    break; // Stop checking current word after a match
                }
            }
        }
        return ret; // Return indices of words that contain character x
    }
};

