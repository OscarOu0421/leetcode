// Time: O(n)
// Space: O(1)
class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int ret = 0;

        for (int i = 0; i < n-1; i++) {
            ret += abs(s[i] - s[i+1]);
        }
        return ret;
    }
};
