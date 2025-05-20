// Time Complexity: O(n) where n is the length of the input string `s`
// Space Complexity: O(n) for storing words in the stack and result string

class Solution {
public:
    string reverseWords(string s) {
        stack<string> sk;
        string word = "";
        string ret = "";

        // Split the input string by spaces and push words onto the stack
        for (auto c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    sk.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        // Push the last word if present
        if (!word.empty())
            sk.push(word);

        // Pop words from the stack to reverse their order
        while (!sk.empty()) {
            ret += sk.top();
            sk.pop();
            if (!sk.empty())
                ret += ' ';
        }

        return ret;
    }
};

