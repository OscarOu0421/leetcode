// Time: O(n)
// Space: O(n)
class Solution {
public:
    void getNums(stack<int> &stack, int &a, int &b) {
        a = stack.top();
        stack.pop();
        b = stack.top();
        stack.pop();
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int num1, num2;

        for (auto tok : tokens) {
            if (tok == "+") {
                getNums(stack, num1, num2);
                stack.push(num2 + num1);
            } else if (tok == "-") {
                getNums(stack, num1, num2);
                stack.push(num2 - num1);
            } else if (tok == "*") {
                getNums(stack, num1, num2);
                stack.push(num2 * num1);
            } else if (tok == "/") {
                getNums(stack, num1, num2);
                stack.push(num2 / num1);
            } else {
                stack.push(stoi(tok));
            }
        }
        return stack.top();
    }
};
