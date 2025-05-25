// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(n), for the stack used during parsing

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;    // Stack to hold previous results and signs
        int result = 0;    // Ongoing result
        int number = 0;    // Current number being built from digits
        int sign = 1;      // Current sign (+1 or -1)

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build number digit by digit
                number = number * 10 + (ch - '0');
            } else if (ch == '+' || ch == '-') {
                // Add previous number with its sign to result
                result += sign * number;
                number = 0;  // Reset number

                // Update sign based on operator
                sign = (ch == '+') ? 1 : -1;
            } else if (ch == '(') {
                // Push current result and sign onto the stack
                stk.push(result);
                stk.push(sign);

                // Reset result and sign for the new subexpression
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                // Add last number before ')'
                result += sign * number;
                number = 0;

                // Retrieve the sign and previous result from the stack
                result *= stk.top(); stk.pop();  // This is the sign before '('
                result += stk.top(); stk.pop();  // This is the result before '('
            }
            // Ignore spaces
        }

        // Add any remaining number
        if (number != 0) {
            result += sign * number;
        }

        return result;
    }
};

