// TC: O(n)
// SC: O(n)
class Solution {
public:
    int balancedString(string s) {
        int l = 0, r = 0, n = s.size(), k = n >> 2, ret = n;
        unordered_map<int, int> map;

        /* Count the letter frequency outside the window */
        for (auto c : s)
            map[c]++;

        for (; r < n; r++) {
            /* 
             * add s[r] into the window 
             * we erase all letter inside the window
             */
            map[s[r]]--;
            
            /*
             * we find the smallest window that still make string balanced.
             * we can make the whole string balanced as long as
             * max(map['Q'], map['W'], map['E'], map['R']) <= k
             * because we can replace the letter inside the window to complement 
             * the string to balanced.
             * 
             * why need l < n, not l <= r ?
             * For example: s = "QWER", the result should be 0
             * if use l <= r, no matter r is, the result would be 1.
             * if use l <= r + 1, then we could get the correct result 0.
             * but if r at n - 1, l may reach n that occur overflow problem.
             * so we use l < n.
             */
            while (l < n && 
                map['Q'] <= k && 
                map['W'] <= k && 
                map['E'] <= k &&
                map['R'] <= k) {
                ret = min(ret, r - l + 1);
                map[s[l++]]++;
            }
        }
        return ret;
    }
};
