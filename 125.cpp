// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool isAlpha(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        else if (c >= 'a' && c <= 'z')
            return true;
        else if (c >= '0' && c <= '9')
            return true;
        return false;
    }
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        return c;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l <= r) {
            if (!isAlpha(s[l])) {
                l++;
                continue;
            }
            if (!isAlpha(s[r])) {
                r--;
                continue;
            }
            if (toLower(s[l]) != toLower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
