// TC: O(n)
// SC: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.size(), ret = 0;
        vector<int> count(3, 0);

        for (; r < n; r++) {
            count[s[r] - 'a']++;
            /*
             * if the substring s[l:r] contains the letter a, b, c
             * we can advance the index l until lack some letter,
             */
            while (count[0] && count [1] && count[2])
                count[s[l++] - 'a']--;
            /*
             * For example: s= "abcabc"
             * at r = 2, l will be at 1, and add substring "abc"
             * at r = 3, l will be at 2, and add substring "abca" and "bca"
             * at r = 4, l will be at 3, and add substring "abcab", "bcab" and "cab"
             * at r = 5, l will be at 4, and add substring "abcabc", "bcabc", "cabc" and "abc"
             */
            ret += l;
        }
        return ret;
    }
};
