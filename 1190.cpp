// TC: O(n)
// SC: O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> v, pair(n);
        string ret;

        /*
         * record each '(' and ')' pair index
         */
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                v.push_back(i);
            if (s[i] == ')') {
                int j = v.back();
                v.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        /*
         * d means direction, d=1 means right, d=0 meas left
         * when you meet '(' form right, then you should jump to ')' and turn left
         * -> ( .... )  =>  ( .... <- )
         * same method, like
         * ( .... ) <-  =>. ( -> .... ) 
         * ( <- .... )  =>  ( .... ) ->
         * ( .... -> ). =>  <- ( .... )
         */
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else
                ret += s[i];
        }

        return ret;
    }
};
