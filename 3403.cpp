// Time Complexity: O(N * M)
//   - N = length of word
//   - M = length of each substring = N - numFriends + 1
//   - In worst case, you check O(N) substrings of length O(N), so total O(N^2) in worst case
// Space Complexity: O(1) (excluding return string, which is O(M))

class Solution {
public:
    // Returns the lexicographically largest substring of length (n - numFriends + 1)
    string answerString(string word, int numFriends) {
        int n = word.size();
        int m = n - numFriends + 1;  // Length of substring to consider
        string ret = "";

        if (numFriends == 1)
            return word;  // If only 1 friend, whole word is the answer
        
        // Iterate through all possible substrings of length m
        for (int i = 0; i < n; i++) {
            string s = word.substr(i, m);
            ret = max(ret, s);  // Keep the maximum lexicographic substring
        }
        return ret;
    }
};

