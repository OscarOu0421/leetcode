// TC:O(n)
// SC:O(1)
class Solution {
public:
    bool isValid(string s) {
        stack<int> sk;
        int n = s.length();
        int top;
        
        for (int i = 0; i < n; i++) {
            if (!sk.empty() && 
                ((s[i] == ')' && sk.top() == '(') ||
                (s[i] == ']' && sk.top() == '[') ||
                (s[i] == '}' && sk.top() == '{')))
                sk.pop();
            else
                sk.push(s[i]);
        }
        return sk.empty();
    }
};
