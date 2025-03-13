// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26, 0);

        for (auto c : s) {
            vec[c - 'a']++;
        }
        
        for (auto c : t) {
            vec[c - 'a']--;
        }

        for (auto i : vec) {
            if (i != 0)
                return false;
        }
        return true;
    }
};
