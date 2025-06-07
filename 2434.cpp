// Time Complexity: O(n * 26) => O(26n) => O(n), where n = length of string s
//   - Each character is processed once (O(n))
//   - The `low()` function runs in O(26) per call, and can be called up to n times
// Space Complexity: O(n)
//   - Stack and output string can hold up to n characters
//   - Count array holds 26 integers (constant space)

class Solution {
public:
    // Finds the lexicographically smallest character remaining (non-zero count)
    char low(vector<int> count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return 'a' + i;
            }
        }
        return 'a'; // Default return; shouldn't be reached if count is valid
    }

    string robotWithString(string s) {
        string ret;
        stack<char> sk;                 // Stack simulating characters held by the robot
        vector<int> count(26, 0);       // Frequency of remaining characters in `s`

        // Count the frequency of each character in the string
        for (auto c : s) {
            count[c - 'a']++;
        }

        // Process each character in the input
        for (auto c : s) {
            sk.push(c);                // Robot picks up the character
            count[c - 'a']--;          // Mark character as used from the input

            // While stack top is <= the smallest remaining character, pop to result
            while (!sk.empty() && sk.top() <= low(count)) {
                ret += sk.top();       // Append top character to result
                sk.pop();              // Remove character from stack
            }
        }

        // Add remaining characters in the stack to the result
        while (!sk.empty()) {
            ret += sk.top();
            sk.pop();
        }

        return ret;
    }
};

